// https://leetcode.com/problems/restore-ip-addresses/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    vector<string> ans;

    bool isValid(string &s, int left, int right)
    {
        if (right - left <= 0 || right - left > 3)
            return false;

        if (right - left > 1 && s[left] == '0')
            return false;

        int num = 0;
        for (int i = left; i < right; i++)
        {
            if (s[i] > '9' || s[i] < '0')
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }

    void backtracking(string &s, int left, int right, int depth)
    {
        if (depth == 3)
        {
            if (isValid(s, left, s.size()))
                ans.push_back(s);
            return;
        }
        int len = min({right + 3, (int)s.size()});
        for (int i = right; i < len; i++)
        {
            if (isValid(s, left, i))
            {
                s.insert(i, ".");
                backtracking(s, i + 1, i + 2, depth + 1);
                s.erase(i, 1);
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        ans.clear();
        backtracking(s, 0, 1, 0);
        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    string ip_str("010010");
    // string ip_str("25525511135");

    auto ans = s.restoreIpAddresses(ip_str);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}