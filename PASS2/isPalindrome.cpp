#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s);
};

bool Solution::isPalindrome(string s)
{
    string str = "";
    for(auto c: s)//学习一个
        if(isalnum(c)) str += tolower(c);
    for(int i=0,j=str.size()-1;i<j;i++,j--)
        if(str[i]!=str[j]) return false;
    return true;
} 

int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << bool(s.isPalindrome(str)) << endl;
    return 0;
}