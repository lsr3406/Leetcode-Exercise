/**
 * encoding: utf-8
 * @author: siru
 * @create on: 2019-01-31 10:24:31
 * @update on: 2019-02-07 21:09:03
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {

        // return maxArea1(height);
        return maxArea2(height);
    }

    /**
     * 方案一: 二重遍历, 找出所有的可能情况
     * 时间复杂度: O(n^2)
     * 空间复杂度: O(1)
     */ 
    int maxArea1(vector<int>& height) {

        int tempMaxArea = 0;
        for (int i = 0; i < height.size(); i ++) {
            for (int j = i + 1; j < height.size(); j ++) {
                int currentArea = (j - i) * min(height[i], height[j]);
                if ( currentArea > tempMaxArea )
                    tempMaxArea = currentArea;
            }
        }
        return tempMaxArea;
    }

    /**
     * 方案二: 贪心算法, 指针对撞, 可使用反证法确定该方案能得到最优解
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     */ 
    int maxArea2(vector<int>& height) {

        int tempMaxArea = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            // 计算当前面积
            int currentArea = (r - l) * min(height[l], height[r]);
            if (currentArea > tempMaxArea)
                tempMaxArea = currentArea;

            // TODO prove
            if (height[l] > height[r])
                r --;
            else  // height[l] <= height[r]
                l ++;
        }
        return tempMaxArea;
    }
};

int main(int argc, char const *argv[]) {
    
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height(arr, end(arr));

    int res = Solution().maxArea(height);

    cout << res << endl;

    return 0;
}

