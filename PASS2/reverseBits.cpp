#include<iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n);
};

uint32_t Solution::reverseBits(uint32_t n)
{
    // n = (n >> 16) | (n << 16);
    // n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    // n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    // n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    // n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    // return n;

    uint32_t ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        ret = ret | (((n >> (31 - i)) & 1) << i);
    }
    return ret;
}

int main()
{
    unsigned int n;
    cin >> n;
    Solution s;
    cout << s.reverseBits(n) << endl;
    return 0;
}