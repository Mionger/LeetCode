#include<iostream>
#include<vector>
using namespace std;

#define SIZE 3

class Solution {
public:
    void rotate(vector<vector<int> > &matrix);
};

void Solution::rotate(vector<vector<int> > &matrix)
{
    for (int i = 0; i < matrix.size();i++)
    {
        for (int j = i + 1; j < matrix.size();j++)
        {
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            matrix[j][i] = matrix[i][j] ^ matrix[j][i];
            matrix[i][j] = matrix[i][j] ^ matrix[j][i];
        }
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    Solution s;
    vector<vector<int> > matrix;
    for (int i = 0; i < SIZE; i++)
    {
        vector<int> array;
        for (int j = 0; j < SIZE; j++)
        {
            int temp;
            cin >> temp;
            array.push_back(temp);
        }
        matrix.push_back(array);
    }
    s.rotate(matrix);
    for (int i = 0; i < SIZE;i++)
    {
        for (int j = 0; j < SIZE;j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}