#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
int GiveChargeSum(int N)
{
    vector<int> coins = {1, 2, 5, 10};
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    // dp[2] = 1;
    // dp[5] = 1;
    // dp[10] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i < N + 1; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    return dp[N];
}
vector<int> getFraction(float a)
{
    int res_N;
    int res_M;
    float minDiff = numeric_limits<float>::max();
    for (int m = 1; m <= 200; m++)
    {

        int N_MAX = m-1;
        for (int n = 0; n <= N_MAX; n++)
        {
            float fv = (float)n / (float)m;
            float diff = abs(fv - a);
            if(diff < minDiff){
                minDiff = diff;
                res_N = n;
                res_M = m;
            }
        }
        
    }
    return {res_N,res_M};
}
int main()
{
    cout << GiveChargeSum(37);
    return 0;
}