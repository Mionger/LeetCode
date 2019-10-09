# 0112.path-sum  

## 题目信息  
Problem:[path-sum](https://leetcode.com/problems/path-sum/)  
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.  
Note: A leaf is a node with no children.  
Example:  
Given the below binary tree and sum = 22,  
```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.  

## 思路及总结
有种深度优先搜索的思想在里面。  
不过也没有什么特别的，通过传销递归一样可以解决。  

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
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        elif root.val == sum and root.left is None and root.right is None:
            return True
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 63.18%(52ms)  

## 其他  
暂无  
