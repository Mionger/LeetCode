# 0572.subtree-of-another-tree  

## 题目信息  
Problem:[subtree-of-another-tree](https://leetcode.com/problems/subtree-of-another-tree/)  
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.  
A subtree of s is a tree consists of a node in s and all of this node's descendants.  
The tree s could also be considered as a subtree of itself.  
Example 1:  
Given tree s:  
```
     3
    / \
   4   5
  / \
 1   2
```
Given tree t:  
```
   4 
  / \
 1   2
```
Return true, because t has the same structure and node values with a subtree of s.  
Example 2:  
Given tree s:  
```
     3
    / \
   4   5
  / \
 1   2
    /
   0
```
Given tree t:  
```
   4
  / \
 1   2
```
Return false.  

## 思路及总结
之前做的树的算法题还是太少了，而且其中回溯法还占了大头，因此一下子遇到这种题会往回溯法上想，有些想当然了。  
在评论区看到了一种使用f-字符串的神来之笔。  

## 代码
Language：python3  
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        string_s = self.traverse_tree(s)
        string_t = self.traverse_tree(t)
        if string_t in string_s:
            return True
        return False
    
    
    def traverse_tree(self, s):
        if s:
            return f"#{s.val} {self.traverse_tree(s.left)} {self.traverse_tree(s.right)}"
        return None  
```

## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 94.84%(80ms)  

## 其他  
1. pyhton格式化字符串  
f-string，亦称为格式化字符串常量（formatted string literals），是Python3.6新引入的一种字符串格式化方法，该方法源于PEP 498 – Literal String Interpolation，主要目的是使格式化字符串的操作更加简便。f-string在形式上是以 f 或 F 修饰符引领的字符串（f'xxx' 或 F'xxx'），以大括号 {} 标明被替换的字段；f-string在本质上并不是字符串常量，而是一个在运行时运算求值的表达式  
