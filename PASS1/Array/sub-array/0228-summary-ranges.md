# 0228.summary-ranges  

## 题目信息  
Problem:[summary-ranges](https://leetcode.com/problems/summary-ranges/)  
Given a sorted integer array without duplicates, return the summary of its ranges.  
Example 1:  
Input:  [0,1,2,4,5,7]  
Output: ["0->2","4->5","7"]  
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.  
Example 2:  
Input:  [0,2,3,4,6,8,9]  
Output: ["0","2->4","6","8->9"]  
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.  

## 思路及总结
这道题和之前有一个区间插入的问题类似，只不过换了一种输出方式，总体来说还是双指针就可以解决的问题  

## 代码
Language：python3  
```
class Solution:
    def summaryRanges(self, nums):
        left, result = 0, []
        strout = lambda b, e: str(b) + "->" + str(e) if b != e else str(b)
        for right in range(1, len(nums)+1):
            if right == len(nums) or nums[right] - nums[right-1] != 1:
                result.append(strout(nums[left], nums[right-1]))
                left = right
        return result
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 90.15%    

## 其他  
暂无