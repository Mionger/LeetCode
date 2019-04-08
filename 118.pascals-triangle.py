#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (45.11%)
# Total Accepted:    238.5K
# Total Submissions: 528.3K
# Testcase Example:  '5'
#
# Given a non-negative integer numRows, generate the first numRows of Pascal's
# triangle.
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# Input: 5
# Output:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
# 
# 

class Solution:
    def generate(self, numRows: 'int') -> 'List[List[int]]':
        if not numRows:
            return []
        result = []
        for i in range(numRows):        
            if i == 0:
                result.append([1])
            else:
                List = []
                for j in range(i + 1):
                    if j == 0:
                        List.append(result[i - 1][0])
                    else:
                        if j == i:
                            List.append(result[i - 1][i - 1])
                        else:
                            List.append(result[i - 1][j - 1] + result[i - 1][j])
                result.append(List)
        return result
