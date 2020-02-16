#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution 
{
public:
    bool isPowerOfThree(int n);
};

bool Solution::isPowerOfThree(int n)
{
    double temp = log10(n) / log10(3);
    return (temp - int(temp) == 0) ? true : false;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.isPowerOfThree(n) << endl;
    return 0;
}