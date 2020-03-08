#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int prestart, int instart, int inend);
};

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder, int prestart, int instart, int inend)
{
    if (instart > inend)
        return NULL;

    int preroot = preorder[prestart];
    TreeNode *root = new TreeNode(preroot);
    int index;
    for (int i = instart; i <= inend; i++)
    {
        if (preroot == inorder[i])
            index = i;
    }

    root->left = buildTree(preorder, inorder, prestart + 1, instart, index - 1);
    root->right = buildTree(preorder, inorder, prestart + (index - instart) + 1, index + 1, inend);

    return root;
}