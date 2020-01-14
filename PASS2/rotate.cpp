#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k);
};

void re(vector<int> &nums, int start, int end)
{
    while(start < end)
    {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}

void Solution::rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    if(0 == k)
    {
        return;
    }
    else
    {
        re(nums, 0, nums.size() - k - 1);
        re(nums, nums.size() - k, nums.size() - 1);
        re(nums, 0, nums.size() - 1);
        return;
    }
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    for (int i = 0; i < 6; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    s.rotate(obj, 3);
    for (int i = 0; i < obj.size();i++)
    {
        cout << obj[i]<<' ';
    }
    return 0;
}