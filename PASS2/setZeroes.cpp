#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int> > &matrix);
};

void Solution::setZeroes(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool row = false;
    for (int i = 0; i < n; i++)
        if (0 == matrix[0][i])
        {
            row = true;
            break;
        }

    bool col = false;
    for (int i = 0; i < m; i++)
        if (0 == matrix[i][0])
        {
            col = true;
            break;
        }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (0 == matrix[i][j])
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (0 == matrix[i][0])
            for (int j = 1; j < n; j++)
                matrix[i][j] = 0;
    }

    for (int j = 1; j < n; j++)
    {
        if (0 == matrix[0][j])
            for (int i = 0; i < m; i++)
                matrix[i][j] = 0;
    }

    if (row)
        for (int i = 0; i < n;i++)
            matrix[0][i] = 0;
    if (col)
        for (int i = 0; i < m;i++)
            matrix[i][0] = 0;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> line;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            line.push_back(temp);
        }
        matrix.push_back(line);
    }
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    return 0;
}