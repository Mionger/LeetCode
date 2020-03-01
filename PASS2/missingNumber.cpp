#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int missingNumber(vector<int> &nums);
};

int Solution::missingNumber(vector<int> &nums)
{
    int result = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        result += (i - nums[i]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> test;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        test.push_back(temp);
    }
    Solution s;
    cout << s.missingNumber(test) << endl;
    return 0;
}