#include "../stdc++.h"
using namespace std;

int pack(vector<int> weights, vector<int> values, int maxPackWeight)
{
    // dp[i] : 背包大小为i时，所能拿到的最多的价值
    vector<int> dp(maxPackWeight + 1, 0);
    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = maxPackWeight; j >= 0; j--)
        // for (int j = 0; j < maxPackWeight + 1; j++)
        {
            // 从高到低遍历原因是：因为高背包值的运算是由低位dp[j - weights[i]]加上values[i]
            // 有可能dp[j - weights[i]]中已经添加了values[i] ， 这样就加了两遍
            if (j - weights[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
    }
    return dp.back();
}

int main()
{
    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    cout << pack(weights, values, 4);
    return 0;
}