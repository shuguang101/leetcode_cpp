// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <cstring>

using namespace std;

class Solution
{
public:
    int maxProfit_v1(vector<int> &prices)
    {
        // 116 ms	77.9 MB

        // 最多进行的交易次数
        int k = 2;
        // 天数
        int m = prices.size();
        // dp[i][j]表示到第j天最多进行i次交易的最大收益
        int dp[k + 1][m + 1];
        int g[k + 1][m + 1];

        memset(dp, 0, sizeof(dp));
        memset(g, 0, sizeof(g));

        for (int i = 1; i <= k; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                g[i][j] = max(dp[i - 1][j - 2], g[i][j - 1]) + (prices[j - 1] - prices[j - 1 - 1]);
                dp[i][j] = max(g[i][j], dp[i][j - 1]);
            }
        }

        return dp[k][m];
    }

    int maxProfit_v2(vector<int> &prices)
    {
        // 136 ms	76.6 MB, 减少了少量内存占用

        // 最多进行的交易次数
        int k = 2;
        // 天数
        int m = prices.size();
        // dp[i][j]表示到第j天最多进行i次交易的最大收益
        int dp[k + 1][m + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= k; i++)
        {
            int g_i_jSub1 = 0;
            for (int j = 2; j <= m; j++)
            {
                int g_i_j = max(dp[i - 1][j - 2], g_i_jSub1) + (prices[j - 1] - prices[j - 1 - 1]);
                g_i_jSub1 = g_i_j;
                dp[i][j] = max(g_i_j, dp[i][j - 1]);
            }
        }

        return dp[k][m];
    }

    int maxProfit_v3(vector<int> &prices)
    {
        // 120 ms	75.3 MB

        // 第一次买入的价钱
        int buy1 = INT32_MAX;
        // 第一次交易的最大收益
        int profit1 = INT32_MIN;

        // 第二次买入的价钱减去第一次的收益， 第二次买入的价钱可能和第一次卖出的价钱一致
        int buy2_subProfit1 = INT32_MAX;
        int profit = INT32_MIN;

        int len = prices.size();
        for (int i = 0; i < len; i++)
        {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);

            buy2_subProfit1 = min(buy2_subProfit1, prices[i] - profit1);
            profit = max(profit, prices[i] - buy2_subProfit1);
        }

        return profit;
    }
};

int main(int, char **)
{
    Solution s;

    // // 6
    // vector<int> nums{3, 3, 5, 0, 0, 3, 1, 4};

    // // 4
    // vector<int> nums{1, 2, 3, 4, 5};

    // 13
    vector<int> nums{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};

    // auto ans = s.maxProfit_v1(nums);
    // auto ans = s.maxProfit_v2(nums);
    auto ans = s.maxProfit_v3(nums);

    cout << ans << endl;
}