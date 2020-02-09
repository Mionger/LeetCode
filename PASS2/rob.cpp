#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int rob(vector<int> &nums);
};

int Solution::rob(vector<int> &nums)
{
    if (0 == nums.size())
        return 0;
    int best[nums.size()];
    for (int i = 0; i < nums.size();i++)
    {
        if (0 == i)
            best[i] = nums[0];
        else if (1 == i)
            best[i] = max(nums[0], nums[1]);
        else
            best[i] = max(best[i - 1], best[i - 2] + nums[i]);
    }
    return best[nums.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}