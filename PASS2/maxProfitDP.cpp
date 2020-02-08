#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices);
};

int Solution::maxProfit(vector<int> &prices)
{
    if(0==prices.size())
        return 0;
    int result = 0;
    int min = prices[0];
    int max = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            max = prices[i];
        }
        if(prices[i] > max)
            max = prices[i];
        if (max - min > result)
            result = max - min;
    }
    return result;
}

int main()
{
    vector<int> prices;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}