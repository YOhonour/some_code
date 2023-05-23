/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int all = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            all += nums[i];
        }
        int x = (all + target) / 2;
        int ans = 0;
        while (1)
        {

            int t = pack(nums, nums, x);
            if (t == target)
            {
                ans++;
            }
            else
                break;
        }
        return ans;
    }
    int pack(vector<int> &ws, vector<int> &vs, int maxSize)
    {

        vector<int> dp(maxSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < ws.size(); i++)
        {
            for (int j = maxSize; j >= ws[i]; j--)
            {
                    dp[j] += dp[j - ws[i]];
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << solu.findTargetSumWays(nums, 3);
}
// @lc code=end
