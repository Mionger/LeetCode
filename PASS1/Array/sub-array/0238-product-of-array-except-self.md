# 0238.product-of-array-except-self  

## 题目信息  
Problem:[product-of-array-except-self](https://leetcode.com/problems/product-of-array-except-self/)  
Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].  
Example:  
Input:  [1,2,3,4]  
Output: [24,12,8,6]  
Note: Please solve it without division and in O(n).  
Follow up:  
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)  

## 思路及总结
这道题的题干加上了时间复杂度和不可以用除法的要求，一个数对应位置的乘积可以拆分成它左右两部分乘积的乘积  
可以牵强地说这道题仍然可以使用双指针的思想，只不过不管是同时确定左侧和右侧的乘积还是先确定一个再一边确定另一个同时确定最终结果，都需要遍历两次  

## 代码
Language：python3  
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1]*len(nums)
        R = 1
        
        for i in range(1,len(nums)):
            result[i] = result[i-1]*nums[i-1]
            
        for i in range(len(nums)-1,-1,-1):
            result[i] = result[i]*R
            R *= nums[i]
            
        return result
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 98.13%    

## 其他  
暂无