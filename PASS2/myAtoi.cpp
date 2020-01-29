#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str);
};

int Solution::myAtoi(string str) 
{
    int i = 0;
    int flag = 1;
    int result = 0;
    while(' '==str[i])
        i++;
    if('+'==str[i])
        i++;
    else if('-'==str[i])
    {
        i++;
        flag = -1;
    }
    while (i < str.size() && isdigit(str[i]))
    {
        int temp = str[i] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > 7))
            return flag > 0 ? INT_MAX : INT_MIN;
        result = result * 10 + temp;
        i++;
    }
    return flag > 0 ? result : -result;
}

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.myAtoi(str) << endl;
    return 0;
}