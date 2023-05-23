/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i < dp.size(); i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(max(j*dp[i-j],j*(i-j)),dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

