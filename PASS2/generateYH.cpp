#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > generate(int numRows);
};

vector<vector<int> > Solution::generate(int numRows)
{
    vector<vector<int> > result;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        if (0 == i)
            temp.push_back(1);
        else
        {
            temp.push_back(1);
            for (int j = 1; j < result[i - 1].size(); j++)
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            temp.push_back(1);
        }
        result.push_back(temp);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int> > result;
    result = s.generate(n);
    for (int i = 0; i < result.size(); i++)
        for(int j=0;j<result[i].size();j++)
            cout << result[i][j] << ' ';
        cout << endl;
    return 0;
}