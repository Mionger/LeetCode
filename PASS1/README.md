# INDEX
- [BRFORE](#brfore)
- [CONTENT](#content)
  * [Array](#array)
    + [K-SUM](#k-sum)
      - [题型总结](#%E9%A2%98%E5%9E%8B%E6%80%BB%E7%BB%93)
      - [题目列表](#%E9%A2%98%E7%9B%AE%E5%88%97%E8%A1%A8)
    + [SECTION](#section)
      - [题型总结](#%E9%A2%98%E5%9E%8B%E6%80%BB%E7%BB%93-1)
      - [题目列表](#%E9%A2%98%E7%9B%AE%E5%88%97%E8%A1%A8-1)
    + [SUB-ARRAY](#sub-array)
      - [题型总结](#%E9%A2%98%E5%9E%8B%E6%80%BB%E7%BB%93-2)
      - [题目列表](#%E9%A2%98%E7%9B%AE%E5%88%97%E8%A1%A8-2)
    + [MATH](#math)
      - [题型总结](#%E9%A2%98%E5%9E%8B%E6%80%BB%E7%BB%93-3)
      - [题目列表](#%E9%A2%98%E7%9B%AE%E5%88%97%E8%A1%A8-3)
  * [Link-List](#link-list)
    + [DELETE](#delete)
      - [题型总结](#%E9%A2%98%E5%9E%8B%E6%80%BB%E7%BB%93-4)
      - [题目列表](#%E9%A2%98%E7%9B%AE%E5%88%97%E8%A1%A8-4)

# BRFORE
算是被某厂校招的宣讲会打了鸡血，希望能坚持下来  

# CONTENT  
## Array  
### K-SUM
#### 题型总结  
这类题目通常会给定一个数组和一个值，让求出这个数组中两个/三个/K个值的和等于这个给定的值target  
leetcode第一题two-sum就是这类问题，对于这类题目，首先看题目要求的时间复杂度和空间复杂度是什么，其次看有没有限制条件，如要求不能有重复的子数组或者要求按照升序/降序排列等。  
常见解法：  
1. 暴力解法：最常见，但是通常会超时，只能作为备选    
2. hash-map：建立一个hash-map循环遍历一次即可  
3. two-pointers：定位两个指针根据和的大小来移动另外一个，这里设定的指针个数根据题目中K的个数来定，3Sum中可以设定3个指针，固定两个，移动另一个  
4. 优化搜索方式（如从依次遍历优化为二分查找等）往往会有比较大的性能提升
#### 题目列表  
|index|name|difficulty|
|:--:|:--:|:--:|
|1|[two-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0001-two-sum.md)|easy|
|167|[two-sum-ii-input-array-is-sorted](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0167-two-sum-ii-input-array-is-sorted.md)|easy|
|15|[3-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0015-3-sum.md)|medium|
|16|[3-sum-closest](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0016-3-sum-closest.md)|medium|
|18|[4-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0018-4-sum.md)|medium|

### SECTION
#### 题型总结
数组类型常见的题型之一，这类题目通常会给定一个区间的列表，然后判断之间的交叉关系，判断是否是无交叉区间或者简化成无交叉区间的形式  
这类题目往往还有比较实际的意义，比如说可以用于安排日程时间等等，可以被包装成很多种情形，注意化归成最原始的模型  
常见解法：  
1. 对列表按照区间首元素等排序处理  
2. 在相邻区间的尾元素和首元素之间判断临界条件  
3. 可以通过优化搜索方式进行性能提升  
#### 题目列表
|index|name|difficulty|
|:--:|:--:|:--:|
|56|[merge-intervals](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0056-merge-intervals.md)|medium|
|57|[insert-interval](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0057-insert-interval.md)|hard|
|352|[data-stream-as-disjoint-intervals](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0352-data-stream-as-disjoint-intervals.md)|hard|

### SUB-ARRAY
#### 题型总结
这类题目通常会在一个包含多个子数组的数组中，求和/积，最大最小等。形式有很多种，例如求一个数组中和最小的子数组，或者积最小的子数组。  
常见解法 :  
1. 双指针法  
2. 滑窗法  
#### 题目列表
|index|name|difficulty|
|:--:|:--:|:--:|
|485|[max-consecutive-ones](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0485-max-consecutive-ones.md)|easy|
|1004|[max-consecutive-ones-iii](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0485-max-consecutive-ones-iii.md)|medium|
|3|[longest-substring-without-repeating-characters](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0003-longest-substring-without-repeating-characters.md)|medium|
|209|[minimum-size-subarray-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0209-minimum-size-subarray-sum.md)|medium|
|238|[product-of-array-except-self](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0238-product-of-array-except-self.md)|medium|
|239|[sliding-window-maximum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0239-sliding-window-maximum.md)|hard|
|228|[summary-ranges](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/sub-array/0228-summary-ranges.md)|medium|
### MATH
#### 题型总结
暂无  
#### 题目列表
|index|name|difficulty|
|:--:|:--:|:--:|
|78|[subsets](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/math/0078-subsets.md)|medium|

## Link-List  
### DELETE  
#### 题型总结
对于单向链表的删除问题，最主要的有以下两点:
1. 判断链表是否结束
2. 预留该节点的父节点，以便进行操作
  
因此这类问题一般采用双指针法，慢的指针通常指向被删除节点的父节点，但是双指针法尤其要注意对于循环不变式和链表是否结束的把握  
#### 题目列表
|index|name|difficulty|
|:--:|:--:|:--:|
|19|[remove-nth-node-from-end-of-list](https://github.com/Mionger/LeetCode/blob/master/PASS1/Link-List/delete/0019-remove-nth-node-from-end-of-list.md)|medium|
|82|[remove-duplicates-from-sorted-list-ii](https://github.com/Mionger/LeetCode/blob/master/PASS1/Link-List/delete/0082-remove-duplicates-from-sorted-list-ii.md)|medium|
### REVERSE  
#### 题型总结
暂无
#### 题目列表
|index|name|difficulty|
|:--:|:--:|:--:|
|206|[reverse-linked-list](https://github.com/Mionger/LeetCode/blob/master/PASS1/Link-List/reverse/0206-reverse-linked-list.md)|easy|
