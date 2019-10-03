# 0725.split-linked-list-in-parts  

## 题目信息  
Problem:[split-linked-list-in-parts](https://leetcode.com/problems/split-linked-list-in-parts/)  
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".  
The length of each part should be as equal as possible: no two parts should have a size differing by more than 1.  
This may lead to some parts being null.
The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.  
Return a List of ListNode's representing the linked list parts that are formed.  
Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]  
Example 1:  
Input:  
root = [1, 2, 3], k = 5  
Output: [[1],[2],[3],[],[]]  
Explanation:  
The input and each element of the output are ListNodes, not arrays.  
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.  
The first element output[0] has output[0].val = 1, output[0].next = null.  
The last element output[4] is null, but it's string representation as a ListNode is [].  
Example 2:  
Input:  
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3  
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]  
Explanation:  
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.  
Note:  
The length of root will be in the range [0, 1000].  
Each value of a node in the input will be an integer in the range [0, 999].  
k will be an integer in the range [1, 50].  

## 思路及总结
一开始看到这个题目的时候，顿时懵了，链表没办法直接求具体的长度，为了求长度先O(n)遍历一圈，是不是有点浪费时间  
后来思前想后没有啥更好的办法，只能按照这个思路硬着头皮做下去，但是结果还是确实比较满意  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        cur = root
        N = 0
        while cur:
            cur = cur.next
            N += 1
        
        num = N // k
        mod = N % k
        cur = root
        result = []
        for i in range(k):
            head = cur
            for j in range(num + (i < mod) - 1):
                if cur:
                    cur = cur.next
            if cur:
                cur.next, cur = None, cur.next
            result.append(head)
        return result
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 90.99%(40ms)  

## 其他  
暂无
  
  
