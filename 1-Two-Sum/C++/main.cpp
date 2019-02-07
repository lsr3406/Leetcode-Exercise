/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-07 19:54:52
 * @update on: 2019-02-07 21:04:57
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

// 1. Two Sum
// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // return twoSum1(nums, target);
        return twoSum2(nums, target);
    }

    /**
     * 方案一: 使用哈希表实现的集合存放原始元素, 之后依次查询互补量. 假设每个元素只有一个
     * 时间复杂度: O(n)
     * 空间复杂度: O(n)
     */
    vector<int> twoSum1(vector<int>& nums, int target) {
        
        // 创建哈希表
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++)
            map[nums[i]] = i;

        // 查找
        for (int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if (iter != map.end() && iter->second != i){
                int res[2] = {i, iter->second};
                return vector<int>(res, res + 2);
            }
        }
        throw invalid_argument("The Input Has No Solution");
    }

    /**
     * 方案二: 使用哈希表实现的集合依次存放原始元素, 存放之前查询互补量, 找不到再添加. 假设每个元素只有一个
     * 时间复杂度: O(n)
     * 空间复杂度: O(n)
     */
    vector<int> twoSum2(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++) {

            unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if (iter != map.end() && iter->second != i){
                int res[2] = {iter->second, i};
                return vector<int>(res, res + 2);
            }

            map[nums[i]] = i;
        }
        throw invalid_argument("The Input Has No Solution");
    }
};

int main(int argc, char const *argv[]) {

    int arr1[] = {2, 7, 11, 15};

    vector<int> nums = vector<int>(arr, end(arr));

    vector<int> res = Solution().twoSum(nums, 9);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << ", ";
    cout << endl;

    return 0;
}
