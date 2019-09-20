# 0001.two-sum

## 题目信息  
Problem:[two-sum](https://leetcode.com/problems/two-sum/)  
Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
You may assume that each input would have exactly one solution, and you may not use the same element twice.  
Example:  
Given nums = [2, 7, 11, 15], target = 9,  
Because nums[0] + nums[1] = 2 + 7 = 9,  
return [0, 1].  

## 思路及总结
这道题作为leetcode的第一道题，就像高中3500词第一个是a/an，第二个是abandon一样，算是比较熟练的一个题目了（笑）  
不过这一次做的时候直接行云流水地想到了当时学习题解时候的思路，也算是一个小小的进步吧（逃）  
关于这一次刷leetcode其实是在某大厂的校招宣讲会上被打鸡血了，觉得自己要为暑期实习天做一些准备  
毕竟没人会要一个算法啥也不是的菜鸡  
好了，废话就到此为止  
这次不像以前那么盲目按照序号一个一个往下做，而是按照标签先分类复习一下简单的数据结构和基本算法，首当其冲的就是Array(数组)了  
在之前的刷题过程中就发现了有那么一些问题是和数组元素和有关的（打字起来我都觉得有点绕口）  
在思考这道题时有两种实现的思路，其一是下面代码中的字典法，其二是双指针法  
但是实际上给的输入中并没有限制数组是否有序，因此双指针法操作繁琐，遂放弃  

## 代码
Language：python3  
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i in range(len(nums)):
            if nums[i] in dic:
                return [dic[nums[i]],i]
            else:
                dic[target - nums[i]] = i
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 96.65%，且处于第一个波峰附近，应该是比较好的解法了  

## 其他  
1. 关于字典查询，in dict被用来查询某个键是否在字典中，而in dict.values()被用来查询某个值是否在字典中，但是注意字典的键不可以重复，值可以重复
