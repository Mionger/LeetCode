# 0147.insertion-sort-list  

## 题目信息  
Problem:[insertion-sort-list](https://leetcode.com/problems/insertion-sort-list/)  
Sort a linked list using insertion sort.  
Algorithm of Insertion Sort:  
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.  
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.  
It repeats until no input elements remain.  
Example 1:  
Input: 4->2->1->3  
Output: 1->2->3->4  
Example 2:  
Input: -1->5->3->4->0  
Output: -1->0->3->4->5  

## 思路及总结
解法中有几个指针，在这里简单解释一下（发现我之前的dummy居然都拼成了dommy）  
p表示待插入位置的父结点    
cur表示目前待插入的结点  
总而言是也是类似于插入排序那样的两层循环的思路  

## 代码
Language：python3  
```
class Solution:
    def insertionSortList(self, head):
        p = dummy = ListNode(0)
        cur = dummy.next = head
        while cur and cur.next:
            val = cur.next.val
            if cur.val < val:
                cur = cur.next
                continue
            if p.next.val > val:
                p = dummy
            while p.next.val < val:
                p = p.next
            new = cur.next
            cur.next = new.next
            new.next = p.next
            p.next = new
        return dummy.next
```

## 复杂度分析  
Time Complexity:O(n^2)  
Space Complexity:O(1)  
时间复杂度方面beats 94.12%(136ms)  

## 其他  
暂无
  
  
