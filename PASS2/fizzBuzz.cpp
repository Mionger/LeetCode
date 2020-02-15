#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    vector<string> fizzBuzz(int n);
};

vector<string> Solution::fizzBuzz(int n)
{
    vector<string> result;
    for (int i = 1; i <= n; i++)
    {
        string s;
        if (0 == i % 15)
            s = "FizzBuzz";
        else if (0 == i % 3)
            s = "Fizz";
        else if (0 == i % 5)
            s = "Buzz";
        else
            s = to_string(i);
        result.push_back(s);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<string> result;
    result = s.fizzBuzz(n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}