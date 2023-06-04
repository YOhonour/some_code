#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
int GiveChargeSum(int N)
{
    vector<int> coins = {1,2,5,10};
    vector<int> dp(N+1,0);
    dp[0] = 1;
    // dp[2] = 1;
    // dp[5] = 1;
    // dp[10] = 1;
    for(int coin : coins){
        for(int i = coin; i < N+1; i++) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[N];
}
int main()
{
    cout << GiveChargeSum(37);
    return 0;
}