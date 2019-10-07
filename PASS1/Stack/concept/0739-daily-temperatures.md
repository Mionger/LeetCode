# 0739.daily-temperatures  

## 题目信息  
Problem:[daily-temperatures](https://leetcode.com/problems/daily-temperatures/)  
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.  
If there is no future day for which this is possible, put 0 instead.  
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].  
Note: The length of temperatures will be in the range [1, 30000].  
Each temperature will be an integer in the range [30, 100].  

## 思路及总结
这个题目本质上解决的问题是寻找一个元素后离他最近的比他大的元素的距离  
栈是按照从热到冷的顺序保存目前还没找到更大元素的数的index  
同时维持栈的如下两个性质：  
1. 以栈中元素为序号对应的元素数值从栈顶到栈底单调递增  
2. 栈中元素从栈顶到栈底单调递减  
  
这样一来就保证了栈顶元素永远是之前一个数值更大的元素的序号  

## 代码
Language：python3  
```
class Solution:
    def dailyTemperatures(self, T):
        result = [0] * len(T)
        stack = [] 
        for i in range(len(T)-1, -1, -1):
            while stack and T[i] >= T[stack[-1]]:
                stack.pop()
            if stack:
                result[i] = stack[-1] - i
            stack.append(i)
        return result
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 90.91%(524ms)    

## 其他  
暂无
