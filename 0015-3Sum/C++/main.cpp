/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-07 22:58:13
 * @update on: 2019-02-07 23:14:56
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 15. 3Sum
// https://leetcode.com/problems/3sum

class Solution {
public:

    /**
     * 方案一: 建立计数器, 统计每种数字的个数; 将原数组排序并去重; 做二重遍历并分类讨论
     */
    vector<vector<int>> threeSum(vector<int>& nums) {

        // 统计每种数字的个数
        unordered_map<int, int> counter;
        for (int i = 0; i < nums.size(); i ++)
            counter[nums[i]] ++;

        // 去重
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        vector<vector<int>> res;

        if (counter[0] >= 3)
            res.push_back({0, 0, 0});

        // 二重遍历
        for (int i = 0; i < nums.size(); i ++) {

            for (int j = i + 1; j < nums.size(); j ++) {

                if (nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2)
                    res.push_back({nums[i], nums[i], nums[j]});

                if (nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2)
                    res.push_back({nums[i], nums[j], nums[j]});

                int c = 0 - nums[i] - nums[j];
                if (c > nums[j] && counter[c] > 0)
                    res.push_back({nums[i], nums[j], c});
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = Solution().threeSum(nums1);

    for (int i = 0; i < res.size(); i ++) {
        for (int j = 0; j < res[i].size(); j ++)
            cout << res[i][j] << ", ";
        cout << endl;
    }
    return 0;
}
