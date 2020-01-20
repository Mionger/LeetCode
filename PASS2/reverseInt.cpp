#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    int reverse(int x);
};

int Solution::reverse(int x)
{
    int result = 0;
    while(x)
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && x % 10 > 7))
        {
            return 0;
        }
        else if(result < INT_MIN / 10 || (result == INT_MIN / 10 && x % 10 <-8))
        {
            return 0;
        }
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

int main()
{
    Solution s;
    int input, result;
    cin >> input;
    result = s.reverse(input);
    cout << result << endl;
    return 0;
}