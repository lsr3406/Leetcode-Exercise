/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-03 21:21:41
 * @update on: 2019-02-03 21:43:13
 */
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram

class Solution {
public:

    /**
     * 判断两个字符串是否互为变位词, 这里使用映射来统计两个字符串的各个字符的数量, 映射的实现用了哈希表的思想. 已知所有字符都是小写字母
     * @param  s 第一个字符串
     * @param  t 第二个字符串
     * @return
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    bool isAnagram(string s, string t) {
        // 字符串长度不同的情况
        if (s.size() != t.size())
            return false;

        // 计数器初始化
        int counter[26] = {0};
        // 遍历两个字符串, 照这样操作, 计数器最终所有的元素都为 0
        for (int i = 0; i < s.size(); i ++) {
            counter[s[i] - 'a'] ++;
            counter[t[i] - 'a'] --;
        }
        for (int i = 0; i < 26; i ++)
            if (counter[i] != 0)
                return false;
        return true;
    }
};

int main(int argc, char const *argv[]) {

    string s1("anagram");
    string t1("nagaram");
    string s2("rat");
    string t2("car");

    bool res1 = Solution().isAnagram(s1, t1);
    bool res2 = Solution().isAnagram(s2, t2);

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}
