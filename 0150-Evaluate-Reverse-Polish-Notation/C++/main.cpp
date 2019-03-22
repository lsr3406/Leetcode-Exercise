/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-22 16:38:59
 * @update on: 2019-03-22 17:33:21
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> record;
        for (int i = 0; i < tokens.size(); i ++) {

            if (isOperator(tokens[i])) {
                int num1 = record.top();
                record.pop();
                int num2 = record.top();
                record.pop();

                int res = calculate(num1, num2, tokens[i]);
                record.push(res);
            }
            else {  // is Number
                record.push(stoi(tokens[i]));
            }
        }
        return record.top();
    }

    bool isOperator(const string& s) {
        if (s.length() > 1)
            return false;
        char c = s[0];
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int calculate(int a, int b, const string& op) {
        switch (op[0]) {
            case '+':
                return b + a;
            case '-':
                return b - a;
            case '*':
                return b * a;
            case '/':
                return b / a;
            default:
                throw "Illegal operator";
        }
    }
};

int main(int argc, char const *argv[]) {

    vector<string> inputs({"2", "1", "+", "3", "*"});
    int res = (Solution()).evalRPN(inputs);

    cout << res << endl;

    return 0;
}
