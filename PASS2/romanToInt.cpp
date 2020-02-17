#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution 
{
public:
    int romanToInt(string s);
};

int Solution::romanToInt(string s)
{
    int result = 0;
    map<char, int> rom;
    rom['I'] = 1;
    rom['V'] = 5;
    rom['X'] = 10;
    rom['L'] = 50;
    rom['C'] = 100;
    rom['D'] = 500;
    rom['M'] = 1000;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        int temp = rom[s[i]];
        if (len - 1 == i || rom[s[i]] >= rom[s[i + 1]])
            result += temp;
        else
            result -= temp;
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.romanToInt(str) << endl;
    return 0;
}