#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs);
};

string Solution::longestCommonPrefix(vector<string> &strs)
{
    string res;
    if (strs.empty())
        res = "";
    else
    {
        res = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < res.length(); j++)
            {
                if(res[j]==strs[i][j])
                    continue;
                else
                {
                    res.erase(j);
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        strs.push_back(temp);
    }
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
