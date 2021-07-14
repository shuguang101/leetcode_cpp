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
        int ans = 0;
        int l = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] >= prices[i - 1])
            {
                if (i == prices.size() - 1)
                {
                    ans += prices[i] - prices[l];
                }
            }
            else
            {
                ans += max(0, prices[i - 1] - prices[l]);
                l = i;
            }
        }
        return ans;
    }

    int maxProfit_dp(vector<int> &prices)
    {
        int dp_i_pre = 0;
        int dp_i = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i - 1] < 0)
            {
                dp_i = dp_i_pre;
            }
            else
            {
                dp_i = dp_i_pre + prices[i] - prices[i - 1];
            }
            dp_i_pre = dp_i;
        }
        return dp_i;
    }
};

int main(int, char **)
{
    Solution s;

    // 7
    vector<int> nums{7, 1, 5, 3, 6, 4};

    // auto ans = s.maxProfit(nums);
    auto ans = s.maxProfit_dp(nums);

    cout << ans << endl;
}