// https://leetcode.com/problems/implement-strstr/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    void get_next(int *next, const string &s)
    {
        // longest prefix and suffix, LPS
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            int j = next[i - 1];
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

public:
    int strStr_1(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        if (haystack.size() < needle.size())
        {
            return -1;
        }

        int ans = -1;
        int p1 = 0;
        int p2 = needle.size() - 1;

        while (p1 < haystack.size())
        {
            if (haystack.substr(p1, p2 - p1 + 1) == needle)
            {
                return p1;
            }
            p1++;
            p2++;
        }
        return ans;
    }

    int strStr(string haystack, string needle)
    {
        // kmp
        if (needle.empty())
        {
            return 0;
        }
        if (haystack.length() < needle.length())
        {
            return -1;
        }

        int next[needle.size()];
        get_next(next, needle);
        int j = 0;

        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};

int main(int, char **)
{
    Solution s;
    int ans = s.strStr("ncabc", "ab");
    // int ans = s.strStr("mississippi", "issip");
    cout << ans << endl;

    string a = "abc";
    cout << a.substr(1, 2) << endl;
}