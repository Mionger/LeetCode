# 0078.subsets  

## 题目信息  
Problem:[subsets](https://leetcode.com/problems/subsets/)  
Given a set of distinct integers, nums, return all possible subsets (the power set).  
Note: The solution set must not contain duplicate subsets.  
Example:  
Input: nums = [1,2,3]  
Output:  
[  
  [3],  
  [1],  
  [2],  
  [1,2,3],  
  [1,3],  
  [2,3],  
  [1,2],  
  []  
]  

## 思路及总结
最开始看这道题的名称决定做的时候以为是和子串子数列那种的sub-array类型问题，但是实际做了才发现就是一个组合问题  
组合数学课上常见（甚至高中数学课上常见）的问题之一，果断用写计组/数字逻辑时常用的位信号表示存在与否，效率还算可以  

## 代码
Language：python3  
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        if not nums:
            return result
        N = len(nums)
        for i in range(1,2 ** N):
            temp = []
            for j in range(N):
                if i & 2 ** j:
                    temp.append(nums[j])
            result.append(temp)
        return result
```

## 复杂度分析  
MySolution:  
Time Complexity:O(2^n)  
Space Complexity:O(2^n)  
时间复杂度方面beats 92.66%，虽然和回溯法一样同为指数时间复杂度，但是位运算在找各个情况的时候比回溯法更省时间  

## 其他  
暂无