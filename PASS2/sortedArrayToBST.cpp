#include<iostream>
#include<vector>
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
    TreeNode *sortedArrayToBST(vector<int> &nums);
    TreeNode *sortedArrayToBST(vector<int> &nums, int low, int high);
};

TreeNode* Solution::sortedArrayToBST(vector<int> &nums)
{
    return this->sortedArrayToBST(nums, 0, nums.size());
}

TreeNode* Solution::sortedArrayToBST(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        return NULL;
    }
    else
    {
        int mid = (low + high) >> 1;
        TreeNode *result = new TreeNode(nums[mid]);
        result->left = this->sortedArrayToBST(nums, low, mid);
        result->right = this->sortedArrayToBST(nums, mid + 1, high);
        return result;
    }
}