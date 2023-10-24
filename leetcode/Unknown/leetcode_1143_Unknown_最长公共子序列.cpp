/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        //dp[i][j] 长度为i 的text1,与 j 的最长公共子序列
        for(int j = 0; j < n; j++) {
            dp[0][j] = true;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

