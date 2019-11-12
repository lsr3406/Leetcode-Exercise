#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-12 09:34:36
# @update on: 2019-11-12 09:34:59

# 64. Minimum Path Sum
# https://leetcode.com/problems/minimum-path-sum/

class Solution:
    def minPathSum(self, grid):
        m = len(grid)
        n = len(grid[0])
        for i in range(1, m):
            grid[i][0] = grid[i-1][0] + grid[i][0]
        for j in range(1, n):
            grid[0][j] = grid[0][j-1] + grid[0][j]
        
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
        return grid[-1][-1]
