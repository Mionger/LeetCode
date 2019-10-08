# 0104.maximum-depth-of-binary-tree  

## 题目信息  
Problem:[maximum-depth-of-binary-tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)  
Given a binary tree, find its maximum depth.  
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.  
Note: A leaf is a node with no children.  
Example:  
Given binary tree [3,9,20,null,null,15,7],  
```
    3
   / \
  9  20
    /  \
   15   7
```
return its depth = 3.  

## 思路及总结
关于二叉树的操作基本都可以通过递归和迭代这两种方式来实现。  
递归操作可以说是一种以自我为中心的解法，不需要了解之前和之后的操作实现的细节，只需要做好自己的这一步就可以。不过需要注意的是，递归操作要有明确的停止条件。  
本题的递归解法就不失递归代码一般的可读性。  
而迭代操作相对递归来说，代码就比较复杂，相对而言可以说是方便了机器，麻烦了程序员。虽然二者理论上的时间开销几乎一致，但是考虑到递归调用需要大量的堆栈，因此空间开销比较大。  
本题的迭代解法属于层次遍历。  

## 代码
Language：python3  
```
Recursion:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        else:
            return max(self.maxDepth(root.left),self.maxDepth(root.right)) + 1
```

```
Iteration:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        else:
            queue = [root]
            depth = 0
            while len(queue):
                depth += 1
                levelNodeTotal = len(queue)
                count = 0
                while count < levelNodeTotal:
                    count += 1
                    node = queue[0]
                    del queue[0]
                    if not (node.left is None):
                        queue.append(node.left)
                    if not (node.right is None):
                        queue.append(node.right)
            return depth
```

## 复杂度分析  
Recursion:  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 76.95%(48ms)  
  
Iteration:  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 76.95%(48ms)  

## 其他  
暂无
