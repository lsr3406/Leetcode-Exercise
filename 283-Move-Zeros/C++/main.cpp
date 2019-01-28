/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-28 20:07:27
 * @update on: 2019-01-28 21:08:57
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    /**
     * 简单的移零问题
     * @param 待移零 vector
     */
    void moveZeroes(vector<int>& nums) {

        moveZeroes3(nums);
    }

    /**
     * 方案一: 创建一个新的 vector, 将 nums 中的非零元素依次放入新的 vector 中, 再拷贝回原 nums 并充零. 本方案不能达到题目中原地操作的要求.
     * @param nums 待移零处理的 vector, 引用传参
     * 时间复杂度 O(n)
     * 空间复杂度 O(n)
     */
    void moveZeroes1(vector<int>& nums) {

        vector<int> aux;
        
        // 拷贝非零元素至 aux
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] != 0)
                aux.push_back(nums[i]);

        // 向 nums 中放回非零元素
        for (int i = 0; i < aux.size(); i ++)
            nums[i] = aux[i];

        // 在 nums 剩余位置充零
        for (int i = aux.size(); i < nums.size(); i ++)
            nums[i] = 0;
    }

    /**
     * 方案二: 在方案一的基础上改为原地操作, 遍历 nums, 检测到非零元素, 在前面相应位置设置相等的元素, 最后在剩余位置充零.
     * @param nums 待移零处理的 vector, 引用传参
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    void moveZeroes2(vector<int>& nums) {

        // 遍历 nums, 非零元素拷贝至 nums 的前面
        int nonZerosCount = 0;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] != 0) {
                nums[nonZerosCount] = nums[i];
                nonZerosCount ++;
            }

        // 在 nums 剩余位置充零
        for (int i = nonZerosCount; i < nums.size(); i ++)
            nums[i] = 0;
    }

    /**
     * 方案三: 遍历 nums, 检测到非零元素后, 直接将其与应当放置的位置的元素作交换, 省去最后的充零步骤.
     * @param nums 待移零处理的 vector, 引用传参
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    void moveZeroes3(vector<int>& nums) {

        int nonZerosCount = 0;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] != 0){
                swap(nums[i], nums[nonZerosCount]);
                nonZerosCount ++;
            }
    }

    /**
     * 其他优化方案:
     * 1. 在方案三的基础上, 考虑 swap 是否还有其他条件, 如 i == nonZerosCount 时无需交换
     */
};

int main(int argc, char const *argv[]){
    
    int arr[] = {0, 1, 0, 3, 12};
    // int desired[] = {1, 3, 12, 0, 0};

    vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    // 实例化一个 Solution 对象并调用 moveZeros 方法, num 为引用传参
    Solution solution = Solution();
    solution.moveZeroes(nums);

    // 打印输出结果
    for (int i = 0; i < nums.size(); i ++)
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}