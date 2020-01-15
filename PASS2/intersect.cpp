#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2);
};

vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2)
{
    if(0==nums1.size())
    {
        return nums1;
    }
    else if(0==nums2.size())
    {
        return nums2;
    }
    else
    {
        vector<int> nums;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        for (i = 0; i < nums1.size(); i++)
        {
            if(j==nums2.size())
                break;
            if (nums1[i] == nums2[j])
            {
                nums.push_back(nums1[i]);
                j++;
            }
            else if(nums1[i]>nums2[j])
            {
                i--;
                j++;
            }
        }
        return nums;
    }
}

int main()
{
    Solution s;
    vector<int> obj1;
    vector<int> obj2;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        obj1.push_back(temp);
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        obj2.push_back(temp);
    }
    vector<int> obj3 = s.intersect(obj1, obj2);
    for (int i = 0; i < obj3.size(); i++)
    {
        cout << obj3[i]<<" ";
    }
    cout << endl;
    return 0;
}