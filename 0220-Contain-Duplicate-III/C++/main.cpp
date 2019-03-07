/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-05 20:53:51
 * @update on: 2019-03-06 23:02:44
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    /**
     * 使用容量为 k 的集合
     */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        if (k <= 0)
            return false;

        set<long> record;
        for (int i = 0; i < nums.size(); i ++) {

            if (record.lower_bound((long)nums[i] - t) != record.end() && *record.lower_bound((long)nums[i] - t) <= (long)nums[i] + t)
                return true;
            record.insert((long)nums[i]);
            
            if (i >= k)
                record.erase((long)nums[i - k]);
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> vec({-2147483648, -2147483647});
    cout << Solution().containsNearbyAlmostDuplicate(vec, 3, 3) << endl;

    return 0;
}
