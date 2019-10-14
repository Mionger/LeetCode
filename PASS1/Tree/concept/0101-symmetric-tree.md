# 0101.symmetric-tree  

## 题目信息  
Problem:[symmetric-tree](https://leetcode.com/problems/symmetric-tree/)  
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).  
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:  
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
But the following [1,2,2,null,3,null,3] is not:  
```
    1
   / \
  2   2
   \   \
   3    3
```
Note:  
Bonus points if you could solve it both recursively and iteratively.  

## 思路及总结
判断一棵树是否对称，之列利用递归法就可以解决。不过注意这种需要注意这种母问题和子问题细节不同的递归情况。  

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
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            return self.isBothSymmetric(root.left, root.right)
        
    def isBothSymmetric(self, left, right) -> bool:
        if not left and not right:
            return True
        elif not left or not right:
            return False
        elif left.val != right.val:
            return False
        else:
            return self.isBothSymmetric(left.left, right.right) and self.isBothSymmetric(left.right,right.left)
```

## 复杂度分析  
Time Complexity:O(lgn)  
Space Complexity:O(n)  
时间复杂度方面beats 76.09%(40ms)  

## 其他  
暂无  
