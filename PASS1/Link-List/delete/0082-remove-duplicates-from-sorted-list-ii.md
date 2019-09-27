# 0082.remove-duplicates-from-sorted-list-ii  

## 题目信息  
Problem:[remove-duplicates-from-sorted-list-ii](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)  
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.  
Example 1:  
Input: 1->2->3->3->4->4->5  
Output: 1->2->5  
Example 2:  
Input: 1->1->1->2->3  
Output: 2->3  

## 思路及总结
设置一个指针，维护这个指针的一个循环不变性：包括这个指针所指的元素在内的左侧所有链表结点没有值重复的结点  
这样一来每次要监测的事情有两件 :   
1. 右侧第一个结点以及其子结点是否存在  
2. 右侧第一个结点以及其子结点的值是否相等  
  
这样一来需要注意的是，如果已经检测到值相同的结点，在继续判断后续结点的值是否相同的过程结束的时候，记得不要留下一个和之前元素重复的结点  
## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        dummy = pre = ListNode(0)
        dummy.next = head
        while head and head.next:
            if head.val == head.next.val:
                while head and head.next and head.val == head.next.val:
                    head = head.next
                head = head.next
                pre.next = head
            else:
                pre = pre.next
                head = head.next
        return dummy.next
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 89.91%    

## 其他  
暂无
