// https://leetcode.com/problems/sudoku-solver/
// using hashset: 104 ms	20.7 MB

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    vector<tuple<int, int>> indexes;
    bool is_end = false;

    void backtracking(vector<vector<char>> &board, int index)
    {
        auto [row, col] = indexes[index];
        auto candidates = getCandidates(board, row, col);

        for (char ch : candidates)
        {
            board[row][col] = ch;
            if (index < indexes.size() - 1)
            {
                backtracking(board, index + 1);
            }
            else
            {
                is_end = true;
            }

            if (is_end)
            {
                return;
            }
            board[row][col] = '.';
        }
    }

    unordered_set<char> getCandidates(const vector<vector<char>> &board, int row, int col)
    {
        unordered_set<char> candidates{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 0; i < 9; i++)
        {
            candidates.erase(board[i][col]);
            candidates.erase(board[row][i]);
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                candidates.erase(board[i + (row / 3) * 3][j + (col / 3) * 3]);
            }
        }

        return candidates;
    }

    vector<tuple<int, int>> getUnFilledIndex(const vector<vector<char>> &board)
    {
        vector<tuple<int, int>> indexes;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    indexes.push_back(make_tuple(i, j));
                }
            }
        }
        return indexes;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        is_end = false;
        indexes = getUnFilledIndex(board);
        backtracking(board, 0);
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;

    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    vector<vector<char>> ans{
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
    };

    s.solveSudoku(board);

    printer.compact(false);
    printer.print("board =", board);
    printer.print("is equal = ", board == ans);
}
