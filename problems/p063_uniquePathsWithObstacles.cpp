// https://leetcode.com/problems/unique-paths/

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
    int p063_uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) ans[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) ans[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1) continue;
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }

        return ans[m - 1][n - 1];
    }
};

int main(int, char **)
{
    Solution s;

    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    auto ans = s.p063_uniquePathsWithObstacles(obstacleGrid);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}