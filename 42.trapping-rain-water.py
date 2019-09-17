#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#
class Solution:
    def trap(self, height):
        length = len(height)
        if not height or length < 3:
            return 0
        vol = 0
        l , r = 0 , length - 1
        l_max = height[l]
        r_max = height[r]
        while l < r:
            l_max = max(height[l], l_max)
            r_max = max(height[r], r_max)
            if l_max <= r_max:
                vol += l_max - height[l]
                l += 1
            else:
                vol += r_max - height[r]
                r -= 1
        return vol  
        

