# 0002.add-two-numbers  

## 题目信息  
Problem:[add-two-numbers](https://leetcode.com/problems/add-two-numbers/)  
You are given two non-empty linked lists representing two non-negative integers.  
The digits are stored in reverse order and each of their nodes contain a single digit.  
Add the two numbers and return it as a linked list.  
You may assume the two numbers do not contain any leading zero, except the number 0 itself.  
Example:  
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)  
Output: 7 -> 0 -> 8  
Explanation: 342 + 465 = 807.  

## 思路及总结
按部就班的按照reverse的的思路对加完之后的结点一个一个串起来  
需要注意的是，结果的节点是取模之后的值，商是进位的值  
额外需要注意的就是首位相加之后需要进位的情况  

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
        result = ListNode(-1)
        current = result
        
        mod = 0
        while l1 or l2:
            if l1 and l2:
                temp = l1.val + l2.val + mod
                l1, l2 = l1.next, l2.next
            elif l1:
                temp = l1.val + mod
                l1 = l1.next
            else:
                temp = l2.val + mod
                l2 = l2.next
                
            mod = temp // 10
            temp = temp % 10
            current.next = ListNode(temp)
            current = current.next
                
        if mod != 0:
            current.next = ListNode(mod)
        
        return result.next
```
## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 79.44%(76ms)    


## 其他  
暂无
