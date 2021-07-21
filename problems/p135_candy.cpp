// https://leetcode.com/problems/palindrome-partitioning/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <cstring>
#include <chrono>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // 24 ms 17.2 MB  faster than 36.77%

        if (ratings.empty())
            return 0;
        if (ratings.size() == 1)
            return 1;

        int n = ratings.size();
        int candies[n];
        int minCandies = 0;

        candies[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = 1 + candies[i - 1];
            }
            else
            {
                candies[i] = 1;
            }
        }

        minCandies += candies[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            {
                candies[i] = 1 + candies[i + 1];
            }
            minCandies += candies[i];
        }

        return minCandies;
    }

    int candy_other_people(vector<int> &ratings)
    {
        // 16 ms

        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        int i;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }

        for (i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (i = 0; i < n; i++)
        {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};

int main(int, char **)
{

    Solution s;

    // // 5
    // vector<int> ratings{1, 0, 2};

    // // 4
    // vector<int> ratings{1, 2, 2};

    // // 11
    // vector<int> ratings{1, 3, 4, 5, 2};

    // time cost test
    int len = 100000;
    vector<int> ratings(len);
    for (int i = 0; i < len; i++)
        // rand()
        ratings[i] = arc4random() % (len + 1);

    double sum = 0;
    int cnt = 100;
    for (int i = 0; i < cnt; i++)
    {
        auto t1 = chrono::steady_clock::now();

        auto ans1 = s.candy(ratings); // 1.990, 2.135, 1.998, 6e-05, 1.980
        // auto ans2 = s.candy_other_people(ratings); // 3.496, 3.571, 3.816, 5.549, 3.559

        auto t2 = chrono::steady_clock::now();

        auto c = std::chrono::duration<double, std::milli>(t2 - t1).count();
        sum += c;
    }

    cout << "avg time cost: " << (sum / cnt) << "ms" << endl;
}