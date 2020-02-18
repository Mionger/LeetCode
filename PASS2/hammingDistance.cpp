#include<iostream>
using namespace std;

class Solution 
{
public:
    int hammingDistance(int x, int y);
};

int Solution::hammingDistance(int x, int y)
{
    unsigned int n = x ^ y;
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = (n * (0x01010101) >> 24);
    return n;
}

int main()
{
    int x;
    int y;
    cin >> x >> y;
    Solution s;
    cout << s.hammingDistance(x, y) << endl;
    return 0;
}