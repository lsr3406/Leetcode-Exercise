/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-05 20:35:00
 * @update on: 2019-03-05 20:51:24
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:

    /**
     * 判断数组中是否存在相同元素, 距离小于给定值 k
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // return containsNearbyDuplicate1(nums, k);
        return containsNearbyDuplicate2(nums, k);
    }

    /**
     * 使用集合
     */
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {

        unordered_set<int> set;        

        for (int i = 0; i < nums.size(); i ++) {
            if (i > k)
                set.erase(nums[i - k - 1]);
            if (!set.insert(nums[i]).second)
                return true;
        }
        return false;
    }

    /**
     * 使用映射
     */
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {

        unordered_map<int, int> map;        

        for (int i = 0; i < nums.size(); i ++) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
                return true;
            map[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> vec({1,2,3,1,2,3});
    bool res = Solution().containsNearbyDuplicate(vec, 3);

    cout << res << endl;
    
    return 0;
}

