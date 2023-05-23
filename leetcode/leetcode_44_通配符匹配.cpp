/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < dp.at(0).size(); i++)
        {
            dp[0][i] = p.at(i-1) == '*' ? dp[0][i-1] : false; // 因为要求全文匹配，如果p中有字母，就不能匹配上，
        }
        
        for (int i = 1; i < s.size() + 1; i++)
        {
            for (int j = 1; j < p.size() + 1; j++)
            {
                if (p.at(j - 1) == '*')
                {
                    dp[i][j] = dp[i - 1][j] || // 使用这个*号，看s上一个阶段的值
                               dp[i][j - 1];   // 不使用这个*号
                } else 
                // d[i][j] 表示s的前i个字符与，p的前j个是否能匹配
                if (s.at(i - 1) == p.at(j - 1) || p.at(j - 1) == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
