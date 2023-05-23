/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, false));
        for (int i = 0; i < dp.size(); i++)
            dp[i][0] = i;
        for (int i = 0; i < dp.at(0).size(); i++)
            dp[0][i] = i;
        for (int i = 1; i < word1.size() + 1; i++)
        {
            for (int j = 1; j < word2.size() + 1; j++)
            {
                // 替换一个字符 dp[i - 1][j - 1] + 1
                // 删除一个字符 dp[i - 1][j] + 1  （从word1中删除一个）
                // 插入一个字符 dp[i][j - 1] + 1  （从word2中删除一个，或者说不考虑word2一个字符）
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                if (word1.at(i - 1) == word2.at(j - 1))
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    string w1 = "horse";
    string w2 = "ros";

    Solution solu;
    cout << solu.minDistance(w1, w2);
}
// @lc code=end
