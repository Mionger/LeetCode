#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle)
{
    int result = -1;
    if (0 == needle.size())
    {
        result = 0;
    }
    else
    {
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0] && haystack.size() - i >= needle.size())
            {
                result = i;
                int flag = 1;
                for (int j = 0; j < needle.size(); j++)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        result = -1;
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    break;
            }
        }
    }
    return result;
}

int main()
{
    Solution s;
    string haystack, needle;
    cin >> haystack >> needle;
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}

//不调用strstr的话，也有一样白给的调用find