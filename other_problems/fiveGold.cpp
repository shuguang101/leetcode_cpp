#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int maxGoldYield(int n, int p, vector<int> &g_person, vector<int> &g_yield)
    {
        // 总共p个人挖掘包含从[1-n]号金矿的最大产量
        int dp[n + 1][p + 1]{};

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                // 挖掘i号矿
                int remain_person = max({0, j - g_person[i]});
                int item1 = (j >= g_person[i] ? g_yield[i] + dp[i][remain_person] : 0);

                dp[i][j] = max({item1, dp[i - 1][j]});
            }
        }
        return dp[n][p];
    }

    int maxGoldYield_1(int n, int p, vector<int> &g_person, vector<int> &g_yield)
    {
        // 总共p个人挖掘包含从[1-n]号金矿的最大产量
        int dpi[p + 1]{};

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= p; j++)
            {
                // 挖掘i号矿
                int remain_person = max({0, j - g_person[i]});
                int item1 = (j >= g_person[i] ? g_yield[i] + dpi[remain_person] : 0);
                dpi[j] = max({item1, dpi[j]});
            }
        }
        return dpi[p];
    }
};

int main(int, char **)
{
    // 金矿所需人数
    vector<int> g_person{5, 5, 3, 4, 3};
    // 金矿产量
    vector<int> g_yield{400, 500, 200, 300, 350};
    // 总共可用人数
    int totalPerson = 10;
    // 金矿总数
    int n = g_person.size();

    assert(g_yield.size() == g_person.size());

    Solution s;

    auto ans = s.maxGoldYield(n, totalPerson, g_person, g_yield);

    auto ans1 = s.maxGoldYield_1(n, totalPerson, g_person, g_yield);

    cout << ans << "  " << ans1 << endl;
}