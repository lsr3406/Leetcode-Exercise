#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-01 09:07:35
# @update on: 2019-11-01 09:08:14

# 417. Pacific Atlantic Water Flow
# https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        n_rows = len(matrix)
        n_cols = len(matrix[0])
        
        pacific = [[False for c in matrix[0]] for r in matrix]
        atlantic = [[False for c in matrix[0]] for r in matrix]
        
        # i: [0, n_rows-1], j: 0
        for r in range(n_rows):
            self.dfs(r, 0, pacific, matrix)
            self.dfs(r, n_cols-1, atlantic, matrix)
        
        # i: 0, j: [0, n_cols-1]
        for j in range(n_cols):
            self.dfs(n_rows-1, j, atlantic, matrix)
            self.dfs(0, j, pacific, matrix)
        
        res = []
        for i in range(n_rows):
            for j in range(n_cols):
                if pacific[i][j] and atlantic[i][j]:
                    res.append([i, j])
        return res
    
    def dfs(self, i, j, available, matrix):
        if available[i][j]:
            return
        available[i][j] = True
        
        if i - 1 >= 0 and matrix[i - 1][j] >= matrix[i][j]:
            self.dfs(i - 1, j, available, matrix)
        if i + 1 < len(available) and matrix[i + 1][j] >= matrix[i][j]:
            self.dfs(i + 1, j, available, matrix)
        if j - 1 >= 0 and matrix[i][j - 1] >= matrix[i][j]:
            self.dfs(i, j - 1, available, matrix)
        if j + 1 < len(available[0]) and matrix[i][j + 1] >= matrix[i][j]:
            self.dfs(i, j + 1, available, matrix)
