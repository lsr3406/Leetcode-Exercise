/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-01 22:43:42
 * @update on: 2019-02-01 23:02:45
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

using namespace std;

// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:

    /**
     * 将 nums1 中的元素依次放入集合 set1 中, 遍历 nums2 并依次在 set1 中查找, 结果放入 resSet 中 然后遍历集合取出元素
     * 时间复杂度: O(n1 + n2)
     * 空间复杂度: O()
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> resSet;

        for (int e: nums2)
            if (set1.find(e) != set1.end())
                resSet.insert(e);
        
        return vector<int>(resSet.begin(), resSet.end());
    }
};

int main(int argc, char const *argv[]) {

    int arr1[] = {1, 2, 2, 1};
    int arr2[] = {2, 2};
    vector<int> nums1 = vector<int>(arr1, end(arr1));
    vector<int> nums2 = vector<int>(arr2, end(arr2));

    vector<int> res = Solution().intersection(nums1, nums2);

    for (int e: res)
        cout << e;
    cout << endl;

    return 0;
}

