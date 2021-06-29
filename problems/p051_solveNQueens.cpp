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

    void pp(vector<vector<int>> &unSafe, int row, int col, bool add)
    {
        int n = unSafe.size();
        if (row >= 0 && col >= 0 && row < n && col < n)
        {
            if (add)
                unSafe[row][col]++;
            else
                unSafe[row][col]--;
        }
    }

    void backtracking(vector<string> &board,
                      vector<vector<int>> &unSafe,
                      int startIndex,
                      int depth)
    {
        int n = board.size();
        int len = n * n;
        for (int index = startIndex; index < len; index++)
        {
            int row = index / n;
            int col = index % n;

            if (unSafe[row][col] == 0)
            {
                board[row][col] = 'Q';
                for (int i = -n; i <= n; i++)
                {
                    if (i != 0)
                    {
                        pp(unSafe, row, col + i, true);
                        pp(unSafe, row + i, col, true);
                        pp(unSafe, row + i, col + i, true);
                        pp(unSafe, row - i, col + i, true);
                    }
                }

                if (depth == n)
                {
                    ans.push_back(board);
                }
                else
                {
                    backtracking(board, unSafe, index + 1, depth + 1);
                }

                for (int i = -n; i <= n; i++)
                {
                    if (i != 0)
                    {
                        pp(unSafe, row, col + i, false);
                        pp(unSafe, row + i, col, false);
                        pp(unSafe, row + i, col + i, false);
                        pp(unSafe, row - i, col + i, false);
                    }
                }
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        ans.clear();

        vector<string> board{(size_t)n, string((size_t)n, '.')};
        vector<vector<int>> unSafe{(size_t)n, vector((size_t)n, 0)};

        backtracking(board, unSafe, 0, 1);

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