# 0503.next-greater-element-ii  

## 题目信息  
Problem:[next-greater-element-ii](https://leetcode.com/problems/next-greater-element-ii/)  
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element.  
The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.  
If it doesn't exist, output -1 for this number.  
Example 1:  
Input: [1,2,1]  
Output: [2,-1,2]  
Explanation: The first 1's next greater number is 2;  
The number 2 can't find next greater number;  
The second 1's next greater number needs to search circularly, which is also 2.  
Note: The length of given array won't exceed 10000.  

## 思路及总结
这道题的实现思路和[daily-temperatures](https://github.com/Mionger/LeetCode/blob/master/PASS1/Stack/concept/0739-daily-temperatures.md)类似  
但是注意有两点区别:  
1. 本题中要求操作的对象不是一个简单的列表，而是一个循环列表  
2. 本题中不是要求元素序号之间的关系，而是要直接求数值之间的关系  
  
因此，本题的栈中直接保存数值就可以。  
对于循环列表的操作通常有两种处理方法：其一是扩展双倍的空间，其二是进行两次操作。  

## 代码
Language：python3  
```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        res = [-1] * len(nums)
        stack = []
        
        for idx, val in enumerate(nums):
            while stack and stack[-1][0] < val:
                _, tidx = stack.pop()
                res[tidx] = val
            stack.append((val, idx))
            
        for idx, val in enumerate(nums):
            while stack and stack[-1][0] < val:
                _, tidx = stack.pop()
                res[tidx] = val

        return res
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 97.30%(232ms)    

## 其他  
暂无
