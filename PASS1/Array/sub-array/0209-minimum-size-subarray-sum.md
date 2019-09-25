# 0209.minimum-size-subarray-sum  

## 题目信息  
Problem:[minimum-size-subarray-sum](https://leetcode.com/problems/minimum-size-subarray-sum/)  
Given a string, find the length of the longest substring without repeating characters.  
Example 1:  
Input: "abcabcbb"  
Output: 3  
Explanation: The answer is "abc", with the length of 3.  
Example 2:  
Input: "bbbbb"  
Output: 1  
Explanation: The answer is "b", with the length of 1.  
Example 3:  
Input: "pwwkew"  
Output: 3  
Explanation: The answer is "wke", with the length of 3.   
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.  

## 思路及总结
双指针法做了之前的几道题之后也是老生常谈的问题了，相对来说已经可以算是信手拈来  
但是题干中提到的n(nlgn)的算法有点摸不到头脑，看到这个时间复杂度感觉应该是在搜索方式上优化为二分查找，但是对于无序的数组如何二分查找是个问题  
后来看到题解中的提示发现是每个left以二分查找的方式寻找满足sum>=s的子数列，操作起来比双指针复杂  

## 代码
Language：python3  
```
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        result = 0
        if not nums:
            return result
        
        left = 0
        temp = 0
        for right in range(len(nums)):
            temp += nums[right]
            while temp - nums[left] >= s:
                temp -= nums[left]
                left += 1
            if temp >= s:
                if result == 0:
                    result = right - left + 1
                else:
                    result = min(result, right - left + 1)
        return result
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 86.04%    

## 其他  
暂无