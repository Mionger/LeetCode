#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution 
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs);
};

vector<vector<string> > Solution::groupAnagrams(vector<string> &strs)
{
    vector<vector<string> > result;
    map<string, int> jido;
    int index = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if (jido.count(temp))
        {
            result[jido[temp]].push_back(strs[i]);
        }
        else
        {
            vector<string> vec(1, strs[i]);
            result.push_back(vec);
            jido[temp] = index++;
        }
    }
    return result;
}

int main()
{

    return 0;
}