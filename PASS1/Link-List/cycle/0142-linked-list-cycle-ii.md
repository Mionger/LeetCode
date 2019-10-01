# 0142.linked-list-cycle-ii  

## 题目信息  
Problem:[linked-list-cycle-ii](https://leetcode.com/problems/linked-list-cycle-ii/)  
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.  
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to.   
If pos is -1, then there is no cycle in the linked list.  
Note: Do not modify the linked list.  

## 思路及总结
这道题和上一题[linked-list-cycle](https://github.com/Mionger/LeetCode/edit/master/PASS1/Link-List/cycle/0141-linked-list-cycle.md)相比，区别是这道题除了判断是否有环路之外，还要判断环路的起点  
因为采用双指针法的话只能根据二者的时间差判断是否有环路，二者可能在环路上任何一个结点处相遇  
因此这里使用一个字典存储已经出现过的结点，如果再次出现，说明有环路  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        nodeDict = {}
        while head:
            try:
                if nodeDict[head]:
                    return head
            except:
                nodeDict[head] = True
            head = head.next
        return None
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 84.42%(56ms)  

## 其他  
暂无
  
  
