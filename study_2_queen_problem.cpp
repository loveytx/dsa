#include <bits//stdc++.h>
using namespace std;

class solution
{
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &lower_left, vector<int> &upper_left, int n)
    {

        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lower_left[row + col] == 0 && upper_left[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lower_left[row + col] = 1;
                upper_left[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftrow, lower_left, upper_left, n);
                
                board[row][col] = '.';
                leftrow[row] = 0;
                lower_left[row + col] = 0;
                upper_left[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solvenQueen(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        int col = 0;
        vector<int> leftrow(n, 0), lower_left(2 * n - 1, 0), upper_left(2 * n - 1, 0);
        solve(0, board, ans, leftrow, lower_left, upper_left, n);
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    solution s;

    vector<vector<string>> result = s.solvenQueen(n);

    for (int i = 0; i < 2; i++) //because we know there will be two answers only but we can write n also (answer will be same)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << result[i][j][k]<<" ";
            }
        cout<<"\n";
        }

        cout<<"\n";
    }

    return 0;
}