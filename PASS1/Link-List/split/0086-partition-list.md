# 0086.partition-list  

## 题目信息  
Problem:[partition-list](https://leetcode.com/problems/partition-list/)  
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.  
You should preserve the original relative order of the nodes in each of the two partitions.  
Example:  
Input: head = 1->4->3->2->5->2, x = 3  
Output: 1->2->2->4->3->5  

## 思路及总结
这道题的思路类似于将原来的整个链表在遍历的过程中根据结点的数值的大小拆分成两部分，再将这两部分拼接起来  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dommy = ListNode(-1)
        dommy.next, current, small = head, dommy, dommy
        
        while current.next:
            if current.next.val < x:
                if current == small:
                    current = current.next
                    small = small.next
                else:
                    temp = current.next
                    current.next = temp.next
                    temp.next = small.next
                    small.next = temp
                    small = small.next
            else:
                current = current.next
        
        return dommy.next
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 91.58%(36ms)  

## 其他  
暂无
  
  
