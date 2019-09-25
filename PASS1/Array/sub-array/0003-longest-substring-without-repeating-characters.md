# 0003.longest-substring-without-repeating-characters  

## 题目信息  
Problem:[max-consecutive-ones](https://leetcode.com/problems/longest-substring-without-repeating-characters/)  
Given a string, find the length of the longest substring without repeating characters.  
Example 1:  
Input: "abcabcbb"  
Output: 3  
Explanation: The answer is "abc", with the length of 3.  
Example 2:  
Input: "bbbbb"  
Output: 1  
Explanation: The answer is "b", with the length of 1.  
Example 3:  
Input: "pwwkew"  
Output: 3  
Explanation: The answer is "wke", with the length of 3.   
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.  

## 思路及总结
这道题和[max-consecutive-ones-iii](https://leetcode.com/problems/max-consecutive-ones-iii/)类似  
我的实现方式就是直接使用双指针法来解这道题，但是效果不尽人意，看了一些效率更高的解发现思路是一样的，只不过通过调用和一些隐含的信息实现“双指针”  

## 代码
Language：python3  
```
Solution:
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        S = ""
        result = 0
        for i in s:
            if i not in S:
                S += i
            else:
                S = S[S.find(i) + 1:] + i
            if len(S) > result:
                result = len(S)
        return result
```
```
MySolution:
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        N = len(s)  
        dic = {}
        result = 0
        for right in range(N):
            if s[right] in dic:
                dic[s[right]] += 1
                while dic[s[right]] > 1:
                    dic[s[left]] -= 1
                    left += 1
            else:
                dic[s[right]] = 1
            result = max(result, right - left + 1)
        
        return result
```

## 复杂度分析  
Solution:  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 92.70%    

MySolution:  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 49.53%  

## 其他  
1. python str.find()方法  
函数定义如下,可以通过修改参数beg和end的值修改查找子串的范围。本题中可以利用这个调用来更新left指针（或者隐式的左端指针）  
```
  str.find(str, beg=0, end=len(string))
```