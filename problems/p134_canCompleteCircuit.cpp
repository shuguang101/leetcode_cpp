// https://leetcode.com/problems/palindrome-partitioning/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <cstring>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0, curPos = 0, len = gas.size();
        int remainGas = gas[0];

        while (true)
        {
            if (remainGas >= cost[curPos])
            {
                remainGas -= cost[curPos];
                curPos = (curPos + 1) % len;
                remainGas += gas[curPos];
            }
            else
            {
                start = (start - 1 + len) % len;
                remainGas += gas[start];
                remainGas -= cost[start];
            }

            if ((1 + curPos) % len == start)
                break;
        }

        if (remainGas >= cost[curPos])
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};

int main(int, char **)
{
    Solution s;

    // 3
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};

    // // -1
    // vector<int> gas{2, 3, 4};
    // vector<int> cost{3, 4, 3};

    // // -1
    // vector<int> gas{4, 5, 2, 6, 5, 3};
    // vector<int> cost{3, 2, 7, 3, 2, 9};

    auto ans = s.canCompleteCircuit(gas, cost);
    cout << ans << endl;
}