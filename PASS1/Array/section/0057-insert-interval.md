# 0057.insert-interval

## 题目信息  
Problem:[insert-interval](https://leetcode.com/problems/insert-interval/)  
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).  
You may assume that the intervals were initially sorted according to their start times.  
Example 1:  
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]  
Output: [[1,5],[6,9]]  
Example 2:  
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]  
Output: [[1,2],[3,10],[12,16]]  
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].  
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.  

## 思路及总结
本题可以看作是56题merge-intervals的进阶  
因此一开始的思路就是按照稍微改动一下56题的解法，虽然也可以AC,但是用时不是很满意  
后来学到了一种left+变化+right的新解法  

## 代码
Language：python3  
```
Soultion1:
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left, right = [], []
        l, r = newInterval[0],newInterval[-1]
        
        for i in range(len(intervals)):
            if intervals[i][-1] < l:
                left.append(intervals[i])
            elif intervals[i][0] > r:
                right.append(intervals[i])
            else:
                l = min(intervals[i][0],l)
                r = max(intervals[i][-1],r)
        
        return left + [[l,r]] + right
```

```
MySoluton:
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        if len(intervals) < 2:
            return intervals
        intervals.sort(key = lambda x: x[0])
        
        result = []
        for i in intervals:
            if result:
                if i[0] <= result[-1][-1]:
                    result[-1][-1] = max(i[-1],result[-1][-1])
                else:
                    result.append(i)
            else:
                result.append(i)
               
        return result
```

## 复杂度分析
Solution1:
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 97.86%，应该是比较好的解法 

MySolution:
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 54.23%  

## 其他  
暂无
