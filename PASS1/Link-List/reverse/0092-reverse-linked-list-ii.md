# 0092.reverse-linked-list-ii  

## 题目信息  
Problem:[reverse-linked-list-ii](https://leetcode.com/problems/reverse-linked-list-ii/)  
Reverse a linked list from position m to n. Do it in one-pass.  
Note: 1 ≤ m ≤ n ≤ length of list.  
Example:  
Input: 1->2->3->4->5->NULL, m = 2, n = 4  
Output: 1->4->3->2->5->NULL  

## 思路及总结
这道题完全就是[在上一题](https://github.com/Mionger/LeetCode/blob/master/PASS1/Link-List/reverse/0206-reverse-linked-list.md)的基础上改编而来  
上一题式翻转整个链表，这次是给出被翻转部分的首尾序号（均为从1开始），然后翻转这部分  
唯一复杂的地方就是对后半部分不需要翻转的链表的处理  
这里用了双指针法同时寻找首位，然后立即拼接不翻转的部分  
虽然beats的比例低，但是看到题解报告中的20ms最优答案的思路和我的思路一样，提交后时间结果也相同，可能导致时间效率低的是服务器原因  

## 代码
Language：python3  
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dommy, current = ListNode(-1), ListNode(-1)
        dommy.next = head
        start, end = dommy, dommy
        
        for i in range(n - m + 1):
            end = end.next
            
        for i in range(m - 1):
            start = start.next
            end = end.next
            
        current.next = start.next
        start.next = end.next
        end.next = None
        
        while current.next:
            temp = current.next
            current.next = temp.next
            temp.next = start.next
            start.next = temp
            
        return dommy.next
```
## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 78.56%(36ms)    

## 其他  
暂无
