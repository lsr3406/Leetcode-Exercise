/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-28 19:57:02
 * @update on: 2019-02-28 21:05:56
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

class Solution {
public:

    /**
     * 求距目标最近的三数之和. 首先将原数组排序, 之后将原问题转化为 一重遍历 + 2Sum-Closest 的问题, 2Sum-Closest 使用指针对撞来解决
     */
    int threeSumClosest(vector<int>& nums, int target) {
        
        assert(nums.size() >= 3);
        sort(nums.begin(),nums.end());

        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);

        for (int i = 0; i < nums.size(); i ++) {

            int t = target - nums[i];
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {

                int s = nums[l] + nums[r];
                if (s == t)
                    return target;

                int d = abs(t - s);
                if (d < diff) {
                    res = nums[i] + s;
                    diff = d;
                }
                if (s < t)
                    l ++;
                else
                    r --;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << Solution().threeSumClosest(nums, target) << endl;
    
    return 0;
}

