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
    int maxDepth(TreeNode* root);
};

//iteration
int Solution::maxDepth(TreeNode* root)
{
    int result = 0;
    queue<TreeNode*> q;
    if (NULL == root)
        return result;
    else
    {
        q.push(root);
        while(!q.empty())
        {
            result++;
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return result;
    }
}

//recursion
// int Solution::maxDepth(TreeNode* root)
// {
//     int result = 0;
//     if(NULL==root)
//         return result;
//     else
//     {
//         result = result + max(this->maxDepth(root->left), this->maxDepth(root->right)) + 1;
//         return result;
//     }
// }