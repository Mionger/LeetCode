#include<iostream>
#include<queue>
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
    bool isSymmetric(TreeNode *root);
    bool judgeSymmetric(TreeNode *left, TreeNode *right);
};

//recursion
// bool Solution::isSymmetric(TreeNode *root)
// {
//     bool result;
//     if (NULL == root)
//         result = true;
//     else
//         result = this->judgeSymmetric(root->left, root->right);
//     return result;
// }

// bool Solution::judgeSymmetric(TreeNode *left, TreeNode *right)
// {
//     if(NULL==left&&NULL==right)
//         return true;
//     else if (left && right && left->val == right->val && this->judgeSymmetric(left->left, right->right) && this->judgeSymmetric(left->right, right->left))
//         return true;
//     else
//         return false;
// }

//iteration
bool Solution::isSymmetric(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(root);
    while(!q.empty())
    {
        TreeNode *temp1 = q.front();
        q.pop();
        TreeNode *temp2 = q.front();
        q.pop();
        if (NULL == temp1 && NULL == temp2)
            continue;
        if (NULL == temp1 || NULL == temp2)
            return false;
        if (temp1->val != temp2->val)
            return false;
        q.push(temp1->left);
        q.push(temp2->right);
        q.push(temp1->right);
        q.push(temp2->left);
    }
    return true;
}