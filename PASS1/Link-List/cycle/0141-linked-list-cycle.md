# 0141.linked-list-cycle  

## 题目信息  
Problem:[linked-list-cycle](https://leetcode.com/problems/linked-list-cycle/)  
Given a linked list, determine if it has a cycle in it.  
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.  
If pos is -1, then there is no cycle in the linked list.  
Example 1:  
Input: head = [3,2,0,-4], pos = 1  
Output: true  
Explanation: There is a cycle in the linked list, where tail connects to the second node.  
Example 2:  
Input: head = [1,2], pos = 0  
Output: true  
Explanation: There is a cycle in the linked list, where tail connects to the first node.  
Example 3:  
Input: head = [1], pos = -1  
Output: false  
Explanation: There is no cycle in the linked list.  

## 思路及总结
这道题使用双指针法，一个指针为快指针另一个指针为慢指针。快指针每次移动两个结点，慢指针每次移动一个结点。  
如果链表有环路的话，快指针总有一天会追上慢指针，而且二者的速度相差一，总会有非初始状态，但是二者指向同一节点的情况。  
反之，如果链表没有环路，那么快指针会率先找到链表的尾部（指向空的部分）。

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        fast, slow = head, head
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True
        return False
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 97.64%(48ms)  

## 其他  
暂无
