// https://leetcode.com/problems/distinct-subsequences/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <cstring>

using namespace std;

class Solution
{
private:
    string path;
    int ans;

    void trackingback(string &s, string &t, int startPos)
    {
        if (path.size() == t.size())
        {
            if (path == t)
                ans++;
            return;
        }

        for (int i = startPos; i < s.size(); i++)
        {
            path.push_back(s[i]);
            trackingback(s, t, i + 1);
            path.pop_back();
        }
    }

public:
    int numDistinct_1(string s, string t)
    {
        // 超时
        path.clear();
        ans = 0;
        trackingback(s, t, 0);
        return ans;
    }

    int numDistinct_2(string s, string t)
    {
        //  速度太慢 1140 ms
        int m = s.size();
        int n = t.size();

        if (m < n)
            return 0;

        uint64_t dp[m][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[j][i] = 0;

                if (i == 0)
                {
                    dp[j][i] = (s[j] == t[i]);
                }
                else if (j < i || s[j] != t[i])
                {
                    dp[j][i] = 0;
                }
                else
                {
                    for (int k = 0; k <= j - 1; k++)
                    {
                        if (k < i - 1)
                            continue;
                        dp[j][i] += dp[k][i - 1];
                    }
                }
            }
        }

        uint64_t ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans += dp[i][n - 1];
        }
        return ans;
    }

    int numDistinct_3(string s, string t)
    {
        // 8 ms, much faster
        // zero index
        // dp[j,i] 表示以s[j]为最后一个字符 能够形成字符串t[0:i]的数量(包含n)
        // dp[m-1, n-1]

        //  速度太慢 1140 ms
        int m = s.size();
        int n = t.size();

        if (m < n)
            return 0;

        uint64_t dp[m + 1][n + 1];
        uint64_t sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < m; j++)
            {
                if (i == 0)
                    dp[j][i] = (s[j] == t[i]);
                sum += dp[j][i];
                dp[j + 1][i + 1] = (s[j + 1] != t[i + 1]) ? 0 : sum;
            }
        }
        return sum;
    }

    int numDistinct_4(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (m < n)
            return 0;

        // m >= n, 初始化为0
        uint64_t dp[m][n]{};
        // fill with zero, leetcode 不支持uint64_t dp[m][n]{}
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < m; j++)
            {
                if (i == 0)
                {
                    dp[j][i] = (s[j] == t[i]);
                    if (j > i)
                        dp[j][i] += dp[j - 1][i];
                }
                else
                {
                    dp[j][i] = dp[j - 1][i] + (s[j] == t[i] ? dp[j - 1][i - 1] : 0);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main(int, char **)
{
    Solution s;

    // // 4
    // string w1("aabb");
    // string w2("ab");

    // // 3
    // string w1("rabbbit");
    // string w2("rabbit");

    // // 5
    // string w1("babgbag");
    // string w2("bag");

    // 543744000
    string w1("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo");
    string w2("rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");

    // 0
    // string w1("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    // string w2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    // auto ans = s.numDistinct_1(w1, w2);
    // auto ans = s.numDistinct_2(w1, w2);
    // auto ans = s.numDistinct_3(w1, w2);
    auto ans = s.numDistinct_4(w1, w2);

    cout << ans << endl;
}