#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n);
};

string Solution::countAndSay(int n)
{
    string result = "1";
    for (int i = 2; i <= n; i++)
    {
        string temp = "";
        for (int j = 0; j < result.size(); j++)
        {
            int count = 1;
            while (j + 1 < result.size() && result[j + 1] == result[j])
            { 
                count++;
                j++;
            }
            temp += to_string(count) + result[j];
        }
        result = temp;
    }
    return result;
}

int main()
{
    Solution s;
    int n;
    cin >> n;
    cout << s.countAndSay(n) << endl;
    return 0;
}