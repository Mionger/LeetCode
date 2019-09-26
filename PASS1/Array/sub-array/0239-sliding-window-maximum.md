# 0239.sliding-window-maximum  

## 题目信息  
Problem:[sliding-window-maximum](https://leetcode.com/problems/sliding-window-maximum/)  
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.  
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.  
Example:  
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3  
Output: [3,3,5,5,6,7]  
Explanation:  
```
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
Note:  
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.  
Follow up:  
Could you solve it in linear time?  

## 思路及总结
本道题衍生出来的方法和双指针法几乎可以并列是子数组问题的两大法宝  
本题的难点在于维护window时的细节，之前只是拘泥于元素间的大小关系的维护，忽略的坐标过前的可能早就离开了window  

## 代码
Language：python3  
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        result = []
        q = []
        for right in range(len(nums)):
            while q and nums[q[-1]] < nums[right]:
                q.pop(-1)
            q += [right]
            
            if right - q[0] >= k:
                q.pop(0)
            if right + 1 >= k:
                result.append(nums[q[0]])
            
        return result
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 90.64%,位于第一波峰前列    

## 其他  
暂无