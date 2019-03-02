/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-02 18:53:31
 * @update on: 2019-03-02 19:43:25
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs

class Solution {
public:
    /**
     * 二重遍历, 统计两两之间的距离, 针对每个点, 分析其到其他各点的距离.
     */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {

        int res = 0;
        for (int i = 0; i < points.size(); i ++) {

            unordered_map<int, int> map;
            for (int j = 0; j < points.size(); j ++)
                map[distance(points[i], points[j])] += 1;
            map[0] --;
            
            for (unordered_map<int, int>::iterator iter = map.begin(); iter != map.end(); iter ++) {
                res += (iter->second) * (iter->second - 1);
            }
        }
        return res;
    }

    int distance(pair<int, int> p1, pair<int, int> p2) {
        int x = (p1.first - p2.first);
        int y = (p1.second - p2.second);
        return x * x + y * y;
    }
};

int main(int argc, char const *argv[]) {

    vector<pair<int, int>> points;
    points.push_back(make_pair(0, 0));
    points.push_back(make_pair(1, 0));
    points.push_back(make_pair(2, 0));

    int res = Solution().numberOfBoomerangs(points);
    cout << res << endl;

    return 0;
}

