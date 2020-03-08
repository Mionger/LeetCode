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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int postend, int instart, int inend);
};

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTree(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder, int postend, int instart, int inend)
{
    if (instart > inend)
        return NULL;

    int postroot = postorder[postend];
    TreeNode *root = new TreeNode(postroot);
    int index;
    for (int i = instart; i <= inend; i++)
    {
        if (inorder[i] == postroot)
            index = i;
    }

    root->left = buildTree(inorder, postorder, postend - (inend - index) - 1, instart, index - 1);
    root->right = buildTree(inorder, postorder, postend - 1, index + 1, inend);

    return root;
}