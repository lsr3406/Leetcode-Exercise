/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-30 22:33:28
 * @update on: 2019-01-31 09:41:39
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        
        int l = nextVowelIndex(s, 0);
        int r = previousVowelIndex(s, s.size() - 1);

        while (l < r) {

            swap(s[l], s[r]);
            l = nextVowelIndex(s, l + 1);
            r = previousVowelIndex(s, r - 1);
        }
        return s;
    }

private:

    /**
     * 找到字符串 s 中 index 起下一个元音字母对应的索引
     */
    int nextVowelIndex(const string& s, int index) {
        for (int i = index; i < s.size(); i ++)
            if (isVowel(s[i]))
                return i;
        return s.size();
    }

    /**
     * 找到字符串 s 中 index 起的前一个元音字母对应的索引
     */
    int previousVowelIndex(const string& s, int index) {
        for (int i = index; i >= 0; i --)
            if (isVowel(s[i]))
                return i;
        return -1;
    }

    bool isVowel(char c) {
        char lowerC = tolower(c);
        return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
    }
};

int main(int argc, char const *argv[]) {
    
    // string str1("hello");
    string str2("leetcode");

    Solution solution = Solution();
    // string res1 = solution.reverseVowels(str1);
    string res2 = solution.reverseVowels(str2);

    // cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}
