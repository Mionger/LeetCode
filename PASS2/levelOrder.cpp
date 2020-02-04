#include<iostream>
#include<vector>
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
    vector<vector<int> > levelOrder(TreeNode *root);
};

vector<vector<int> > Solution::levelOrder(TreeNode *root)
{
    vector<vector<int> > result;
    if (root != NULL)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int length = q.size();
            vector<int> temp;
            for (int i = 0; i < length; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                temp.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            result.push_back(temp);
        }
    }
    return result;
}