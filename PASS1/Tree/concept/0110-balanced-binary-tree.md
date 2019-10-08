# 0110.balanced-binary-tree  

## 题目信息  
Problem:[balanced-binary-tree](https://leetcode.com/problems/balanced-binary-tree/)  
Given a binary tree, determine if it is height-balanced.  
For this problem, a height-balanced binary tree is defined as:  
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.  
Example 1:  
Given the following tree [3,9,20,null,null,15,7]:  
```
    3
   / \
  9  20
    /  \
   15   7
```
Return true.  
Example 2:  
Given the following tree [1,2,2,3,3,null,null,4,4]:  
```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```
Return false.  

## 思路及总结
二叉平衡树是一种改进的二叉查找树。因为二叉查找树的期望效率取决于其深度的期望，因此平衡树作为一种期望高度较小的树出现。  
二叉平衡树的平衡之处在于对于二叉树的每一个结点，其左子树和右子树的深度的查的绝对值不超过1。  
因此一般而言，判断一棵树是不是二叉平衡树一般采用这种方式来判断，这也是解法一中用到的方法。  
这个方法在解题报告中属于第二个波峰的前列，因此一定还存在位于第一个波峰的效率更高的解法。  
解法二相对于解法一而言，应该说是优化了对于一个结点的函数调用次数，原来既要调用深度函数，又要调用平衡函数，这样一来感觉相当于提前剪枝。  
解法二在解题报告中属于第一个波峰的前列，效率还算可以。  

## 代码
Language：python3  
```
Solution1:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        else:
            if not self.isBalanced(root.right):
                return False
            elif not self.isBalanced(root.left):
                return False
            else:
                hl = self.getHeight(root.left)
                hr = self.getHeight(root.right)
                if hl - hr > 1 or hr - hl > 1:
                    return False
                else:
                    return True
        
    def getHeight(self, root:TreeNode) -> int:
        if not root:
            return 0
        else:
            return max(self.getHeight(root.left), self.getHeight(root.right)) + 1
```
```
Solution2:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        # 思路2. 把两个函数的穿插调用简化1成几乎之递归调用一个函数
        if self.checkHeight(root) == -1:
            return False
        else:
            return True
            
    def checkHeight(self, root:TreeNode) -> int:
        if not root:
            return 0
        hl = self.checkHeight(root.left)
        if hl == -1:
            return -1
        
        hr = self.checkHeight(root.right)
        if hr == -1:
            return -1
        
        ha = abs(hl - hr)
        if ha > 1:
            return -1
        else:
            return max(hl, hr) + 1
```


## 复杂度分析  
Solution1:  
Time Complexity:O(nlgn)  
Space Complexity:O(n)  
时间复杂度方面beats 36.69%(72ms)  
  
Solution2:  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 87.13%(56ms)  

## 其他  
暂无
