// https://leetcode-cn.com/problems/two-sum/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans(2, 0);
        unordered_map<int, int> umap;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            int a = nums[i];
            int b = target - a;
            auto fd = umap.find(b);

            if (fd != umap.end())
            {
                ans[0] = fd->second;
                ans[1] = i;
                break;
            }
            else
            {
                umap[nums[i]] = i;
            }
        }

        return ans;
    }
};

int main(int, char **)
{
    vector<int> nums{2, 7, 11, 15};
    int target = 13;

    Solution s;

    vector<int> ans = s.twoSum(nums, target);
    cout << ans.size() << endl;
    cout << ans[0] << endl;
    cout << ans[1] << endl;
}