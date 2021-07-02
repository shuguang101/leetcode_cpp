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

public:
    int climbStairs(int n)
    {
        // 1 indexed
        // dp[1] = 1
        // dp[2] = 2
        // dp[3] = 3
        // dp[n] = dp[n-1] + dp[n-2]

        if (n <= 3) return n;

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