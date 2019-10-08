# 0543.diameter-of-binary-tree  

## 题目信息  
Problem:[diameter-of-binary-tree](https://leetcode.com/problems/diameter-of-binary-tree/)  
Given a binary tree, you need to compute the length of the diameter of the tree.  
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.  
This path may or may not pass through the root.  
Example:  
Given a binary tree  
```
          1
         / \
        2   3
       / \     
      4   5    
```
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].  
Note: The length of path between two nodes is represented by the number of edges between them.  

## 思路及总结
求一颗二叉树的两个结点之间的最长路径，处理思路有点和平衡树有种异曲同工之妙，或者说涉及到树高的二叉树问题应该都是这种思路。  
一种类似于深度优先搜索的方法?  

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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.result = 1
        
        def getDepth(node: TreeNode) -> int:
            if not node:
                return 0
            L = getDepth(node.left)
            R = getDepth(node.right)
            self.result = max(self.result, L+R+1)
            return max(L, R) + 1
        
        getDepth(root)
        return self.result - 1
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 76.95%(48ms)  

## 其他  
1. 嵌套函数有时候能在递归的时候巧妙传参。  
