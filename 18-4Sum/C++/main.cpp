/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-09 21:04:44
 * @update on: 2019-02-09 22:43:26
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// 18. 4sum
// https://leetcode.com/problems/4sum

class Solution {
public:
    /**
     * 将 4 数之和问题看做两个 2 数之和问题
     * 题目要求索引不能重复使用
     */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        // 二重遍历一次, 设置哈希表记录两数之和可能的情况及相应索引
        unordered_map<int, vector<pair<int, int>>> complement;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                complement[target - nums[i] - nums[j]].push_back({i, j});
            }
        }

        // 二重遍历一次, 对每种情况在原哈希表中做查找
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int temp = nums[i] + nums[j];
                if (complement.find(temp) != complement.end()) {
                    for (auto p: complement[temp]) {
                        if (p.first == i || p.second == i || p.first == j || p.second == j)
                            continue;
                        res.push_back({nums[i], nums[j], nums[p.first], nums[p.second]});
                    }
                }
            }
        }

        // 排序, 去重
        for (int i = 0; i < res.size(); i ++)
            sort(res[i].begin(), res[i].end());
        sort(res.begin(), res.end());

        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> nums({1, 0, -1, 0, -2, 2});

    vector<vector<int>> res = Solution().fourSum(nums, 0);

    for (vector<int> vec: res) {
        for(int e: vec) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
