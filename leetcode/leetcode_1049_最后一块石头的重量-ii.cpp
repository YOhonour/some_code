/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int all = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            all += stones[i];
        }
        int target = all - all / 2;
        int maxVal = pack(stones,stones,target);
        return abs(all - maxVal - maxVal);
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
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << solu.lastStoneWeightII(nums);
}
// @lc code=end

