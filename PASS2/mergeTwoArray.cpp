#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
};

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p = m + n - 1;
    int p1 = m - 1;
    int p2 = n - 1;
    while (p2 >= 0 && p >= 0)
    {
        
        if (p1 < 0)
        {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
        else
        {
            if (nums1[p1] < nums2[p2])
            {
                nums1[p] = nums2[p2];
                p2--;
                p--;
            }
            else
            {
                nums1[p] = nums1[p1];
                p1--;
                p--;
            }
        }    
    }
    return;
}

int main()
{
    int m, n;
    vector<int> a1;
    vector<int> a2;
    cin >> m >> n;
    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
        {
            int temp;
            cin >> temp;
            a1.push_back(temp);
        }
        else
        {
            a1.push_back(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a2.push_back(temp);
    }
    Solution s;
    s.merge(a1, m, a2, n);
    for (int i = 0; i < m + n; i++)
        cout << a1[i] << ' ';
    cout << endl;
    return 0;
}