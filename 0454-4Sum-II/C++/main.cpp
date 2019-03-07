/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-28 21:49:45
 * @update on: 2019-02-28 22:31:41
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    /**
     * 在四个数组中, 各取一个数, 使和为 0, 求有多少种情况
     * 将 A + B 的所有的可能的情况都列出来, C + D 的所有可能的情况都列出来, 之后对两个新的序列求解一次
     */
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        unordered_map<int, int> map1, map2;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < B.size(); j ++) {
                map1[A[i] + B[j]] += 1;
                map2[C[i] + D[j]] += 1;
            }
        }

        int res = 0;
        for (unordered_map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter ++)
            if (map2.find(-(iter->first)) != map2.end())
                res += iter->second * map2[-(iter->first)];
        return res;
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}

