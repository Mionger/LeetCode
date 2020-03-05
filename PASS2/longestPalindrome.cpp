#include<iostream>
#include<string>
using namespace std;

class Solution 
{
public:
    int expend(string s, int left, int right);
    string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s)
{
    if (s.size() < 1)
        return "";
    else
    {
        int start = 0;
        int end = 0;
        int l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int l1 = expend(s, i, i);
            int l2 = expend(s, i, i + 1);
            l = max(max(l1, l2), l);
            if (l > end - start + 1)
            {
                start = i - (l - 1) / 2;
                end = i + l / 2;
            }
        }
        return s.substr(start, l);
    }
}

int Solution::expend(string s,int left,int right)
{
    int L = left;
    int R = right;
    while (L >= 0 && R < s.size() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.longestPalindrome(str) << endl;
    return 0;
}