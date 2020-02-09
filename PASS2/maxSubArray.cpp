#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums);
    int maxSubArray(vector<int> &nums, int left, int right);
};

//dp
int Solution::maxSubArray(vector<int> &nums)
{
    int b[nums.size()];
    int sum = nums[0];
    b[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        b[i] = max(b[i - 1], 0) + nums[i];
        if(b[i]>sum)
            sum = b[i];
    }
    return sum;
}

//partition
// int Solution::maxSubArray(vector<int> &nums, int left, int right)
// {
//     int sum;
//     if(left==right)
//     {
//         sum = nums[left];
//     }
//     else
//     {
//         int mid = (left + right) / 2;
//         int leftsum = this->maxSubArray(nums, left, mid);
//         int rightsum = this->maxSubArray(nums, mid + 1, right);

//         int sum1;
//         int lefttemp = 0;
//         for (int i = mid; i >= left; i--)
//         {
//             lefttemp += nums[i];
//             if (mid == i)
//                 sum1 = lefttemp;
//             else
//                 sum1 = lefttemp > sum1 ? lefttemp : sum1;
//         }
//         int sum2;
//         int righttemp = 0;
//         for (int i = mid + 1; i <= right; i++)
//         {
//             righttemp += nums[i];
//             if (mid + 1 == i)
//                 sum2 = righttemp;
//             else
//                 sum2 = righttemp > sum2 ? righttemp : sum2;
//         }
//         sum = sum1 + sum2;
//         if (leftsum > sum)
//             sum = leftsum;
//         if (rightsum > sum)
//             sum = rightsum;
//     }
//     return sum;
// }

// int Solution::maxSubArray(vector<int> &nums)
// {
//     return this->maxSubArray(nums, 0, nums.size() - 1);
// }

int main()
{
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}