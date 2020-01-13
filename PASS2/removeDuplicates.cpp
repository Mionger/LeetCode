#include<iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int> &nums);
};

int Solution::removeDuplicates(vector<int> &nums)
{
    if(nums.empty())
    {
        return 0;
    }
    else
    {
        int number = 0;
        for (int i = 1; i < nums.size();i++)
        {
            if(nums[number]==nums[i])
            {
                continue;
            }
            else
            {
                nums[++number] = nums[i];
            }
        }
        return number + 1;
    }
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
    temp = s.removeDuplicates(obj);
    for (int i = 0; i < temp;i++)
    {
        cout << obj[i] << " ";
    }
    cout << endl;
    return 0;
}
