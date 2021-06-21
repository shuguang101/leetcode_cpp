// https://leetcode.com/problems/valid-parentheses

#include <stack>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> map{
            {
                {')', '('},
                {']', '['},
                {'}', '{'},
            },
            3};

        stack<char> st;

        for (char ch : s)
        {
            auto fd = map.find(ch);
            if (fd != map.end())
            {

                if (st.size() == 0 || fd->second != st.top())
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }
        return st.empty();
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;

    // string str = "()[]{}";
    // string str = "(]";
    // string str = "[";
    string str = "";
    bool ans = s.isValid(str);
    cout << ans << endl;
}