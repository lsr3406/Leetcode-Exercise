/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-03 23:47:26
 * @update on: 2019-02-06 22:04:33
 */
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:

    /**
     * 判断两个字符串是否同构.
     * 使用数组模拟映射
     */
    bool isIsomorphic(string s, string t) {
        
        // assert(s.size() == t.size());  // 题目假定长度相等

        // 创建两个映射表
        char map1[128] = {0};  // s -> t
        char map2[128] = {0};  // t -> s

        for (int i = 0; i < s.size(); i ++) {
            // 能找到记录就查询
            if (map1[s[i]] != 0 || map2[t[i]] != 0){
                if (map1[s[i]] != t[i] || map2[t[i]] != s[i])
                    return false;
            }
            // 找不到记录就添加
            else {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    
    cout << Solution().isIsomorphic("egg", "add") << endl;  // True
    cout << Solution().isIsomorphic("foo", "bar") << endl;  // False
    cout << Solution().isIsomorphic("paper", "title") << endl;  // True
    cout << Solution().isIsomorphic("ab", "aa") << endl;  // False

    return 0;
}

