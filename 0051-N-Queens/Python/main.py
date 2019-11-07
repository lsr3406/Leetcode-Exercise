#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-07 18:53:36
# @update on: 2019-11-07 18:54:28

# 51. N-Queens
# https://leetcode.com/problems/n-queens/

import copy

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        solution = []
        available = [[True for j in range(n)] for i in range(n)]
        self.solve(n, 0, [], available, solution)
        return solution
    
    def solve(self, n, line, board, available, solution):
        # 找到了一个解, 构造字符串
        if line >= n:
            new_solution = ["".join(["Q" if board[i] == j else "." for j in range(n)]) for i in range(n)]
            solution.append(new_solution)
            return
        
        # 遍历该行, 寻找可以落子的位置
        for j in range(n):
            if available[line][j]:
                new_board = copy.copy(board)
                new_board.append(j)
                new_available = copy.deepcopy(available)
                self.set_unavailable(new_available, line, j)
                self.solve(n, line + 1, new_board, new_available, solution)
    
    def set_unavailable(self, available, i, j):
        n = len(available)
        
        for index in range(1, n - i):
            available[i + index][j] = False
            if j - index >= 0:
                available[i + index][j - index] = False
            if j + index < n:
                available[i + index][j + index] = False
