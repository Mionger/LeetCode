#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target);
};

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    map<int, int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if(temp.find(target-nums[i])!=temp.end())
        {
            result.push_back(temp[target - nums[i]]);
            result.push_back(i);
            break;
        }
        else
        {
            temp[nums[i]] = i;
        }
    }
    return result;
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    int k;
    cin >> k;
    vector<int> result = s.twoSum(obj, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<<' ';
    }
    cout << endl;
    return 0;
}