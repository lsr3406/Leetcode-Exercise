#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-08 09:46:44
# @update on: 2019-11-08 10:20:02

# 37. Sudoku Solver
# https://leetcode.com/problems/sudoku-solver/

class Solution:
    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        self.solve(board)
    
    def solve(self, board):
        """
        递归函数, 返回沿当前 board 是否可以得到解
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == ".":
                    available_numbers = self.find_available_number(board, i, j)
                    if available_numbers == {}:
                        return False
                    for number in available_numbers:
                        board[i][j] = number
                        if self.solve(board):
                            return True
                    board[i][j] = "."
                    return False
        return True

    def find_available_number(self, board, i, j):
        """
        给定坐标, 得出当前坐标点可以放置的数字
        """
        available_numbers = {"1", "2", "3", "4", "5", "6", "7", "8", "9"}
        # 1. 遍历行和列
        for k in range(len(board)):
            if board[i][k] in available_numbers:
                available_numbers.remove(board[i][k])
            if board[k][j] in available_numbers:
                available_numbers.remove(board[k][j])

        # 2. 遍历相应的 3*3 的方块
        row_start, col_start = (i // 3) * 3, (j // 3) * 3
        for k in range(row_start, row_start + 3):
            for l in range(col_start, col_start + 3):
                if board[k][l] in available_numbers:
                    available_numbers.remove(board[k][l])
        return available_numbers

    def print_board(self, board):
        for row in board:
            print(" ".join(row))
        print()

if __name__ == '__main__':
    
    sudoku = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    Solution().solveSudoku(sudoku)
    print(sudoku)
