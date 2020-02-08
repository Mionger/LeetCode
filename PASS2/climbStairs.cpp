#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int climbStairs(int n);
};

int Solution::climbStairs(int n)
{
    vector<int> note;
    note.push_back(1);
    note.push_back(1);
    for (int i = 2; i <= n; i++)
        note.push_back(note[i - 1] + note[i - 2]);
    return note[n];
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}