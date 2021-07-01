// https://leetcode.com/problems/jump-game/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> nums{2, 3, 1, 1, 4};
    // vector<int> nums{3, 2, 1, 0, 4};
    // vector<int> nums{0, 3, 2, 1, 0, 4};

    auto ans = s.canJump(nums);

    cout << ans << endl;
}