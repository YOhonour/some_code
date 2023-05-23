#include "../stdc++.h"
using namespace std;

// 二维dp数组
int mostValue(vector<int> &weights, vector<int> &values, int packSize)
{
    vector<vector<int>> dp(values.size(), vector<int>(packSize + 1, 0));
    // dp[i][j]含义：从前i个物品中选择放入重量为j的背包的最大价值
    // 最优价值时的 物品重量
    //  初始化
    for (int j = 0; j < packSize; j++)
    {
        dp[0][j] = j >= weights[0] ? values[0] : 0; // 第0号物品是否能放下
    }
    int totalWeight = 0;
    for (int i = 1; i < weights.size(); i++)
    {
        for (int j = 1; j <= packSize; j++)
        {
            // 考虑第i件物品是否能放进重量为j的背包 它只有两种情况：放入和不放入
            // 放入的条件是重量是否超标
            if (j - weights[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[values.size() - 1][packSize];
}
// 一维dp
int mostValue2(vector<int> &weights, vector<int> &values, int packSize)
{
    vector<int> dp(packSize + 1, 0);
    // dp[i] 重量为i时的最优价值
    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = packSize; j >= 0; j--)
        {
            if (j - weights[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
    }
    return dp[packSize];
}
int pack(vector<int> &ws, vector<int> &vs, int maxSize)
{
    vector<int> ans;
    vector<int> dp(maxSize + 1, 0);
    for (int i = 0; i < ws.size(); i++)
    {
        for (int j = maxSize; j >= 0; j--)
        {
            if (j - ws[i] >= 0 && dp[j - ws[i]] + vs[i] > dp[j])
            {
                dp[j] = dp[j - ws[i]] + vs[i];
                if (j == maxSize)
                {
                    ans.push_back(i);
                }
            }
        }
    }
    // for (auto it = ans.rbegin(); it != ans.rend(); it++)
    // {
    //     ws.erase(ws.begin() += (*it));
    //     vs.erase(vs.begin() += (*it));
    // }
    return dp.back();
}
int main()
{
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << pack(nums, nums, 3);
    return 0;
}