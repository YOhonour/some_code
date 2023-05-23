/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int all = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            all += nums[i];
        }
        if (all % 2 != 0)
            return false;
        int target = all / 2;
        return target == pack(nums, nums, target);
    }
    int pack(vector<int> &weights, vector<int> &values, int maxPackWeight)
    {
        vector<int> dp(maxPackWeight + 1, 0);
        for (int i = 0; i < weights.size(); i++)
        {
            for (int j = maxPackWeight; j >= 0; j--)
            {
                if (j - weights[i] >= 0)
                {
                    dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
                }
            }
        }
        return dp[maxPackWeight];
    }
};
int main()
{
    Solution solu;
    vector<int> nums = {1, 2, 5};
    cout << solu.canPartition(nums);
}
// @lc code=end
