/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-01 16:52:27
 * @update on: 2019-02-01 22:28:20
 */
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring

/**
 * 寻找包含 t 中所有字符的最短子字符串, 找不到返回空串, 要求时间复杂度 O(n)
 */
class Solution {
public:

    /**
     * 滑动窗口记录有效信息
     * 时间复杂度: O(length(s))
     * 空间复杂度: O(length(t))
     */
    string minWindow(string s, string t) {
        
        // 创建并初始化目标计数器
        int targetCounter[256] = {0};
        for (int i = 0; i < t.size(); i ++) {
            targetCounter[t[i]] ++;
        }

        // 创建原字符串中有效字符索引数组及有效字符
        vector<int> availableIndex;
        string availableString = "";
        for (int i = 0; i < s.size(); i ++) {
            if (targetCounter[s[i]] > 0) {
                availableIndex.push_back(i);
                availableString += s[i];
            }
        }
        
        // 创建原数组计数器
        int stringCounter[256] = {0};
        int count = 0;  // stringCounter 总和

        int minLength = s.size() + 1;
        int l = 0;

        int startIndex = 0;
        // int endIndex = -1;

        // 考察区间 [l, r], minLength 在这里始终存放 r - l 的值
        for (int r = 0; r < availableIndex.size(); r ++) {

            // 多容纳一个有效字符
            stringCounter[availableString[r]] ++;
            if (stringCounter[availableString[r]] <= targetCounter[availableString[r]])
                count ++;

            if (count < t.size())
                continue;

            do {  // 多容纳一个有效字符
                stringCounter[availableString[l]] --;
                if (stringCounter[availableString[l]] < targetCounter[availableString[l]])
                    count --;
                l ++;
            } while (count >= t.size());

            // 计算一次
            int currentLength = availableIndex[r] - availableIndex[l-1] + 1;
            if (minLength > currentLength) {
                minLength = currentLength;
                startIndex = availableIndex[l-1];  // (l - 1)
                // endIndex = availableIndex[r] + 1;  // (r) + 1
            }
        }

        return minLength == s.size() + 1 ? "" : s.substr(startIndex, minLength);
    }
};

int main(int argc, char const *argv[]) {

    // string s = "ADOBECODEBANC", t = "ABC";  // "BANC"
    // string s = "a", t = "aa";  // ""
    // string s = "abc", t = "b";  // "b"
    string s = "cabwefgewcwaefgcf", t = "cae";  // "cwae"

    string res = Solution().minWindow(s, t);
    
    cout << res << endl;

    return 0;
}
