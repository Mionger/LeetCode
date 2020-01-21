#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t);
};

bool Solution::isAnagram(string s, string t)
{
    bool result = true;
    int map[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        map[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if(map[i]!=0)
        {
            result = false;
            break;
        }
    }
    return result;
}

int main()
{
    return 0;
}