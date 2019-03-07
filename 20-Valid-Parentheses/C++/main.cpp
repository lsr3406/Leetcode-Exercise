/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-07 20:36:32
 * @update on: 2019-03-07 21:58:56
 */
#include <iostream>
#include <cassert>
#include <stack>
#include <string>

using namespace std;

// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses

class Solution {
public:

    /**
     * 模拟栈的实现
     */
    bool isValid(string s) {

        stack<char> record;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                record.push(s[i]);
            else {
                if (record.empty())
                    return false;
                char temp = record.top();
                if (s[i] == ')' && temp != '(' || s[i] == ']' && temp != '[' || s[i] == '}' && temp != '{')
                    return false;
                record.pop();
            }
        }
        return record.empty();
    }
};

int main(int argc, char const *argv[]) {

    string res("{[()[]]}()");

    cout << Solution().isValid(res) << endl;
    
    return 0;
}

