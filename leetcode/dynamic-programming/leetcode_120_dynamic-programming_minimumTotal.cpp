/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(triangle);
        for(int i = 1; i < m; i++){
            int n = triangle[i].size();
            for(int j = 0; j < n; j ++){
                int upL = j-1 >= 0 ? dp[i-1][j-1] : INT_MAX;
                int upR = j < dp[i-1].size() ? dp[i-1][j] : INT_MAX;
                int upMin = min( upL,  upR);
                dp[i][j] = triangle[i][j] + upMin;
            }
        }
        int res = INT_MAX;
        auto &lastRow = dp.back();
        int n = lastRow.size();
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
    s.minimumTotal(nums);
}
// @lc code=end

