# 0071.simplify-pathsimplify-path  

## 题目信息  
Problem:[simplify-pathsimplify-path](https://leetcode.com/problems/simplify-pathsimplify-path/)  
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.  
In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.
For more information, see: Absolute path vs relative path in Linux/Unix  
Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names.  
The last directory name (if it exists) must not end with a trailing /.  
Also, the canonical path must be the shortest string representing the absolute path.  
Example 1:  
Input: "/home/"  
Output: "/home"  
Explanation: Note that there is no trailing slash after the last directory name.  
Example 2:  
Input: "/../"  
Output: "/"  
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.  
Example 3:  
Input: "/home//foo/"  
Output: "/home/foo"  
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.  
Example 4:  
Input: "/a/./b/../../c/"  
Output: "/c"  
Example 5:  
Input: "/a/../../b/../c//.//"  
Output: "/c"  
Example 6:  
Input: "/a//b////c/d//././/.."  
Output: "/a/b/c"  

## 思路及总结
这道题看起来也是相对来说比较普通的一道栈的应用，不过糅合了一点UNIX风格的路径的知识  
在处理字符串的时候尽量使用已有封装好的的方法，而不是一味的按照C语言的思路，会使代码简洁许多  

## 代码
Language：python3  
```
class Solution:
    def simplifyPath(self, path: str) -> str:
        if not path: return ""
        res = []
        for p in path.split("/"):
            if p == "..":
                if res:
                    res.pop()
            elif p and p != ".":
                res.append(p)
        return "/" + "/".join(res)
```
## 复杂度分析  
Time Complexity:O(n)  
Space Complexity:O(n)  
时间复杂度方面beats 63.16%(40ms)    

## 其他  
暂无
