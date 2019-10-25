# !/usr/bin/python
# -*- encoding: utf-8 -*-
# @author: siru
# @create on: Fri 2019-10-25 19:16:26
# @update on: Fri 2019-10-25 19:44:24
class Solution:
    def trap(self, height):
        """
        判断积水量.
        1. 设置两个数组, 满足 3 个要求: 元素不小于 height 中的对应项, 元素尽可能小, 一个递增一个递减
        2. 对这两个数组逐个元素求最小值, 即为积水后的状态
        3. 求和, 相减
        """
        arr_asc = height.copy()
        arr_desc = height.copy()

        n = len(height)
        for i, j in zip(range(1, n), range(n-2, -1, -1)):
            # i: [1, 2, ..., n-2, n-1]
            # j: [n-2, n-1, ..., 1, 0]
            arr_asc[i] = max(arr_asc[i-1], height[i])
            arr_desc[j] = max(arr_desc[j+1], height[j])
        
        arr_trap = [min(x, y) for x, y in zip(arr_asc, arr_desc)]
        res = sum(arr_trap) - sum(height)
        return res

if __name__ == "__main__":
    solution = Solution()
    res = solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    print(res)