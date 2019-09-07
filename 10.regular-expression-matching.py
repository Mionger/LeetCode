#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)

        dp = [[False] * (m + 1) for _ in range(n + 1)]

        dp[0][0] = True
        # dp = [[True for col in range(n + 1)] for raw in range(m + 1)]

        for i in range(1, n):
            dp[i + 1][0] = dp[i - 1][0] and p[i] == '*'

        for i in range(n):
            for j in range(m):
                if p[i] == '*':
                    dp[i + 1][j + 1] = dp[i - 1][j + 1] or dp[i][j + 1]
                    if p[i - 1] == s[j] or p[i - 1] == '.':
                        dp[i + 1][j + 1] |=  dp[i + 1][j]
                else:
                    dp[i + 1][j + 1] = dp[i][j] and (p[i] == s[j] or p[i] == '.')
    
        return dp[-1][-1]


        

