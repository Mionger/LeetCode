# 0206.reverse-linked-list  

## 题目信息  
Problem:[reverse-linked-list](https://leetcode.com/problems/reverse-linked-list/)  
Reverse a singly linked list.  
Example:  
Input: 1->2->3->4->5->NULL  
Output: 5->4->3->2->1->NULL  
Follow up:  
A linked list can be reversed either iteratively or recursively. Could you implement both?  

## 思路及总结
链表翻转也是链表常见的操作之一  
对于链表的翻转常见的有递归和迭代两种方法实现
迭代法的实现思路：不断地把原来的首元素插到新的链表的末尾  
递归法的实现思路：不用管后面部分怎么实现，只要把首元素放到最后就可以了，注意和首元素有关的next的处理  
## 代码
Language：python3  
```
Iteratively:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        old, new = ListNode(-1), ListNode(-1)
        old.next = head
        current = old.next
        while current:
            old.next = current.next
            current.next = new.next
            new.next = current
            current = old.next
        return new.next
```
```
Recursively:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        else:
            temp = self.reverseList(head.next)
            head.next.next = head
            head.next = None
            return temp
```
## 复杂度分析  
Iteratively:
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 95.91%(36ms)    

Recursively:
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 83.39%(40ms)    

## 其他  
暂无
