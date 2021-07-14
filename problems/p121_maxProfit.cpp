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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int dp[n];
        dp[n - 1] = 0;
        int maxVal = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (dp[i + 1] < 1)
            {
                dp[i] = prices[i + 1] - prices[i];
            }
            else
            {
                dp[i] = dp[i + 1] + (prices[i + 1] - prices[i]);
                dp[i] = max(0, dp[i]);
            }

            maxVal = max(dp[i], maxVal);
        }

        return maxVal;
    }
};

int main(int, char **)
{
    Solution s;

    // // 5
    // vector<int> nums{7, 1, 5, 3, 6, 4};

    // 1
    vector<int> nums{1, 2};

    auto ans = s.maxProfit(nums);

    cout << ans << endl;
}