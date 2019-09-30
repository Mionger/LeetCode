# 0023.merge-k-sorted-lists  

## 题目信息  
Problem:[merge-k-sorted-lists](https://leetcode.com/problems/merge-k-sorted-lists/)  
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.  
Example:  
```
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6 
```

## 思路及总结
首先面对这道题的时候，我的第一反应是拿一个空链表作为result，遍历给定的数组，将每个数组和result两两合并  
但是刚要动手的时候突然反应过来，这种解法很好想，但是对应的自然时间复杂度很高，假设有k个有序链表，几乎是O(nk^2)  
接下来对解法进行时间复杂度上的优化，想到了利用分治法进行优化，递归调用，这样一来时间复杂度降到了O(nklgk)  
利用这种思路实现的代码顺利AC，但是结果不尽人意，beats只有30%左右  
上网查阅之后发现还有更简单的思路：利用最小堆，将每个列表的最小元素放入最小堆中，从最小堆选取最小元素，再将被选取元素的next放入最小堆中，直到所有结点都进入result链表    
最小堆法每次插入的复杂度是lgk，而一共需要插入nk个结点，所以总的时间复杂度是O(nklgk)  

## 代码
Language：python3  
```
Divide and Conquer:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # 迭代
        # 类似于归并排序
        l = len(lists)
        if l == 2:
            l1, l2 = lists[0], lists[1]
            if l1 and l2:
                h1, h2 = ListNode(-1), ListNode(-1)
                h1.next, h2.next, current = l1, l2, h1
                while h2.next:
                    if current.next:
                        if current.next.val > h2.next.val:
                            temp = h2.next
                            h2.next = temp.next
                            temp.next = current.next
                            current.next = temp
                        current = current.next
                    else:
                        current.next = h2.next
                        break
                return h1.next
            elif l1:
                return l1
            else:
                return l2
        elif l == 1:
            return lists[0]
        elif l == 0:
            return None
        else:
            l1 = self.mergeKLists(lists[:l//2])
            l2 = self.mergeKLists(lists[l//2:])
            return self.mergeKLists([l1, l2])
```
```
Heap:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        from heapq import heappush, heappop, heapreplace, heapify
        heap = [(head.val, i, head) for i,head in enumerate(lists) if head]
        heapify(heap)
        dummy = ListNode(0)
        node = dummy
        while heap != []:
            val, i, n = heap[0]
            if not n.next: # exhausted one linked-list
                heappop(heap)
            else:
                heapreplace(heap, (n.next.val, i, n.next)) # recycling tie-breaker i guarantees uniqueness
            node.next = n    
            node = node.next
        return dummy.next
```
## 复杂度分析  
Divide and Conquer:
Time Complexity:O(nklgk)  
Space Complexity:O(lgk)  
时间复杂度方面beats 34.14%(152ms)  

Heap:
Time Complexity:O(nklgk)  
Space Complexity:O(k)  
时间复杂度方面beats 99.99%(72ms)  

## 其他  
1. 类似比较或者排序的时候不要忘了堆排序这种效率比较高的实现方法  
2. python中提供了封装好的堆的数据结构供直接调用，常见操作如下  
```
引入声明：
from heapq import heappush, heappop, heapreplace, heapify

heapq.heappush(heap, item) : 
往堆中插入一个值，同时要保持为最小堆。

heapq.heappop(heap) : 
返回堆中的最小值，并把它从堆中删除，同时保持为最小堆；
如果堆为空，发生 IndexError。直接通过heap[0]可以获取最小值并不从堆中把它删除。

heapq.heappushpop(heap, item) : 
向堆中插入值后再弹出堆中的最小值，这个函数的速度比直接使用heappush() 和heappop()的效率更加高。

heapq.heapreplace(heap, item) : 
弹出和返回堆中的最小值再插入一个新的值。堆的大小没有改变。如果堆为空，产生 IndexError。
这一个操作也比直接使用heappush() 和heappop()的效率更加高，尤其适合使用在固定堆大小不变的情况。
与上一个函数相比，这个函数返回的值可能要比将要插入到堆的值大。

heapq.heapify(x) : 
将一个list转为最小堆，线性时间复杂度，O(n).
```
