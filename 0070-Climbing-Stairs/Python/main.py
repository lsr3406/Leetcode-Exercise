#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-08 14:20:45
# @update on: 2019-11-08 14:25:41

# 70. Climbing Stairs
# https://leetcode.com/problems/climbing-stairs/

class Solution:
    
    def __init__(self):
        self.stairs_map = {
            0: 1,
            1: 1
        }

    def climbStairs(self, n):
        """
        爬楼梯问题, 标准的动态规划
        """
        if n in self.stairs_map:
            return self.stairs_map[n]
        res = self.climbStairs(n-1) + self.climbStairs(n-2)
        self.stairs_map[n] = res
        return res

if __name__ == '__main__':
    print(Solution().climbStairs(3))