# 0617.merge-two-binary-trees  

## 题目信息  
Problem:[merge-two-binary-trees](https://leetcode.com/problems/merge-two-binary-trees/)  
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.  
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.  
Otherwise, the NOT null node will be used as the node of new tree.  
Example 1:  
Input:  
```
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7       
```
Output:  
Merged tree:  
```
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
```

Note: The merging process must start from the root nodes of both trees.

## 思路及总结
这道题和传统的二叉树处理方法比较起来不同的是要注意判断两个结点的状态，弄懂这个通过递归就迎刃而解。  

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
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 and not t2:
            return None
        elif not t1:
            return t2
        elif not t2:
            return t1
        node = TreeNode(t1.val + t2.val)
        node.left = self.mergeTrees(t1.left, t2.left)
        node.right = self.mergeTrees(t1.right, t2.right)
        return node
```

## 复杂度分析   
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 87.31%(84ms)  

## 其他  
暂无  
