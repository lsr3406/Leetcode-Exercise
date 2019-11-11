#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-11 09:55:31
# @update on: 2019-11-11 09:55:57

# 120. Triangle
# https://leetcode.com/problems/triangle/

class Solution:
    def minimumTotal(self, triangle):
        # not accepted
        # return self.solve(triangle, 0, 0)
    
        for i in range(len(triangle)-2, -1, -1):
            triangle[i] = [min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j] for j in range(len(triangle[i]))]
        return triangle[0][0]

    def solve(self, triangle, i, j):
        if i >= len(triangle):
            return 0
        return min(
            self.solve(triangle, i + 1, j),
            self.solve(triangle, i + 1, j + 1)
        ) + triangle[i][j]
