# BRFORE  
算是被某厂校招的宣讲会打了鸡血，希望能坚持下来  

# CONTENT  
## Array  
### K-SUM
#### 题型总结  
这类题目通常会给定一个数组和一个值，让求出这个数组中两个/三个/K个值的和等于这个给定的值target  
leetcode第一题就是two-sum，对于这类题目，首先看题目要求的时间复杂度和空间复杂度是什么，其次看有没有限制条件，如要求不能有重复的子数组或者要求按照升序/降序排列等。  
解法如下：  
1. 暴力解法：最常见，但是通常会超时，只能作为备选    
2. hash-map：建立一个hash-map循环遍历一次即可  
3. two-pointers：定位两个指针根据和的大小来移动另外一个，这里设定的指针个数根据题目中K的个数来定，3Sum中可以设定3个指针，固定两个，移动另一个  

#### 题目列表  
|index|name|difficulty|
|:-----|:---:|:-----:|
|1|[two-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0001-two-sum.md)|easy|
|167|[two-sum-ii-input-array-is-sorted](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0167-two-sum-ii-input-array-is-sorted.md)|easy|
|15|[3-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0015-3-sum.md)|medium|
|16|[3-sum-closest](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0016-3-sum-closest.md)|medium|
|18|[4-sum](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0018-4-sum.md)|medium|

### SECTION
#### 题目列表
|index|name|difficulty|
|:-----|:---:|:-----:|
|56|[merge-intervals](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0056-merge-intervals.md)|medium|
|57|[insert-interval](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0057-insert-interval.md)|hard|
