#include<iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices)
{
    int total;
    if (prices.size() >= 2)
    {
        int index_min = -1;
        int i = 0;
        while(i < prices.size())
        {
            //start
            if(0 == i)
            {
                index_min = i;
            }
            //end 
            if(i+1==prices.size()||prices[i]>prices[i+1])
            {
                total += (prices[i] - prices[index_min]);
                index_min = i + 1;
            }
            i++;
        }
    }
    return total;
}

int main()
{
    Solution s;
    vector<int> obj;
    int temp;
    for (int i = 0; i < 6; i++)
    {
        cin >> temp;
        obj.push_back(temp);
    }
    temp = s.maxProfit(obj);
    cout << temp << endl;
    return 0;
}

// 如果不考虑买入卖出时机，单独考虑利润的话，
// 可以只考虑相邻时间的利润是否为正，把左右为正的利润求和