#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums);
};

bool Solution::containsDuplicate(vector<int> &nums)
{
    if(nums.empty())
    {
        return false;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1;i++)
    {
        if(nums[i]==nums[i+1])
            return true;
    }
    return false;
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    cout << s.containsDuplicate(obj) << endl;
    for (int i = 0; i < obj.size();i++)
    {
        cout << obj[i]<<" ";
    }
    cout << endl;
    return 0;
}