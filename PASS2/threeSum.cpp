#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &nums); 
};

vector<vector<int> > Solution::threeSum(vector<int> &nums)
{
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            int s = nums[i] + nums[left] + nums[right];
            if (s > 0)
                right -= 1;
            else if (s < 0)
                left += 1;
            else
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[left]);
                temp.push_back(nums[right]);
                result.push_back(temp);
                while (left < right && nums[right] == nums[right - 1])
                    right -= 1;
                while (left < right && nums[left] == nums[left + 1])
                    left += 1;
                right -= 1;
                left += 1;
            }
        }
    }
    return result;
}

int main()
{
    return 0;
}