/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(matrix);
        for(int row = 1; row < n; row++){
            for(int col = 0; col < n; col ++){
                int upL = col-1 < 0 ? INT_MAX : dp[row-1][col-1];
                int up = dp[row-1][col];
                int upR = col+1 >= n ? INT_MAX : dp[row-1][col+1];
                dp[row][col] = min(min(upL,upR),up) + dp[row][col];
            }
        }
        int res = INT_MAX;
        auto &lastRow = dp.back();
        for(int j = 0; j < n; j ++){
            res = min(res,lastRow[j]);
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> nums = {
   {2},
  {3,4},
 {6,5,7},
{4,1,8,3}
};
    Solution s;
    s.minFallingPathSum(nums);
}
// @lc code=end

