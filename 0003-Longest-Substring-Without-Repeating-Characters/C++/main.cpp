/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-31 19:22:29
 * @update on: 2019-02-01 15:59:58
 */
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    /**
     * 在一个字符串中找到没有重复字符的子串
     * @param  s 待搜索字符串
     * @return   满足要求的最大字串长度
     */
    int lengthOfLongestSubstring(string s) {

        return lengthOfLongestSubstring1(s);
    }

    /**
     * 方案一: 滑动窗口
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */
    int lengthOfLongestSubstring1(string& s) {

        // 如果程序每次运行得到的结果不一样, 可能是有些数组定义好后没有初始化
        int characters[256] = {0};
        int maxLength = 0;
        int l = 0;

        // 考察区间 [l, r], maxLength 在这里始终存放 r - l 的值
        for (int r = 0; r < s.size(); r ++) {

            // 可以容纳索引为 r 的元素
            if (characters[s[r]] == 0) {
                // do nothing
            }
            // 必须从左侧缩减长度
            else {
                // 计算一次长度, 这里的 r 已经多算了一次
                maxLength = max(maxLength, r - l);
                do {
                    characters[s[l]] --;
                    l ++;
                } while (characters[s[r]] != 0);
            }
            characters[s[r]] ++;
        }
        // 最后还要再算一次, 这里 r 是没有多算的
        maxLength = max(maxLength, static_cast<int>(s.size()) - l);

        return maxLength;
    }
};

int main(int argc, char const *argv[]) {
    
    string str1("abcabcbb");
    string str2("bbbbb");
    string str3("pwwkew");
    string str4("c");
    string str5("abba");
    string str6("");

    Solution solution = Solution();
    int res1 = solution.lengthOfLongestSubstring(str1);
    int res2 = solution.lengthOfLongestSubstring(str2);
    int res3 = solution.lengthOfLongestSubstring(str3);
    int res4 = solution.lengthOfLongestSubstring(str4);
    int res5 = solution.lengthOfLongestSubstring(str5);
    int res6 = solution.lengthOfLongestSubstring(str6);

    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    cout << res4 << endl;
    cout << res5 << endl;
    cout << res6 << endl;

    return 0;
}

