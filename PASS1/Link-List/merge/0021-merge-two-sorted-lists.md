# 0021.merge-two-sorted-lists  

## 题目信息  
Problem:[merge-two-sorted-lists](https://leetcode.com/problems/merge-two-sorted-lists/)  
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.  
Example:  
Input: 1->2->4, 1->3->4  
Output: 1->1->2->3->4->4  

## 思路及总结
本题的实现思路和链表的翻转类似，原址操作的话都是从一个链表插入到另一个链表  
不过要注意被插入链表为空的情况  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dommy1, dommy2 = ListNode(-1), ListNode(-1)
        dommy1.next, dommy2.next = l1, l2
        current = dommy1
        while dommy2.next:
            if current.next:
                if dommy2.next.val <= current.next.val:
                    temp = dommy2.next
                    dommy2.next = temp.next
                    temp.next = current.next
                    current.next = temp
                current = current.next
            else:
                current.next = dommy2.next
                break
        return dommy1.next
```
## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 99.52%(32ms)    


## 其他  
暂无
