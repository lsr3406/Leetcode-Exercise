#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-10-31 17:30:33
# @update on: 2019-10-31 17:30:57

# 200. Number of numIslands
# https://leetcode.com/problems/number-of-islands/

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        visited = [[False for c in grid[0]] for r in grid]
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1" and visited[i][j] == False:
                    self.dfs(grid, visited, i, j)
                    count += 1
        return count
    
    def dfs(self, grid, visited, i, j, depth=0):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
            return
        if grid[i][j] == "0" or visited[i][j]:
            return
        visited[i][j] = True
        # print("depth: {} --- ({}, {})".format(depth,  i, j))
        # print(visited)
        self.dfs(grid, visited, i + 1, j, depth + 1)
        self.dfs(grid, visited, i, j + 1, depth + 1)
        self.dfs(grid, visited, i - 1, j, depth + 1)
        self.dfs(grid, visited, i, j - 1, depth + 1)