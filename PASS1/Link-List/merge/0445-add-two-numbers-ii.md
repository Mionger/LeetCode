# 0002.add-two-numbers  

## 题目信息  
Problem:[add-two-numbers-ii](https://leetcode.com/problems/add-two-numbers-ii/)  
You are given two non-empty linked lists representing two non-negative integers.  
The digits are stored in reverse order and each of their nodes contain a single digit.  
Add the two numbers and return it as a linked list.  
You may assume the two numbers do not contain any leading zero, except the number 0 itself.  
Example:  
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  
Output: 7 -> 0 -> 8  
Explanation: 342 + 465 = 807.  

## 思路及总结
首先注意的是这道题给出的数字的链表是按照正常数字从左到右的顺序给出的，返回的结果也要求按照这个顺序  
那么就相当于利用链表翻转+[add-two-numbers](https://github.com/Mionger/LeetCode/blob/master/PASS1/Link-List/merge/0002-add-two-numbers.md)+链表翻转  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dommy1, dommy2, old = ListNode(-1), ListNode(-1), ListNode(-1)
        
        old.next = l1
        while old.next:
            temp = old.next
            old.next = temp.next
            temp.next = dommy1.next
            dommy1.next = temp
            
        old.next = l2
        while old.next:
            temp = old.next
            old.next = temp.next
            temp.next = dommy2.next
            dommy2.next = temp
            
        result = ListNode(-1)
        current, h1, h2 = result, dommy1.next, dommy2.next
        
        mod = 0
        while h1 or h2:
            if h1 and h2:
                temp = h1.val + h2.val + mod
                h1, h2 = h1.next, h2.next
            elif h1:
                temp = h1.val + mod
                h1 = h1.next
            else:
                temp = h2.val + mod
                h2 = h2.next
                
            mod = temp // 10
            temp = temp % 10
            current.next = ListNode(temp)
            current = current.next
                
        if mod != 0:
            current.next = ListNode(mod)
        
        old.next = result.next
        result.next = None
        while old.next:
            temp = old.next
            old.next = temp.next
            temp.next = result.next
            result.next = temp
        
        return result.next
```
## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 77.46%(80ms)    


## 其他  
暂无
