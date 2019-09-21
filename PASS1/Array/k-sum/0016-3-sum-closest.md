# 0016.3-sum-closest

## 题目信息  
Problem:[3-sum-closest](https://leetcode.com/problems/3sum-closest/)  
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.  
Return the sum of the three integers. You may assume that each input would have exactly one solution.  
Example:  
Given array nums = [-1, 2, 1, -4], and target = 1.  
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).  

## 思路及总结
这是今天做的第二个k-sum类问题，只是在[上一道题](https://github.com/Mionger/LeetCode/blob/master/PASS1/Array/k-sum/0015-3-sum.md)的基础上进行了一下小小的优化  
上一道题的解法二是有明确目标，而这道题虽然有目标，但是给出的数组的元素不一定能达到目标  
因此一开始的思路是沿用上一道题的解法一，在此基础上稍加修改  
但是提交之后虽然最后的结果也算可以，但是前方仍有一个小的波峰，应该还存在更有的解法  
于是找到了本题的解法一，解法一主要是在临界判断和搜索方式上有了更多类似剪枝的操作，从而在细节上提升性能    


## 代码
Language：python3  
```
Solution1:
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        answer = float('inf')
        for i in range(len(nums)-2):
            if i>0 and nums[i-1] == nums[i]:
                continue
            minsum = nums[i] + nums[i+1] + nums[i+2]
            maxsum = nums[i] + nums[-1] + nums[-2]
            if minsum >= target:
                if abs(minsum-target) >= abs(answer-target):
                    return answer
            if maxsum < target:
                if abs(maxsum-target) < abs(answer-target):
                    answer = maxsum
                continue
            left, right = i+1, len(nums)-1
            while left < right:
                thsum = nums[i] + nums[left] + nums[right]
                if abs(thsum - target) < abs(answer - target):
                    answer = thsum
                if thsum == target:
                    return thsum
                elif thsum < target:
                    left += 1
                    while left < len(nums)-1 and nums[left-1] == nums[left]:
                        left += 1
                else:
                    right -= 1
                    while right > i and nums[right+1] == nums[right]:
                        right -= 1
        return answer
```


```
MySoluton:
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l, r = i+1, len(nums)-1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s < target:
                    l +=1 
                    if abs(target - result) > abs(target - s):
                        result = s
                elif s > target:
                    r -= 1
                    if abs(target - result) > abs(target - s):
                        result = s
                else:
                    result = s
                    return result
        return result
```

## 复杂度分析  
Solution1:  
Time Complexity:O(n^2)  
Space Complexity:O(1)  
时间复杂度方面beats 98.34%，处于第一个波峰附近  

My Solution:  
Time Complexity:O(n^2)  
Space Complexity:O(1)  
时间复杂度方面beats 93.50%，处于第二个波峰前列，前方仍有一个小波峰  

## 其他  
暂无
