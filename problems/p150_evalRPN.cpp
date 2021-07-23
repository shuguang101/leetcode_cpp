#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN_v1(vector<string> &tokens)
    {
        stack<string> s;
        stack<int> nums;

        int len = tokens.size();
        for (int i = len - 1; i >= 0; i--)
        {
            s.push(tokens[i]);
        }

        while (!s.empty())
        {
            auto top = s.top();
            s.pop();

            if (top == "+" || top == "-" || top == "*" || top == "/")
            {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                if (top == "+")
                {
                    nums.push(num1 + num2);
                }
                else if (top == "-")
                {
                    nums.push(num1 - num2);
                }
                else if (top == "*")
                {
                    nums.push(num1 * num2);
                }
                else if (top == "/")
                {
                    nums.push(num1 / num2);
                }
            }
            else
            {
                nums.push(stoi(top));
            }
        }
        return nums.top();
    }

    int evalRPN_v2(vector<string> &tokens)
    {
        stack<int> nums;
        int len = tokens.size();
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            // string token = tokens[i];  // 减少复制
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                if (tokens[i] == "+") result=num1+num2;  // nums.push(num1 + num2);
                if (tokens[i] == "-") result=num1-num2;  // nums.push(num1 - num2);
                if (tokens[i] == "*") result=num1*num2;  // nums.push(num1 * num2);
                if (tokens[i] == "/") result=num1/num2;  // nums.push(num1 / num2);
                nums.push(result);
            }
            else
            {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};

int main(int, char **)
{
    // 9
    // vector<string> tokens{"2", "1", "+", "3", "*"};

    // 6
    // vector<string> tokens{"4", "13", "5", "/", "+"};

    // 22
    vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    Solution s;
    // auto ans = s.evalRPN_v1(tokens);
    auto ans = s.evalRPN_v2(tokens);

    cout << ans << endl;
}