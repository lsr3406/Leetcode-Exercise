/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-02-01 23:04:26
 * @update on: 2019-02-01 23:19:12
 */
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

// 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    /**
     * 三角形数, 本题有 O(n), O(sqrt(n)), O(1) 多种解法
     * @param  n 硬币数量
     * @return   硬币能够摆满的三角形直角边长
     */
    int arrangeCoins(int n) {
        // n = a * (a + 1) / 2 => a = ?
        return (-1 + sqrt(1 + 8 * (long)n)) / 2;
    }
};

int main(int argc, char const *argv[]) {
    
    cout << Solution().arrangeCoins(5) << endl;
    cout << Solution().arrangeCoins(8) << endl;
    cout << Solution().arrangeCoins(1804289383) << endl;

    return 0;
}
