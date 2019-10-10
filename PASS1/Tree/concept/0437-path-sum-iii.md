# 0437.path-sum-iii  

## 题目信息  
Problem:[path-sum-iii](https://leetcode.com/problems/path-sum-iii/)  
You are given a binary tree in which each node contains an integer value.  
Find the number of paths that sum to a given value.  
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).  
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.  
Example:  
```
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
```

## 思路及总结
笼统地说，这题是[112题](https://github.com/Mionger/LeetCode/blob/master/PASS1/Tree/concept/0112-path-sum.md)的变式。  
百不同之处在于112题是给定一个数值，让判断是否有从根结点到叶子结点的路径，满足路径上每个结点的数值之和为这个给定的数字。而这道题将情景一般化，让找出有几个连续路径满足路径上的结点数值之和为给定数字，路径的起点不一定为根结点，同时也不一定终止于叶子结点。  
采用深度优先遍历+递归的解法，每层的结果就是以该结点为根节点的子树满足这个条件的路径的数量+左子树子问题+右子树子问题。  
但是意外的发现emmmmm效率比较低下。  
在评论区找到了Solution1，算是一种以空间换时间的方式吧。遍历的同时记录每个结点的值，再利用List的count()方法判断有没有和要求的值相同的，注意数组的增长方式。  


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
class Solution(object):
    def pathSum(self, root, sum):

        if not root:
            return 0
        
        self.ans = 0

        def search(root, memo):
            
            self.ans += memo.count(sum)
            
            if root.left:
                search(root.left, [x+root.left.val for x in memo] + [root.left.val])
            
            if root.right:
                search(root.right, [x+root.right.val for x in memo] + [root.right.val])
                
        search(root, [root.val])
        return self.ans
```

```
MySolution:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        else:
            return self.dfs(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
    
    def dfs(self, root:TreeNode, sum:int) -> int:
        result = 0
        if not root:
            return result
        sum -= root.val
        if sum == 0:
            result += 1
        result += self.dfs(root.left, sum)
        result += self.dfs(root.right, sum)
        return result
```

## 复杂度分析  
Solution1:  
Time Complexity:O(n)  
Space Complexity:O(n^2)  
时间复杂度方面beats 58.17%(272ms)  

MySolution:  
Time Complexity:O(n^2)  
Space Complexity:O(n)  
时间复杂度方面beats 34.27%(996ms)  

## 其他  
暂无  
