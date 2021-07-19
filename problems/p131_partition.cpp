// https://leetcode.com/problems/palindrome-partitioning/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <cstring>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s)
    {
        int end = s.size() / 2 - 1;
        int len = s.size();
        for (int i = 0; i <= end; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    void trackingBack(string &s, int startPos, int segPos)
    {
        int len = s.size();
        for (int i = segPos; i < len; i++)
        {
            string s1 = s.substr(startPos, i - startPos);
            string s2 = s.substr(i, len - i);

            if (isPalindrome(s1))
            {
                path.push_back(s1);

                trackingBack(s, i, i + 1);

                if (isPalindrome(s2))
                {
                    path.push_back(s2);
                    ans.push_back(path);
                    path.pop_back();
                }

                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        path.clear();
        ans.clear();

        if (s.empty())
        {
            return ans;
        }
        if (isPalindrome(s))
        {
            path.push_back(s);
            ans.push_back(path);
            path.clear();
        }

        trackingBack(s, 0, 1);

        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    // // ["a"
    // string str("a");

    // [["a","a" ],["aa" ]]
    string str("aa");

    // // [["a","a","b"],["aa","b"]]
    // string str("aab");

    auto ans = s.partition(str);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}