/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-03 22:13:33
 * @update on: 2019-02-03 23:45:04
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// 290. Word Pattern
// https://leetcode.com/problems/word-pattern

class Solution {
public:
    /**
     * 检测给定字符串是否匹配指定的样式
     * 使用一个映射, 按 s 的内容检索, 检索到单词, 选择性使用映射中已有的记录对照, 或向映射中添加记录
     * debug 必须设置两个映射, 要实现一一对应
     * @param  pattern 给定样式
     * @param  str     给定字符串
     * @return
     */
    bool wordPattern(string pattern, string str) {

        unordered_map<char, string> record1;
        unordered_map<string, char> record2;

        // 分词
        vector<string> words = split(str);

        if (words.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i ++) {
            
            char p = pattern[i];
            string word = words[i];

            // 保存记录查询结果
            bool hit1 = record1.find(p) != record1.end();
            bool hit2 = record2.find(word) != record2.end();

            // 两个记录必须都有或者都没有
            if (hit1 ^ hit2)
                return false;

            // 有记录, 检测该单词是否匹配记录. 去掉 record2[word] != p 提交一样能通过
            if (hit1 && (record1[p] != word || record2[word] != p))
                return false;

            // 找不到记录, 则创建记录
            record1[p] = word;
            record2[word] = p;
        }
        return true;
    }

private:

    /**
     * 分词, 不考虑前后的空白
     */
    vector<string> split(const string& s) {
        vector<string> res;

        int start = 0;

        // 这里循环终止条件加了等号
        for (int i = start; i <= s.size(); i ++) {

            if (i >= s.size() || s[i] == ' '){
                res.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {

    cout << (Solution().wordPattern("abba", "dog cat cat dog") ? "True" : "False") << endl;  // "True"
    cout << (Solution().wordPattern("abba", "dog cat cat fish") ? "True" : "False") << endl;  // "False"
    cout << (Solution().wordPattern("aaaa", "dog cat cat dog") ? "True" : "False") << endl;  // "False"
    cout << (Solution().wordPattern("abba", "dog dog dog dog") ? "True" : "False") << endl;  // "False"

    return 0;
}
