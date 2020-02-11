#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
private:
    vector<int> nums;
public:
    Solution(vector<int> &nums);
    vector<int> reset();
    vector<int> shuffle();
};

Solution::Solution(vector<int> &nums)
{
    this->nums = nums;
}

vector<int> Solution::reset()
{
    return this->nums;
}

vector<int> Solution::shuffle()
{
    vector<int> result;
    if(this->nums.size())
    {
        int r = rand() % this->nums.size();
        
        for (int i = 0; i < this->nums.size(); i++)
            result.push_back(this->nums[(i + r) % this->nums.size()]);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    return 0;
}