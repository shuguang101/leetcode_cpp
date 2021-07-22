// https://leetcode.com/problems/palindrome-partitioning/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <numeric> // std::accumulate
#include <cstring>
#include <chrono>

using namespace std;

class Solution
{
private:
    bool trackingBack_v1(string &s, unordered_set<string> &set, vector<char> &memory, int startPos)
    {
        if (startPos >= s.size())
            return true;
        if (memory[startPos] != -1)
            return memory[startPos];

        int sLen = s.size();
        for (int wordLen = 1; wordLen <= sLen - startPos; wordLen++)
        {
            // 从startPos开始的所有可能字符
            string word = s.substr(startPos, wordLen);
            // string remain = s.substr(startPos + wordLen);
            if (set.find(word) != set.end() && trackingBack_v1(s, set, memory, startPos + wordLen))
            {
                memory[startPos] = 1;
                return true;
            }
        }

        memory[startPos] = 0;
        return false;
    }

public:
    bool wordBreak_v1(string s, vector<string> &wordDict)
    {
        // 20 ms    13.6 MB
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<char> memory(s.size(), -1);
        return trackingBack_v1(s, set, memory, 0);
    }

    bool wordBreak_v2(string s, vector<string> &wordDict)
    {
        int m = s.size();
        int n = wordDict.size();

        int dp[m];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmpVal = 0;
                int wdl = wordDict[j].size();
                int startPos = i - wdl + 1;
                if (startPos >= 0 && s.substr(startPos, wdl) == wordDict[j])
                {
                    if (startPos < 1)
                    {
                        tmpVal = 1;
                    }
                    else
                    {
                        tmpVal = dp[startPos - 1];
                    }
                }
                dp[i] = dp[i] || tmpVal;
            }
        }
        return dp[m - 1];
    }

    bool wordBreak_v3(string s, vector<string> &wordDict)
    {
        int m = s.size();
        int n = wordDict.size();

        int dp[m];
        memset(dp, 0, sizeof(dp));

        // 从前向后找
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int wdl = wordDict[j].size();
                if (s.substr(i, wdl) == wordDict[j])
                {
                    if (i + wdl < m)
                        dp[i] = dp[i] || dp[i + wdl];
                    else
                        dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};

int main(int, char **)
{

    Solution s;

    // 1
    // string s1("leetcode");
    // vector<string> wordDict{"leet", "code"};

    // 1
    // string s1("applepenapple");
    // vector<string> wordDict{"apple", "pen"};

    // 0
    string s1("catsandog");
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};

    // auto ans = s.wordBreak_v1(s1, wordDict);
    // auto ans = s.wordBreak_v2(s1, wordDict);
    auto ans = s.wordBreak_v3(s1, wordDict);
    cout << ans << endl;
}