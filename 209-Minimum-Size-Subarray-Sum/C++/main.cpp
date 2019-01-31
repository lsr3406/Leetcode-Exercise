/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-31 11:20:46
 * @update on: 2019-01-31 19:20:11
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    /**
     * 找到一个长度最小的区间, 使得区间内元素的和大于等于指定的数
     * @param  s    目标和
     * @param  nums 待检索数组
     * @return      最优区间长度
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        
        // return minSubArrayLen1(s, nums);
        // return minSubArrayLen2(s, nums);
        return minSubArrayLen3(s, nums);
    }

    /**
     * 方案一: 二重遍历, 择机跳出循环. 程序中的 minInterval 是最小区间 - 1
     * 时间复杂度: O(n^2)
     * 空间复杂度: O(1)
     */
    int minSubArrayLen1(int s, vector<int>& nums) {

        int minInterval = nums.size();

        // 第一重循环, 作为区间 [l, r] 左侧
        for (int i = 0; i < nums.size(); i ++) {

            // 第二重循环, 作为区间 [l, r] 右侧
            int tempSum = 0;
            for (int j = i; j < nums.size(); j ++) {

                tempSum += nums[j];
                // 跳出第二重循环的条件
                if (j - i >= minInterval)
                    break;

                if (tempSum >= s) {
                    minInterval = j - i;
                }
            }
        }
        return minInterval == nums.size() ? 0 : minInterval + 1;
    }

    /**
     * 方案二: 求累加和, 遍历累加和并使用二分查找
     * 时间复杂度: O(nlogn)
     * 空间复杂度: O(n)
     */
    int minSubArrayLen2(int s, vector<int>& nums) {

        int minInterval = nums.size() + 1;
        
        // 获取累加数组, 累加数组本身是有序的
        vector<int> sums = cumSumWithZero(nums); 
        
        for (int i = 0; i < sums.size(); i ++) {
            // 找满足要求的区间, 获取区间右侧端点
            auto bound = lower_bound(sums.begin() + i, sums.end(), s + sums[i]);
            if (bound == sums.end())
                break;

            // 选择性更新最优解
            int currentInterval = bound - sums.begin() - i;
            if (currentInterval < minInterval)
                minInterval = currentInterval;
        }

        return minInterval == nums.size() + 1 ? 0 : minInterval;
    }

    /**
     * 方案三: 滑动窗口法, 程序中的 minInterval 是最小区间 - 1
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int minSubArrayLen3(int s, vector<int>& nums) {

        int minInterval = nums.size();
        int sum = 0;

        int l = 0;  // 区间左侧
        for (int r = 0; r < nums.size(); r ++) {
            
            sum += nums[r];

            // 尽可能从左侧缩小区间, 直到和不满足要求
            while (sum >= s){
                minInterval = min(r - l, minInterval);
                sum -= nums[l];
                l ++;
            }
        }
        return minInterval == nums.size() ? 0 : minInterval + 1;
    }

private:
    /**
     * 累加
     */
    vector<int> cumSumWithZero(vector<int>& nums) {
        
        // 开辟空间, 设置首项
        vector<int> res(nums.size() + 1);
        res[0] = 0;

        // 遍历计算
        for (int i = 1; i < nums.size() + 1; i ++) {
            res[i] = res[i - 1] + nums[i - 1];
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    int arr[] = {2, 3, 1, 2, 4, 3};
    int s = 7;
    vector<int> nums(arr, end(arr));

    int res = Solution().minSubArrayLen(s, nums);

    cout << res << endl;

    return 0;
}
