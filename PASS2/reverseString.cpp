#include<iostream>
#include<vector>
using namespace std;

#define SIZE 5

class Solution {
public:
    void reverseString(vector<char> &s);
};

void Solution::reverseString(vector<char> &s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        s[i] = s[i] ^ s[s.size() - i - 1];
        s[s.size() - i - 1] = s[i] ^ s[s.size() - i - 1];
        s[i] = s[i] ^ s[s.size() - i - 1];
    }
}

int main()
{
    Solution s;
    char temp;
    vector<char> string;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> temp;
        string.push_back(temp);
    }
    s.reverseString(string);
    for (int i = 0; i < SIZE; i++)
    {
        cout << string[i];
    }
    cout << endl;
    return 0;
}