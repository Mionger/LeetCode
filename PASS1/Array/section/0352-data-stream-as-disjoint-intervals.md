# 0352.data-stream-as-disjoint-intervals

## 题目信息  
Problem link:[data-stream-as-disjoint-intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)  
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.  
For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:  
[1, 1]  
[1, 1], [3, 3]  
[1, 1], [3, 3], [7, 7]  
[1, 3], [7, 7]  
[1, 3], [6, 7]  
Follow up:  
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?  

## 思路及总结
本题可以看作是57题[insert-intervals](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/section/0057-insert-interval.md)的进阶  
57题是给出已有的一个有序区间列表，插入一个区间，再合并区间  
而本题可以看成是不断地插入数字（单个数字val可视为区间[val, val]），动态生成有序区间列表  
一开始的思路是每次插入新数字的时候，遍历整个有序区间，分析好所有可能的合并的情况，在合并后返回，否则接着查询  
虽然这种思路实现的代码也可以AC，但是效率有点低，优化搜索方案后，将依次遍历修改为二分查找，优化后算法的效率大幅提高 

## 代码
Language：python3  
```
MySoultion1:(efficient)
class SummaryRanges(object):
    def __init__(self):
        self.result = []

    def addNum(self, val):
        if len(self.result) < 1:
            self.result.append([val, val])
        
        l, r = 0, len(self.result) - 1
        i = (l + r) // 2
        while l <= r:
            i = (l + r) // 2
            if val >= self.result[i][0] and val <= self.result[i][-1]:
                return
            elif val < self.result[i][0]:
                r = i - 1
            else:
                l = i + 1

        # left
        if self.result[i][0] - 1 > val:
            if i > 0:
                if self.result[i - 1][-1] + 1 < val:
                    self.result.insert(i, [val, val])
                    return
                elif self.result[i - 1][-1] + 1 == val:
                    self.result[i - 1][-1] = val
                    return
                else:
                    return
            else:
                self.result.insert(0, [val, val])
                return
        elif self.result[i][0] - 1 == val:
            if i > 0:
                if self.result[i - 1][-1] + 1 == val:
                    self.result[i - 1][-1] = self.result[i][-1]
                    self.result.pop(i)
                    return
                else:
                    self.result[i][0] = val
                    return
            else:
                self.result[i][0] = val
                return
        # right
        elif self.result[i][-1] + 1 < val:
            if i < len(self.result) - 1 :
                if self.result[i + 1][0] - 1 > val:
                    self.result.insert(i + 1, [val, val])
                    return
                elif self.result[i + 1][0] - 1 == val:
                    self.result[i + 1][0] = val
                    return
                else:
                    return
            else:
                self.result += [[val, val]]
                return
        elif self.result[i][-1] + 1 == val:
            if i < len(self.result) - 1:
                if self.result[i + 1][0] - 1 == val:
                    self.result[i][-1] = self.result[i + 1][-1]
                    self.result.pop(i + 1)
                    return
                else:
                    self.result[i][-1] = val
                    return
            else:
                self.result[i][-1] = val
                return
                
    def getIntervals(self):
        return self.result
```

```
MySoluton2:
class SummaryRanges(object):
    def __init__(self):
        self.result = []

    def addNum(self, val):
        if len(self.result) < 1:
            self.result.append([val, val])
        
        for i in range(len(self.result)):
            # single
                # start
            if self.result[i][0] - 1 > val and i == 0:
                self.result.insert(0, [val, val])
                return
                # end
            elif self.result[i][-1] + 1 < val and i == len(self.result) - 1:
                self.result += [[val, val]]
                return
                # mid
            elif self.result[i][0] - 1 > val and self.result[i - 1][-1] + 1 < val:
                self.result.insert(i, [val, val])
                return
        
            # left-
                # start
            elif self.result[i][0] - 1 == val and i == 0:
                self.result[i][0] = val
                return
                #else
            elif self.result[i][0] - 1 == val and self.result[i - 1][-1] + 1 < val:
                self.result[i][0] = val
                return
          
            # -right
                # end
            elif self.result[i][-1] + 1 == val and i == len(self.result) - 1:
                self.result[i][-1] = val
                return
                # else
            elif self.result[i][-1] + 1 == val and self.result[i + 1][0] - 1 > val:
                self.result[i][-1] = val
                return
        
            # -connect-
            elif self.result[i][-1] + 1 == val and self.result[i + 1][0] - 1 == val:
                self.result[i][-1] = self.result[i+1][-1]
                self.result.pop(i + 1)
                return
        
    def getIntervals(self):
        return self.result
```

## 复杂度分析
MySolution1:
Time Complexity:O(lgn)(176ms)  
Space Complexity:O(n)  
时间复杂度方面beats 93.51%，应该是比较好的解法 

MySolution2:
Time Complexity:O(n)(260ms)  
Space Complexity:O(n)  
时间复杂度方面beats 12.43%  

## 其他  
1. 有时候优化搜索方式可以大大降低算法的时间复杂度
