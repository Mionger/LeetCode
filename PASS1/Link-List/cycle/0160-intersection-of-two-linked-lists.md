# 0160.intersection-of-two-linked-lists  

## 题目信息  
Problem:[intersection-of-two-linked-lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)  
Write a program to find the node at which the intersection of two singly linked lists begins.  
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3  
Output: Reference of the node with value = 8  
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).  
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5].  
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.  

## 思路及总结
思路清晰地直接使用HASH法解决

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        dic = {}
        while headA:
            dic[headA] = True
            headA = headA.next
            
        while headB:
            if headB in dic:
                return headB
            headB = headB.next
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 95.81%(180ms)  

## 其他  
暂无
  
  
