# 0485.max-consecutive-ones  

## 题目信息  
Problem:[max-consecutive-ones](https://leetcode.com/problems/max-consecutive-ones/)  
Given a binary array, find the maximum number of consecutive 1s in this array.  
Example 1:  
Input: [1,1,0,1,1,1]  
Output: 3  
Explanation: The first two digits or the last three digits are consecutive 1s.  
    The maximum number of consecutive 1s is 3.  
Note:  
The input array will only contain 0 and 1.  
The length of input array is a positive integer and will not exceed 10,000  

## 思路及总结
先从一个比较简单的子数组类问题开始  
这个问题的要求简单明了，找出数组中最长的连续个1的长度  
传统方法肯定是O(n)的遍历，除此之外在LeetCode讨论区看到了一个使用迭代器函数的解法(在下列的其他中列出)，效率确实高，但是没有普遍性  
（如果弄清这个迭代器函数的实现原理，用代码实现这个原理会不会效率更高一些）  

## 代码
Language：python3  
```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        length = 0
        max_len = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                max_len = max(length, max_len)
                length = 0
            else:
                length += 1
        return max(max_len, length)
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 77.31%，据我观察结题报告中高效率解法除了调用迭代器函数之外都是O(n)遍历，效率的差异可能和服务器状态有关？  

## 其他  
1. python迭代器函数itertools.groupby()  
函数定义如下，根据key(v)分组  
```
  intertools.groupby(iterable[, key])
```
在本题中调用的解法如下  
```
class Solution:
    def findMaxConsecutiveOnes(self, nums):
        return max(len(list(g)) if k == 1 else 0 for k, g in itertools.groupby(nums))
```
