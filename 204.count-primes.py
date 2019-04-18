#
# @lc app=leetcode id=204 lang=python3
#
# [204] Count Primes
# https://leetcode.com/problems/count-primes/description/
#
# algorithms
# Easy (28.55%)
# Total Accepted:    226.2K
# Total Submissions: 789.4K
# Testcase Example:  '10'
#
# Count the number of prime numbers less than a non-negative number, n.
# 
# Example:
# Input: 10
# Output: 4
# Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
# 
# 
#
class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1 :
            return 0
        n -= 1
        IsPrime = [True]*(n + 1)
        IsPrime[1] = False
        result = n - 1
        for i in range(2,int(n ** 0.5) + 1):
            if IsPrime[i]:
                for j in range(i*i, n + 1, i):
                    if IsPrime[j]:
                        IsPrime[j] = False
                        result -= 1
        return result

