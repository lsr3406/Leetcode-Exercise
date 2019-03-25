/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-25 19:27:55
 * @update on: 2019-03-25 19:32:49
 */
#include <iostream>
#include <vector>

using namespace std;

// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty())
            return 0;
        
        int newIndex = 1;
        int curNum = nums[0];

        for (int i = 1; i < nums.size(); i ++) {

            if (nums[i] != curNum){
                curNum = nums[i];
                nums[newIndex] = curNum;
                newIndex ++;
            }
        }

        return newIndex;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> vec({0,0,1,1,1,2,2,3,3,4});
    int res = Solution().removeDuplicates(vec);

    for (int i = 0; i < res; i ++)
        cout << vec[i] << ", ";
    cout << endl;
    
    return 0;
}
