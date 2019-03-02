/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-02 18:00:50
 * @update on: 2019-03-02 18:35:50
 */
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    /**
     * 创建一个映射, 遍历每个字符串, 排序, 插入到相应的 value 中
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        for (const string& s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto& p: map) {
            res.push_back(p.second);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string>> res = Solution().groupAnagrams(strs);

    for (int i = 0; i < res.size(); i ++) {
        for (int j = 0; j < res[i].size(); j ++)
            cout << res[i][j] << ", ";
        cout << endl;
    }

    return 0;
}
