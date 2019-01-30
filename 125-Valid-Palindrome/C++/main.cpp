/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-30 19:49:09
 * @update on: 2019-01-30 22:24:05
 */
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {

        int l = 0, r = s.size() - 1;

        l = nextAlphaNumeric(s, l + 1);
        r = previousAlphaNumeric(s, r - 1);

        while (l <= r) {
            if (tolower(s[l]) != tolower(s[r]))
                return false;

            l = nextAlphaNumeric(s, l + 1);
            r = previousAlphaNumeric(s, r - 1);
        }

        return true;
    }

private:

    /**
     * 找到 s 中索引排在 index 之后的第一个字母或数字, 找不到返回字符串的长度
     */
    int nextAlphaNumeric(const string& s, int index) {

        for (int i = index; i < s.size(); i ++)
            if (isalnum(s[i]))
                return i;
        return s.size();
    }

    /**
     * 找到 s 中索引排在 index 之前的第一个字母或数字, 找不到返回 -1
     */
    int previousAlphaNumeric(const string& s, int index) {

        for (int i = index; i >= 0; i --)
            if (isalnum(s[i]))
                return i;
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    
    string str1("A man, a plan, a canal: Panama");
    string str2("race a car");

    Solution solution = Solution();
    bool res1 = solution.isPalindrome(str1);
    bool res2 = solution.isPalindrome(str2);

    cout << (res1 ? "True" : "False") << endl;
    cout << (res2 ? "True" : "False") << endl;


    return 0;
}

