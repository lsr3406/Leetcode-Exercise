/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-29 21:16:01
 * @update on: 2019-01-29 22:55:25
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:

    /**
     * 在一个 vector 中找到第 k 大的元素
     * @param  nums 待搜索的 vector
     * @param  k    rank
     * @return      找到的第 k 大的元素
     */
    int findKthLargest(vector<int>& nums, int k) {
    
        // return findKthLargest1(nums, k);    
        return findKthLargest2(nums, k);    
    }

    /**
     * 方案一: 使用选择排序的思路, 相当于暴力破解, 依次找到最大的元素并放到末端
     * 时间复杂度: O(nk)
     * 空间复杂度: O(1)
     */ 
    int findKthLargest1(vector<int>& nums, int k) {

        assert(k >= 1 && k <= nums.size());
        int n = nums.size();

        // 大循环, 每次找出第 i 大的元素
        for (int i = 1; i <= k; i ++) {
            
            int curMaxIndex = 0;
            for (int j = 0; j <= n - i; j ++)
                if (nums[j] > nums[curMaxIndex])
                    curMaxIndex = j;
            swap(nums[curMaxIndex], nums[n - i]);
        }
        return nums[n - k];
    }

    /**
     * 方案二: 使用快速排序的思路, 不断向第 k 大的方向作 partition 操作.
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int findKthLargest2(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0, r = n - 1;
        while (true) {
            // 接收标定点位置
            int br = partition(nums, l, r);
            if (br + k > n) {
                r = br - 1;
            }
            else if (br + k < n) {
                l = br + 1;
            }
            else { // 找到了第 k 大的元素
                return nums[br];
            }
        }
    }

    /**
     * 方案三: 使用容量为 k 的优先队列(最小堆), 依次将 nums 中的元素放入, 最后取出堆顶元素
     * 时间复杂度: O(nlogk)
     * 空间复杂度: O(1)
     */
    int findKthLargest3(vector<int>& nums, int k) {

        // TODO 优先队列法
        return 0;
    }

private:
    /**
     * 在 nums 中 [l, r] 区间中对元素 nums[l] 作 partition 操作, 返回标定点最后移到的位置
     */
    int partition(vector<int>& nums, int l, int r) {

        assert(l <= r);

        int j = l;  // nums[l+1, ..., j] < v, nums[j+1, ..., i-1] > v
        for (int i = l + 1; i <= r; i ++) {
            if (nums[i] < nums[l]) {
                j ++;
                swap(nums[j], nums[i]);
            }
            else {  // nums[i] >= nums[l]
                // do nothing
            }
        }

        swap(nums[l], nums[j]);
        return j;
    }
};

int main(int argc, char const *argv[]) {
    
    int arr1[] = {3, 2, 1, 5, 6, 4}, k1 = 2;
    int arr2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k2 = 4;
    vector<int> nums1(arr1, end(arr1));
    vector<int> nums2(arr2, end(arr2));

    int res1 = Solution().findKthLargest(nums1, k1);
    int res2 = Solution().findKthLargest(nums2, k2);

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}
