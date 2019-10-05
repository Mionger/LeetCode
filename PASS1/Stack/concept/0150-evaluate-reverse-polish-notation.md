# 0150.evaluate-reverse-polish-notation  

## 题目信息  
Problem:[evaluate-reverse-polish-notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)  
Evaluate the value of an arithmetic expression in Reverse Polish Notation.  
Valid operators are +, -, *, /. Each operand may be an integer or another expression.  
Note:  
Division between two integers should truncate toward zero.  
The given RPN expression is always valid.  
That means the expression would always evaluate to a result and there won't be any divide by zero operation.  
Example 1:  
Input: ["2", "1", "+", "3", "*"]  
Output: 9  
Explanation: ((2 + 1) * 3) = 9  
Example 2:  
Input: ["4", "13", "5", "/", "+"]  
Output: 6  
Explanation: (4 + (13 / 5)) = 6  
Example 3:  
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]  
Output: 22  
Explanation:  
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5  
= ((10 * (6 / (12 * -11))) + 17) + 5  
= ((10 * (6 / -132)) + 17) + 5  
= ((10 * 0) + 17) + 5  
= (0 + 17) + 5  
= 17 + 5  
= 22  

## 思路及总结
题目的思路不难想，不过要注意一些特殊情况  
对于如下的情况，python和leetcode理解的答案不一样  
```
["2","-1","+","-3","/"]
```
leetcode给出的答案，也就是正常人的思路是0,但是python直接用//运算计算出来的结果是-1  

## 代码
Language：python3  
```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operator = ["+", "-", "*", "/"]
        s = []
        for i in tokens:
            if i in operator:
                a, b = s.pop(), s.pop()
                if i == "+":
                    s.append(b + a)
                elif i == "-":
                    s.append(b - a)
                elif i == "*":
                    s.append(b * a)
                else:
                    if b*a < 0 and b % a != 0:
                        s.append(b//a+1)
                    else:
                        s.append(b//a)
            else:
                s.append(int(i))
        return s.pop()
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 95.72%(72ms)    

## 其他  
暂无
