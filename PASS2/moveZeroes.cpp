#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums);
};

void Solution::moveZeroes(vector<int> &nums)
{
    int first = 0;
    int last = 0;
    for (int i = 0; i < nums.size();i++)
    {
        if(0 == nums[i])
        {
            last++;
        }
        else
        {
            int temp = nums[i];
            nums[i] = nums[first];
            nums[first] = temp;
            first++;
        }
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
    s.moveZeroes(obj);
    for (int i = 0; i < obj.size(); i++)
    {
        cout << obj[i]<<' ';
    }
    cout << endl;
    return 0;
}