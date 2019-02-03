/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-03 21:45:21
 * @update on: 2019-02-03 22:05:48
 */
#include <iostream>
#include <cassert>
#include <unordered_set>

using namespace std;

// 202. Happy Number
// https://leetcode.com/problems/happy-number

class Solution {
public:
    /**
     * 判断一个数是否为快乐数, 使用一个集合记录中间结果, 某个中间结果出现重复时即判失败
     * @param  n [description]
     * @return   [description]
     */
    bool isHappy(int n) {
        
        assert(n > 0);

        // 使用哈希表统计中间过程
        unordered_set<int> process;
        while (n != 1) {
            // 失败条件
            if (process.find(n) != process.end())
                return false;
            process.insert(n);
            n = next(n);
        }
        return true;
    }

private:
    /**
     * 整数按十进制分解, 然后返回各个位的平方和
     */
    int next(int n) {
        int res = 0;
        while (n != 0) {
            int temp = n % 10;
            res += temp * temp;
            n /= 10;
        }
        return res;
    }

};

int main(int argc, char const *argv[]) {

    cout << (Solution().isHappy(19) ? "True" : "False") << endl;

    return 0;
}
