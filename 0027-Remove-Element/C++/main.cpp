/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-28 20:07:40
 * @update on: 2019-01-28 21:49:11
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 27. Remove Element
// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        return removeElement1(nums, val);
    }

    /**
     * 遍历, 检测到目标值时与 nums 中最后一个元素交换, 然后从 vector 的末尾删除一个元素
     * @param  nums 待检索 vector, 引用传参
     * @param  val  要从 nums 中去掉的值
     * @return      剩余元素的数量
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int removeElement1(vector<int>& nums, int val) {

        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == val) {
                swap(nums[i], nums.back());
                nums.pop_back();
            }
            else {
                i ++;
            }
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[]){

    // 示例
    int arr1[] = {3, 2, 2, 3}, val1 = 3;
    int arr2[] = {0, 1, 2, 2, 3, 0, 4, 2}, val2 = 2;
    vector<int> nums1(arr1, end(arr1));
    vector<int> nums2(arr2, end(arr2));

    Solution solution = Solution();
    int res1 = solution.removeElement(nums1, val1);
    int res2 = solution.removeElement(nums2, val2);
    
    // 打印输出结果
    for (int i = 0; i < nums1.size(); i ++)
        cout << nums1[i] << " ";
    cout << endl;
    cout << "res1: " << res1 << endl;
    for (int i = 0; i < nums2.size(); i ++)
        cout << nums2[i] << " ";
    cout << endl;
    cout << "res2: " << res2 << endl;

    return 0;
}