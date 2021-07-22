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
    string path;
    bool result;

    bool trackingBack_v2(string &s, vector<string> &wordDict)
    {
        int len = wordDict.size();
        for (int i = 0; i < len; i++)
        {
            int l = path.size();
            path.append(wordDict[i]);

            if (path == s)
                return true;
            if (path.size() < s.size() && trackingBack_v2(s, wordDict))
                return true;

            path = path.substr(0, l);
        }
        return false;
    }

    bool trackingBack_v1(string &s, unordered_set<string> &set, int startPos)
    {
        int len = s.size();
        for (int segPos = startPos + 1; segPos < len; segPos++)
        {
            string s1 = s.substr(startPos, segPos - startPos);
            if (set.find(s1) != set.end())
            {
                if (trackingBack_v1(s, set, segPos))
                    return true;
            }
            string s2 = s.substr(segPos, len - segPos);

            if (set.find(s1) != set.end() && set.find(s2) != set.end())
                return true;
        }
        return false;
    }

    void backtracking_v3(string &s, unordered_map<char, vector<string>> &map, int startPos)
    {
        //  超时
        if (startPos < s.size())
        {
            auto fd = map.find(s[startPos]);

            if (fd != map.end())
            {
                vector<string> items = fd->second;
                int items_len = items.size();
                for (int i = 0; i < items_len; i++)
                {
                    auto item = items[i];
                    auto item_len = item.size();
                    auto cmp_s = s.substr(startPos, item_len);

                    if (startPos + item_len == s.size() && item == cmp_s)
                    {
                        result = true;
                        return;
                    }
                    else if (startPos + item_len < s.size() && item == cmp_s)
                    {
                        backtracking_v3(s, map, startPos + item_len);
                    }

                    if (result)
                        return;
                }
            }
        }
    }

public:
    bool wordBreak_v1(string s, vector<string> &wordDict)
    {
        // 超时
        unordered_set<string> set;

        for (int i = 0; i < wordDict.size(); i++)
        {
            set.insert(wordDict[i]);
        }

        if (set.find(s) != set.end())
            return true;

        return trackingBack_v1(s, set, 0);
    }

    bool wordBreak_v2(string s, vector<string> &wordDict)
    {
        // 超时
        path.clear();
        return trackingBack_v2(s, wordDict);
    }

    bool wordBreak_v3(string s, vector<string> &wordDict)
    {
        result = false;
        unordered_map<char, vector<string>> map;

        int len = wordDict.size();
        for (int i = 0; i < len; i++)
        {
            string word = wordDict[i];
            if (map.find(word[0]) != map.end())
            {
                vector<string> v = map.find(word[0])->second;
                v.push_back(word);
                map[word[0]] = v;
            }
            else
            {
                vector<string> v{word};
                map[word[0]] = v;
            }
        }
        backtracking_v3(s, map, 0);
        return result;
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