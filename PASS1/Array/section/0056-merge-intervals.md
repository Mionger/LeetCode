# 0056.merge-intervals  

## 题目信息  
Problem:[merge-intervals](https://leetcode.com/problems/merge-intervals/)  
Given a collection of intervals, merge all overlapping intervals.  
Example 1:  
Input: [[1,3],[2,6],[8,10],[15,18]]  
Output: [[1,6],[8,10],[15,18]]  
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].  
Example 2:  
Input: [[1,4],[4,5]]  
Output: [[1,5]]  
Explanation: Intervals [1,4] and [4,5] are considered overlapping.  
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.  

## 思路及总结
在开始刷数组的第三天就进入了数组的第二种类型，区间问题  
这次的是区间合并的问题，一开始默认了区间是半有序，因此在[[1,4],[0,4]]这种数据上被卡  
于是利用lambda函数顺利解决问题  

## 代码
Language：python3  
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 2:
            return intervals
        intervals.sort(key = lambda x: x[0])
        
        result = []
        for i in intervals:
            if result:
                if i[0] <= result[-1][-1]:
                    result[-1][-1] = max(result[-1][-1], i[-1])
                else:
                    result.append(i)
            else:
                result.append(i)
        return result
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 91.48%，本题的解题时间比较离散，而且此方法多次提交也有过其他70%，50%，90%的情况    

## 其他  
1. pyhton中列表有自带的sort()方法用于排序  
其中key是一个带参数的函数，参数为列表中的每个元素，返回值为比较的参照，默认值为None，按照该数据类型默认比较方式比较，如果有参数，则按照参数提供的方式比较  
常用lambda函数  
而参数reverse表示排序是否为逆序  
```
  List.sort(key = None, reverse = None)
```
