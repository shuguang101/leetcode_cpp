// https://leetcode.com/problems/jump-game-ii/

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
    int jump_0(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }

        int ans = 0;
        int postion = 0;

        while (true)
        {
            ans++;
            if (postion + nums[postion] >= nums.size() - 1)
            {
                break;
            }

            int distance = 0;
            int new_postion = 0;
            for (int i = 1; i <= nums[postion]; i++)
            {
                if (i + nums[postion + i] > distance)
                {
                    distance = i + nums[postion + i];
                    new_postion = postion + i;
                }
            }
            postion = new_postion;
        }
        return ans;
    }

    int jump(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }

        // 当前节点能达到的最远位置
        int curMaxPos = 0;
        // 下一个节点能达到的最远位置
        int nextMaxPos = 0;
        // 跳跃次数
        int ans = 0;

        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            nextMaxPos = max(i + nums[i], nextMaxPos);
            if (i == curMaxPos)
            {
                ans++;
                curMaxPos = nextMaxPos;
            }
        }
        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> nums{2, 3, 1, 1, 4};

    int ans = s.jump(nums);

    cout << ans << endl;
}