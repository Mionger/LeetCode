#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution 
{
public:
    int countPrimes(int n);
};

int Solution::countPrimes(int n)
{
    int result = 0;
    vector<bool> primes(n, true);
    for (int i = 2; i < n; i++)
    {
        if (primes[i] == true) 
        {
            result++;
            for (int j = i + i; j < n; j += i) 
            {
                primes[j] = false;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.countPrimes(n) << endl;
    return 0;
}