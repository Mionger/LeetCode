# 0226.invert-binary-tree  

## 题目信息  
Problem:[invert-binary-tree](https://leetcode.com/problems/invert-binary-tree/)  
Invert a binary tree.  
Example:  
Input:  
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
Output:  
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```
Trivia:  
This problem was inspired by this original tweet by Max Howell:  
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.  

## 思路及总结
总的来说思路还是老生常谈的递归调用。   

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
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        self.invertTree(root.left)
        self.invertTree(root.right)
        root.left, root.right = root.right, root.left
        return root
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 74.33%(36ms)  

## 其他  
暂无
