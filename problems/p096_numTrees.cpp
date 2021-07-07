// https://leetcode.com/problems/unique-binary-search-trees/

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
    int numTrees(int n)
    {
        // init with zero
        int dp[n + 1]{};
        // fill with one
        fill_n(dp, 2, 1);

        if (n < 2)
            return 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};

int main(int, char **)
{
    Solution s;

    auto ans = s.numTrees(3);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}