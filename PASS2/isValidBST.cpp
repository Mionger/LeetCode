#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root);
    bool isValidBST(TreeNode *root, long long min, long long max);
};

//recursion
bool Solution::isValidBST(TreeNode *root)
{
    return isValidBST(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
}

bool Solution::isValidBST(TreeNode *root, long long min, long long max) 
{
    if (!root)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}

//mirros
// bool Solution::isValidBST(TreeNode *root)
// {
//     if (!root)
//         return true;
//     TreeNode *cur = root, *pre, *parent = NULL;
//     bool result = true;
//     while (cur)
//     {
//         if (!cur->left)
//         {
//             if (parent && parent->val >= cur->val)
//                 result = false;
//             parent = cur;
//             cur = cur->right;
//         }
//         else
//         {
//             pre = cur->left;
//             while (pre->right && pre->right != cur)
//                 pre = pre->right;
//             if (!pre->right)
//             {
//                 pre->right = cur;
//                 cur = cur->left;
//             }
//             else
//             {
//                 pre->right = NULL;
//                 if (parent->val >= cur->val)
//                     result = false;
//                 parent = cur;
//                 cur = cur->right;
//             }
//         }
//     }
//     return result;
// }