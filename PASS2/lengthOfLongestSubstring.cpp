#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s)
{
    int result = 0;
    int len = s.size();
    map<char, int> jido;
    for (int i = 0, j = 0; j < len; j++)
    {
        if(jido.end()!=jido.find(s[j]))
        {
            i = max(jido[s[j]], i);
        }
        result = max(result, j - i + 1);
        jido[s[j]] = j + 1;
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}