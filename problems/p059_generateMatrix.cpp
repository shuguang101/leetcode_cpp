// https://leetcode.com/problems/spiral-matrix-ii/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans{(size_t)n, vector<int>((size_t)n, 0)};

        int row = 0;
        int col = 0;
        int val = 0;
        int len = n;
        int plus = 1;

        for (int j = 0; j < n - 1; j++)
        {
            for (int i = 0; i < len; i++)
            {
                // row
                if (val != 0)
                    col = (col + plus) % n;
                ans[row][col] = ++val;
            }
            len--;
            for (int i = 0; i < len; i++)
            {
                // col
                row = (row + plus) % n;
                ans[row][col] = ++val;
            }
            plus *= -1;
        }

        col = (col + plus) % n;
        ans[row][col] = ++val;

        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    auto ans = s.generateMatrix(3);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}