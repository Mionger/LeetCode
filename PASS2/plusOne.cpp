#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits);
};

vector<int> Solution::plusOne(vector<int> &digits)
{
    vector<int> result;
    int pass = 1;
    int temp = 0;
    for (int i = digits.size()-1; i >=0; i--)
    {
        temp = digits[i] + pass;
        if (10 == temp)
        {
            temp = 0;
            pass = 1;
            result.insert(result.begin(), temp);
        }
        else
        {
            pass = 0;
            result.insert(result.begin(), temp);
        } 
    }
    if(0 != pass)
    {
        result.insert(result.begin(), pass);
    }
    return result;
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    vector<int> result = s.plusOne(obj);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
    return 0;
}