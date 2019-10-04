# 0143.reorder-list  

## 题目信息  
Problem:[reorder-list](https://leetcode.com/problems/reorder-list/)  
Given a singly linked list L: L0→L1→…→Ln-1→Ln,  
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…  
You may not modify the values in the list's nodes, only nodes itself may be changed.  
Example 1:  
Given 1->2->3->4, reorder it to 1->4->2->3.  
Example 2:  
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.  

## 思路及总结
这道题目的要求看起来貌似有点复杂，因为对于链表来说，没有index来进行这种和序号有关的排序  
但是稍微思考一下，可以把这个题转化成已经熟练掌握的三部分 :  
1. 使用快慢指针法找到链表的中点，将其分成两个部分，时间复杂度为O(n)  
2. 在O(n)的时间范围内，翻转后半部分链表  
3. 接着在O(n)的时间范围内，进行两个链表的一一合并

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head):
        if not head:
            return
        
        slow = fast = head 
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        pre, node = None, slow
        while node:
            pre, node.next, node = node, pre, node.next
    
        first, second = head, pre
        while second.next:
            first.next, first = second, first.next
            second.next, second = first, second.next
        return 
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 99.95%(80ms)  

## 其他  
暂无
  
  
