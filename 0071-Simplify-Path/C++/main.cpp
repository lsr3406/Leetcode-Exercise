/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-24 08:28:34
 * @update on: 2019-03-24 09:17:03
 */
#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

// 71. Simplify Path
// https://leetcode.com/problems/simplify-path

class Solution {
public:

    string simplifyPath(string path) {

        stack<string> record;
        string cur = "";

        int index = 0;
        assert(path[index] == '/');

        while (index < path.size()) {

            index ++;
            int endIndex = find(path, '/', index);

            if (index == endIndex)
                continue;

            string cur = string(path, index, endIndex - index);
            if (cur == "..") {
                if (!record.empty())
                    record.pop();
            }
            else if (cur.size() > 0 && cur != ".") {
                record.push(cur);
            }

            index = endIndex;
        }

        string res = "";
        while (!record.empty()) {
            string cur = record.top();
            record.pop();
            res = "/" + cur + res;
        }
        return res.size() > 0 ? res : "/";
    }

    int find(const string& s, char c, int from) {
        int index;
        for (index = from; index < s.size(); index ++) {
            if (s[index] == '/')
                break;
        }
        return index;
    }
};

int main(int argc, char const *argv[]) {
    string path = "/a//b////c/d//././/..";

    cout << path << endl;
    string simplified = (Solution()).simplifyPath(path);
    cout << simplified << endl;

    return 0;
}
