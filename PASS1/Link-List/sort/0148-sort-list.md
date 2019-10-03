# 0148.sort-list  

## 题目信息  
Problem:[sort-list](https://leetcode.com/problems/sort-list/)  
Sort a linked list in O(n log n) time using constant space complexity.  
Example 1:  
Input: 4->2->1->3  
Output: 1->2->3->4  
Example 2:  
Input: -1->5->3->4->0  
Output: -1->0->3->4->5  

## 思路及总结
这道题的要求有些严苛，要求O(nlgn)的时间复杂度和O(1)的空间复杂度  
但是实际上能达到这个时间复杂度的，基本上都不能在链表上实现:  
1. 归并排序涉及到递归  
2. 堆排序要维护堆  
3. 快速排序要需要序号  
  
所以这里只取时间复杂度，忽略空间复杂度的要求（甚至其他一栏中的一种投机取巧的方法也不满足空间复杂度的要求）  

## 代码
Language：python3  
```
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: 
            return head
        p1 = head
        p2 = head
        left_tail = None
        while(p2):
            left_tail = p1
            p1 = p1.next
            p2 = p2.next
            if p2: p2 = p2.next
        left_tail.next = None
        p_left = head
        p_right = p1
        p_left = self.sortList(p_left)
        p_right = self.sortList(p_right)
        head = None
        tail = head
        while(p_left and p_right):
            if p_left.val < p_right.val:
                if tail is None:
                    tail = head = p_left
                else:
                    tail.next = p_left
                    tail = p_left
                p_left = p_left.next
            else:
                if tail is None:
                    tail = head = p_right
                else:
                    tail.next = p_right
                    tail = p_right
                p_right = p_right.next
        if p_left: 
            tail.next = p_left
        if p_right: 
            tail.next = p_right
        return head
```

## 复杂度分析  
Time Complexity:O(nlgn)  
Space Complexity:O(1)  
时间复杂度方面beats 83.53%(204ms)  

## 其他  
1. 这里有种比较投机取巧，beats99.38%(88ms)的方法  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        
        node = head
        ls = []
        
        while node:
            ls.append(node.val)
            node = node.next
            
        ls.sort()
        
        root = head
        
        for val in ls:
            head.val = val
            head = head.next
            
        return root
```
  
  
