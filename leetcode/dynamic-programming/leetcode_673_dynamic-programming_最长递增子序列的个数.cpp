/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        vector<int> dp(n,1);// 以nums[i]为结尾的最长递增子序列的长度
        vector<int> cnt(n,1);//以nums[i]为结尾的最长递增子序列的个数
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]){
                    // dp[j] = max(dp[j],dp[i] + 1);
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                ans = cnt[i];
            }else if(dp[i] == maxLen){
                ans += cnt[i];
            }
        }
        return ans;
    }
};
// @lc code=end

