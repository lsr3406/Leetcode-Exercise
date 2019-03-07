/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-03-05 16:01:44
 * @update on: 2019-03-05 16:33:04
 */
#include <iostream>
#include <cassert>
#include <limits.h>

using namespace std;

class Solution {
public:
    /**
     * 求解 x^n, 前面处理一些特殊情况, 最后递归计算
     */
    double myPow(double x, int n) {

        if (x == 1 || x == 0)
            return x;
        // 无法直接将 INT_MIN 转换为 INT_MAX + 1, 所以要特殊对待
        if (n == INT_MIN) {
            return pow_recursive(1 / x, INT_MAX) / x;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return pow_recursive(x, n);
    }

    /**
     * 递归求解
     */
    double pow_recursive(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double aux = pow_recursive(x, n / 2);
        return n % 2 ? aux * aux * x : aux * aux;
    }
};

int main(int argc, char const *argv[]) {    
    return 0;
}

