/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxLen = 0;
        for(int j = 1; j < n; j++) {
            for(int i = j-1; i >= 0; i--) {
                if(nums[i] < nums[j]){
                    dp[j] = max(dp[j],dp[i] + 1);
                }
            }
            maxLen = max(maxLen,dp[j]);
        }
        return maxLen;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> f,ans;
        int n = 0;
        for(int i = 0; i < obstacles.size(); i++) {
            if(int num = obstacles[i]; f.empty() || f.back() <= num){
                f.push_back(num);
                ans.push_back(f.size());
            }else{
                int index = upper_bound(f.begin(),f.end(),num) - f.begin();
                ans.push_back(index + 1);
                f[index] = num;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,3,2};
    Solution s;
    s.longestObstacleCourseAtEachPosition(nums);
}
// @lc code=end

