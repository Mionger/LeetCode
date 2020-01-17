#include<iostream>
#include<vector>

#define SIZE 9

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board);
};

bool Solution::isValidSudoku(vector<vector<char> > &board)
{
    bool line[9][9]={false};
    bool column[9][9]={false};
    bool box[9][9]={false};
    for (int i = 0; i < SIZE;i++)
    {
        for (int j = 0; j < SIZE;j++)
        {
            if('.'==board[i][j])
            {
                continue;
            }
            else
            {
                int temp = board[i][j] - '1';
                if(line[i][temp]||column[j][temp]||box[(i/3)*3+j/3][temp])
                {
                    return false;
                }
                else
                {
                    line[i][temp] = true;
                    column[j][temp] = true;
                    box[(i / 3) * 3 + j / 3][temp] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    Solution s;
    vector<vector<char> > board;
    char temp;
    for (int i = 0; i < SIZE;i++)
    {
        for (int j = 0; j < SIZE;j++)
        {
            cin >> temp;
            board[i].push_back(temp);
        }
    }
    cout << s.isValidSudoku(board) << endl;
    return 0;
}
