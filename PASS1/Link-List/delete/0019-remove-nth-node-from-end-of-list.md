# 0019.remove-nth-node-from-end-of-list  

## 题目信息  
Problem:[remove-nth-node-from-end-of-list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  
Given a linked list, remove the n-th node from the end of list and return its head.  
Example:  
Given linked list: 1->2->3->4->5, and n = 2.  
After removing the second node from the end, the linked list becomes 1->2->3->5.  
Note:  
Given n will always be valid.  
Follow up:  
Could you do this in one pass?  

## 思路及总结
删除链表的倒数第n个结点，如果单纯的用一个指针遍历的话可能有些麻烦，毕竟本题中给出的链表节点就是最普通的单向链表  
链表的结点搜索也没办法使用二分查找等时间优化的技术，因此想要在一遍之内用一个指针的查找找到倒数第n个的点几乎是不可能的  
但是增加一个辅助指针相对来说就容易许多，先让快指针向右移动n次，再让二者同时移动，当快指针到链表末尾的结点时，慢指针子结点恰好就是待删除元素，找到的同时便于删除操作  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dommy = ListNode(-1)
        dommy.next = head
        fast, slow = dommy, dommy
        for i in range(n):
            fast = fast.next
        
        while not fast.next is None:
            fast = fast.next
            slow = slow.next
            
        slow.next = slow.next.next
    
        return dommy.next
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 87.75%    

## 其他  
暂无
