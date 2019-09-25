# 1004.max-consecutive-ones-iii  

## 题目信息  
Problem:[max-consecutive-ones-iii](https://leetcode.com/problems/max-consecutive-ones-iii/)  
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.  
Return the length of the longest (contiguous) subarray that contains only 1s.   
Example 1:  
Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2  
Output: 6  
Explanation:  
[1,1,1,0,0,1,1,1,1,1,1]  
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.  
Example 2:  
Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3  
Output: 10  
Explanation:  
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]  
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.   
Note:  
1 <= A.length <= 20000  
0 <= K <= A.length  
A[i] is 0 or 1  

## 思路及总结
本题为[max-consecutive-ones](https://leetcode.com/problems/max-consecutive-ones/)的扩展，上一道题只是单纯的遍历查找最长序列，而这道题在此基础上进行了一下变化  
允许最多将K个0翻转为1，再求在这个条件下的符合条件的最长的连续个“1”的长度  
其实这道题一开始想用动态规划来解决，但是复杂度将会是O(n^2)  
使用双指针法来解决的话，只需要遍历一遍，虽然时间复杂度是O(n^2)，但是相当于动态规划相当于已经剪枝完毕  
双指针法的具体的使用方式如下:  

1. 用left和right两个指针指向目前选取判断部分的左右两端，用zero记录已经翻转的0的数量  
2. 其中right指针是从左往右依次遍历，判断每个新值是0还是1
3. 如果right的新值是1，则继续向右移动，如果是0，则翻转成1  
4. 如果zero>K(最大可翻转数量)，向右移动左指针，直到将一个从0翻转的1再翻转回0  
5. 每次right和left均稳定的时候，比较目前最大值和left与right之间划定的长度的大小，保留最大值    
  
但是提交后的结果显示只是在第二个波峰的前部，之前还有一个波峰，说明不是最优算法  
查看第一个波峰前部的代码之后，发现其大体实现思路相同，不过唯一的区别就是对K和最大值的操作，将时间复杂度降为O(n)  
这个解法的left与right并不是实际的最长连续的1串的左右端，而是二者移动的差值始终是维持在目前的最长串的状态  

## 代码
Language：python3  
```
Solution:
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        left = 0
        N = len(A)
        for right in range(N):
            K -= 1 - A[right]
            if K < 0:
                K += 1 - A[left]
                left += 1
        return right - left + 1
```

```
MySolution:
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        left = 0
        zero = 0
        maxLen = 0
        for right in range(len(A)):
            if A[right] == 0:
                zero += 1
            while zero > K:
                if A[left] == 0:
                    zero -= 1
                left += 1
            maxLen = max(maxLen, right - left + 1)
        return maxLen
```

## 复杂度分析  
MySolution:  
Time Complexity:O(n)  
Space Complexity:O(1)  
时间复杂度方面beats 97.48%，位于第一个波峰前部，性能比较满意  
MySolution:  
Time Complexity:O(n^2)  
Space Complexity:O(1)  
时间复杂度方面beats 70.47%，只是在第二个波峰的前部  

## 其他  
暂无
