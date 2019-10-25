# !/usr/bin/python
# -*- encoding: utf-8 -*-
# @author: siru
# @create on: Fri 2019-10-25 20:23:40
# @update on: Fri 2019-10-25 20:32:40
class Solution:
    def trap(self, height):
        """
        判断积水量.
        使用双指针
        """
        left, right = 0, len(height)-1
        left_max, right_max = 0, 0
        res = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] > left_max:
                    left_max = height[left]
                else:
                    res += left_max - height[left]
                left += 1
            else:
                if height[right] > right_max:
                    right_max = height[right]
                else:
                    res += right_max - height[right]
                right -= 1
        return res

if __name__ == "__main__":
    solution = Solution()
    res = solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])
    print(res)