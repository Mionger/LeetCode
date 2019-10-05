# 0020.valid-parentheses  

## 题目信息  
Problem:[valid-parentheses](https://leetcode.com/problems/valid-parentheses/)  
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.  
An input string is valid if:  
Open brackets must be closed by the same type of brackets.  
Open brackets must be closed in the correct order.  
Note that an empty string is also considered valid.  
Example 1:  
Input: "()"  
Output: true  
Example 2:  
Input: "()[]{}"  
Output: true  
Example 3:  
Input: "(]"  
Output: false  
Example 4:  
Input: "([)]"  
Output: false  
Example 5:  
Input: "{[]}"  
Output: true  

## 思路及总结
理解栈的概念最老生常谈的一道题，用hash法标记好对应的括号  

## 代码
Language：python3  
```
class Solution:
    def isValid(self, s: str) -> bool:
        S = []
        match = {')':'(',']':'[','}':'{'}
        for i in s:
            if i in match:
                if not (S and S.pop() == match[i]):
                    return False
            else:
                S.append(i)
        return not S
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 94.32%(32ms)    

## 其他  
暂无
