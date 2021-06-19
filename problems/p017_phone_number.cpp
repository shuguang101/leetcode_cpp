// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    vector<string> ans;
    string str;

    void backtracking(const string &digits, int index)
    {
        int digit = digits[index] - '0';
        for (char ch : letterMap[digit])
        {
            str.push_back(ch);
            if (index == digits.size() - 1)
            {
                ans.push_back(str);
            }
            else
            {
                backtracking(digits, index + 1);
            }
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        ans.clear();
        str.clear();
        if (digits.size() == 0)
        {
            return ans;
        }
        backtracking(digits, 0);
        return ans;
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;

    // string digits = "23";
    string digits = "";

    auto ans = s.letterCombinations(digits);

    printer.compact(true);
    printer.print("ans =", ans);
}