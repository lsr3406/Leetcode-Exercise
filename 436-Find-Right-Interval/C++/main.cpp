/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-01 16:07:47
 * @update on: 2019-02-01 16:49:28
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

// 436. Find Right Interval
// https://leetcode.com/problems/find-right-interval

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    /**
     * 找到一个区间数组中, 每个区间右侧最近的区间所在的索引. 找不到返回 -1
     * 根据区间左侧的值排序, 根据区间右侧的值作二分查找
     */
    vector<int> findRightInterval(vector<Interval>& intervals) {
        // 使用 C++ 中的映射
        map<int, int> indexMap;
        vector<int> res;

        // 将所有的区间左侧元素放入映射中, key 为区间左侧的元素, value 为区间在数组中的索引
        for (int i = 0; i < intervals.size(); i ++) {
            indexMap[intervals[i].start] = i;
        }

        // 依次按照区间右侧的元素作二分查找
        for (int i = 0; i < intervals.size(); i ++) {
            auto index = indexMap.lower_bound(intervals[i].end);
            if (index == indexMap.end())
                res.push_back(-1);
            else
                res.push_back(index -> second);
        }
        return res;
    }
};

int printIntegerVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i ++) {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    
    Interval arr1[] = {Interval(1, 2)};
    Interval arr2[] = {Interval(3, 4), Interval(2, 3), Interval(1, 2)};
    Interval arr3[] = {Interval(1, 4), Interval(2, 3), Interval(3, 4)};

    vector<Interval> intervals1(arr1, end(arr1));
    vector<Interval> intervals2(arr2, end(arr2));
    vector<Interval> intervals3(arr3, end(arr3));

    Solution solution = Solution();
    vector<int> res1 = solution.findRightInterval(intervals1);
    vector<int> res2 = solution.findRightInterval(intervals2);
    vector<int> res3 = solution.findRightInterval(intervals3);

    printIntegerVector(res1);
    printIntegerVector(res2);
    printIntegerVector(res3);

    return 0;
}

