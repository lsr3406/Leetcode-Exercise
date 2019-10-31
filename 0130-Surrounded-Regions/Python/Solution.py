#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-10-31 17:32:12
# @update on: 2019-10-31 17:33:04

# 130. Surrounded Regions
# https://leetcode.com/problems/surrounded-regions/

class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        # visited 仅用于记录 O 这个字符的位置是否被访问过
        visited = [[False for c in board[0]] for r in board]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "O" and visited[i][j] == False and self.dfs(board, visited, i, j):
                    self.setX(board, i, j)
    
    def dfs(self, board, visited, i, j, depth=0):
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            # 坐标越界, 表示与这个 O 相连的区域要保留
            return False
        if board[i][j] == "X" or visited[i][j]:
            return True
        visited[i][j] = True
        res = all([self.dfs(board, visited, i + 1, j), self.dfs(board, visited, i, j + 1),
            self.dfs(board, visited, i - 1, j), self.dfs(board, visited, i, j - 1)])
        return res

    def setX(self, board, i, j, depth=0):
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
            return
        if board[i][j] == "X":
            return
        board[i][j] = "X"
        self.setX(board, i + 1, j)
        self.setX(board, i, j + 1)
        self.setX(board, i - 1, j)
        self.setX(board, i, j - 1)