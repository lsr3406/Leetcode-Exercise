#!/usr/bin/python
# -*- coding: utf-8 -*-
# @author: siru
# @create on: 2019-11-13 10:37:36
# @update on: 2019-11-13 10:55:03

# 343. Integer Break
# https://leetcode.com/problems/integer-break/

class Solution:
    
    def __init__(self):
        self.integer_break_map = {}
        
    def integerBreak(self, n):
        if n in self.integer_break_map:
            return self.integer_break_map[n]
        candidate = [n-1]
        for i in range(2, n // 2 + 1):
            r1 = max(self.integerBreak(i), i)
            r2 = max(self.integerBreak(n-i), n-i)
            candidate.append(r1 * r2)

        self.integer_break_map[n] = max(candidate)
        return self.integer_break_map[n]

if __name__ == '__main__':
    s = Solution()
    s.integerBreak(10)
    print(s.integer_break_map)