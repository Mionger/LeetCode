#include<iostream>
using namespace std;

int result;

bool isBadVersion(int version)
{
    if(result==version)
        return true;
    else
        return false;
}

class Solution {
public:
    int firstBadVersion(int n);
};

int Solution::firstBadVersion(int n) 
{
    long long left = 1;
    long long right = n;
    long long mid = (left + right) >> 1;
    while(true)
    {
        if(isBadVersion(mid))
        {
            if (mid == 1 || !isBadVersion(mid - 1))
                break;
            else
            {
                right = mid - 1;
                mid = (left + right) >> 1;
            }
        }
        else
        {
            left = mid + 1;
            mid = (left + right) >> 1;
        }
    }
    return mid;
}

int main()
{
    int n;
    cin >> n >> result;
    Solution s;
    cout << s.firstBadVersion(n) << endl;
    return 0;
}