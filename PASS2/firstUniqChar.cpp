#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s);
};

int Solution::firstUniqChar(string s)
{
    int map[26] = {0};
    int result = -1;
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i] - 'a']++;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if (1 == map[s[i] - 'a'])
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.firstUniqChar(str) << endl;
    return 0;
}