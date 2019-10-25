# !/usr/bin/python
# -*- encoding: utf-8 -*-
# @author: siru
# @create on: Fri 2019-10-25 19:59:24
# @update on: Fri 2019-10-25 20:17:15
class Solution:
    def trap(self, height):
        """
        判断积水量.
        使用栈作为辅助数据结构
        """
        stack = []
        res = 0
        print(height)
        for i in range(len(height)):
            while stack != [] and height[i] > height[stack[-1]]:
                last = stack.pop()
                if stack == []:
                    break
                w = i - stack[-1] - 1
                h = min(height[i], height[stack[-1]]) - height[last]
                res += w * h
                print("add: ", w, h)
            stack.append(i)
            print(stack)
        return res

if __name__ == "__main__":
    solution = Solution()
    res = solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    print(res)