#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countDeletionWays(vector<int>& nums, int k) {
    int n = nums.size();
    
    // 使用动态规划数组dp，dp[i][j]表示从前i个元素中删除j个元素的方式数量
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    
    // 初始化dp数组
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // 如果删除第i个元素
            dp[i][j] = dp[i - 1][j];
            
            // 如果不删除第i个元素，需要满足互为倍数关系
            for (int m = i - 1; m >= 1; --m) {
                if (nums[i - 1] % nums[m - 1] == 0 || nums[m - 1] % nums[i - 1] == 0) {
                    dp[i][j] += dp[m][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    
    return dp[n][k];
}
/*
6 4
1 4 2 3 6 7
*/
int tribonacci(int n) {
        int a = 0, b = 1,c = 1,d = 2;
        for(int i = 3;i <= n; i ++){
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return n == 2 ? 1 : d;
    }
    int sum(int n){
        if(n == 1 || n == 2){
            return 1;
        }
        else {
            return sum(n-1) + sum(n-2);
        }
    }
int main() {
    // int n, k;
    // cin >> n >> k;
    
    // vector<int> nums(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> nums[i];
    // }
    
    // int ways = countDeletionWays(nums, k);
    // cout << ways << endl;
    cout << sum(12);
    return 0;
}
