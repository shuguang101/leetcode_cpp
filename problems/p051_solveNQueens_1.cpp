// https://leetcode.com/problems/n-queens/
// 当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退
// 本题不限制7步

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    vector<vector<string>> ans;

    // 只需要检测前面的行
    bool isValid(vector<string> &board, int row, int col, int n)
    {
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtracking(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            board[row][col] = 'Q';
            if (isValid(board, row, col, n))
            {
                backtracking(board, row + 1, n);
            }
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        ans.clear();

        vector<string> board{(size_t)n, string((size_t)n, '.')};

        backtracking(board, 0, n);

        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    auto ans = s.solveNQueens(4);

    pprint::PrettyPrinter printer;
    printer.compact(false);
    printer.print(ans);
}