#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums);
};

int Solution::singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    return result;
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    cout << s.singleNumber(obj) << endl;
    return 0;
}