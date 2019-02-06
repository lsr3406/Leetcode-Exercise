/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-06 22:06:29
 * @update on: 2019-02-06 22:51:53
 */
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:

    /**
     * 建立一个计数器, 统计频率后排序, 最后创建新的字符串输出.
     * 同样频率的字母不要求保持原来的位置
     */
    string frequencySort(string s) {
        
        // 计数器初始化
        pair<int, char> counter[128];
        for (int i = 0; i < 128; i ++) {
            counter[i].first = 0;
            counter[i].second = i;
        }

        // 统计词频
        for (int i = 0; i < s.size(); i ++)
            counter[s[i]].first ++;
        
        // 排序
        sort(counter, counter + 128, greater<pair<int, char>>());

        // 新字符串
        int index = 0;
        for (int i = 0; i < 128; i ++) {
            while (counter[i].first > 0){
                s[index] = counter[i].second;
                index ++;
                counter[i].first --;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
    
    cout << Solution().frequencySort("tree") << endl;

    return 0;
}

