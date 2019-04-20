#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#
# https://leetcode.com/problems/contains-duplicate-ii/description/
#
# algorithms
# Easy (34.93%)
# Total Accepted:    191.4K
# Total Submissions: 546.3K
# Testcase Example:  '[1,2,3,1]\n3'
#
# Given an array of integers and an integer k, find out whether there are two
# distinct indices i and j in the array such that nums[i] = nums[j] and the
# absolute difference between i and j is at most k.
# 
# 
# Example 1:
# Input: nums = [1,2,3,1], k = 3
# Output: true
# 
# Example 2:
# Input: nums = [1,0,1,1], k = 1
# Output: true
# 
# Example 3:
# Input: nums = [1,2,3,1,2,3], k = 2
# Output: false
# 
# 

class Solution:
    def containsNearbyDuplicate(self, nums: 'List[int]', k: 'int') -> 'bool':      
        if len(set(nums)) != len(nums):
            for i in range(len(nums)):
                for j in range(1,k + 1):
                    if i + j < len(nums):
                        if nums[i] == nums[i + j]:
                            return True
            return False
        else:
            return False


