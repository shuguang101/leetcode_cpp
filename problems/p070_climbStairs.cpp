// https://leetcode.com/problems/climbing-stairs/

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
    // 1 <= n, 1 <= m  完全背包问题
    int climbStairs_m(int n, int m)
    {
        // 每次可以爬1，2，3，...，m个台阶
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i - j >= 0)
                    dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }

public:
    int climbStairs(int n)
    {
        // 1 indexed
        // dp[1] = 1
        // dp[2] = 2
        // dp[3] = 3
        // dp[n] = dp[n-1] + dp[n-2]

        if (n <= 3)
            return n;

        int dp1 = 1;
        int dp2 = 2;
        int dp = 3;
        for (int i = 3; i <= n; i++)
        {
            dp = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp;
        }
        return dp;
    }
};

int main(int, char **)
{
    Solution s;

    auto ans = s.climbStairs(3);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}