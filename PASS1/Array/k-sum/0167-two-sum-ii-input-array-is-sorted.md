# 0167.two-sum-ii-input-array-is-sorted

## 题目信息  
Problem:[two-sum-ii-input-array-is-sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)  
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.  
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.  
Note:  
Your returned answers (both index1 and index2) are not zero-based.  
You may assume that each input would have exactly one solution and you may not use the same element twice.  
Example:  
Input: numbers = [2,7,11,15], target = 9  
Output: [1,2]  
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.  

## 思路及总结  
这道题作为[two-sum](https://leetcode.com/problems/two-sum/)的姊妹题，限定了数组有序之后，简化了双指针法的操作复杂度，因此当仁不让地选择了双指针法  
双指针法对于之前的字典法（或者说hash法）的优点在于节约了空间复杂度  
二者的最坏情况均是遍历一遍数组才找到  

## 代码
Language：python3  
```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers) - 1
        while i < j:
            if numbers[i] + numbers[j] > target:
                j -= 1
            elif numbers[i] + numbers[j] < target:
                i += 1
            else:
                return [i + 1, j + 1]
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 95.94%，且处于第一个波峰附近，应该是比较好的解法了  

## 其他  
1. （不确定）双指针法和有序数组绑定（存疑，待以后的做题验证）  
2. 同时做题时要注意输出的要求格式，这次的序号不是以0开头的  
