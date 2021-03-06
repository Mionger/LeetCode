#include<iostream>
using namespace std;

class Solution 
{
public:
    int hammingWeight(uint32_t n);
};

int Solution::hammingWeight(uint32_t n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = (n * (0x01010101) >> 24);
    return n;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.hammingWeight(n) << endl;
    return 0;
}