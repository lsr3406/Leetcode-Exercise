/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-29 18:14:45
 * @update on: 2019-01-29 19:25:42
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

class Solution {
public:

    /**
     * 颜色排序, 题目
     * @param nums 待排序 vector
     */
    void sortColors(vector<int>& nums) {
        
        // sortColors1(nums);
        sortColors2(nums);
    }

    /**
     * 方案1: 针对有大量重复元素的序列, 使用计数排序.
     * @param nums 待排序 vector
     */
    void sortColors1(vector<int>& nums) {

        // 计数
        int colorsCount[] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i ++) {
            assert(nums[i] >= 0 && nums[i] <= 2);
            colorsCount[nums[i]] ++;
        }

        // index 是向 nums 中回代的索引
        int index = 0;
        for (int i = 0; i < end(colorsCount) - colorsCount; i ++) {
            while (colorsCount[i] > 0) {
                nums[index] = i;
                index ++;
                colorsCount[i] --;
            }
        }
    }

    /**
     * 方案二: 针对有大量重复元素的序列, 使用三路快速排序的思路, 并以 1 为标定点
     * @param nums 待排序 vector
     */
    void sortColors2(vector<int>& nums) {

        // 定义三路快速排序的索引, v == 1
        int lt = -1;  // [0, lt] < v
        int gt = nums.size();  // [gt, nums.size()-1] > v
        int i = 0;  // 最前部指针, [lt+1, i-1] == v

        while (i < gt) {

            // 下列逻辑中可删除断言语句, 合并自增自减语句后再提交问题
            if (nums[i] == 0) {
                lt ++;
                swap(nums[i], nums[lt]);
                i ++;
            }
            else if (nums[i] == 1) {
                i ++;
            }
            else {
                assert(nums[i] == 2);
                gt --;
                swap(nums[i], nums[gt]);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    
    // 测试用例
    int arr[] = {2, 0, 2, 1, 1, 0};
    vector<int> nums(arr, end(arr));

    Solution solution = Solution();
    solution.sortColors(nums);

    for (int i = 0; i < nums.size(); i ++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}

