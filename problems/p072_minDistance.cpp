// https://leetcode.com/problems/edit-distance/

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
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  // 16ms
        int dp[m+1][n+1]; // much faster than vector  4ms

        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        dp[0][0] = 0;
        dp[1][1] = (word2[0] != word1[0]);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1) continue;
                dp[i][j] = min({
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + (word1[i-1] != word2[j-1]),
                    dp[i - 1][j] + 1,
                });
            }
        }
        return dp[m][n];
    }
};

int main(int, char **)
{
    Solution s;

    string w1("intention");
    string w2("execution");

    auto ans = s.minDistance(w1, w2);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}