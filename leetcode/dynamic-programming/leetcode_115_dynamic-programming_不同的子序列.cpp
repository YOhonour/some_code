/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        for(int i = m-1; i >= 0; i--) {
            char c = s[i];
            for(int j = n-1; j >= 0; j--) {
                dp[i][j] = dp[i+1][j];
                if(c == t[j]){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
int main()
{
    vector<vector<int>> he = {{1, 4, 3, 1, 3, 2},
                              {3, 2, 1, 3, 2, 4},
                              {2, 3, 3, 2, 3, 1}};
    Solution s;
}
// @lc code=end
