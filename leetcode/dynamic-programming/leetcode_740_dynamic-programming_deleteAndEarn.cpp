/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3){
            if(n == 1) return nums[0]; 
            if(n == 2) return max(nums[0],nums[1]);
        }
        vector<int> dp(n,0);
        int res = 0;
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i-2]+ nums[i],dp[i-1]);
        }
        return dp.back();
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxVal = 0;
        
        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal,nums[i]);
        }
        vector<int> sum(maxVal+1,0);
        for(int i = 0; i < n; i++) {
            sum[nums[i]] += nums[i];
        }
        return rob(sum);
    }
};
int main()
{
    vector<int> nums = {2,3,4};
    Solution s;
    s.deleteAndEarn(nums);
}
// @lc code=end

