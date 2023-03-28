#include <iostream>
#include "stdc++.h"
#include "tool.h"

using namespace std;
int main() {
    int n;//糖果数量
    int * nums = new int[n]{0};
    int * a = new int[n]{0};
    int * dp = new int[n]{0};
    dp[0] = nums[0];//
    dp[1] = nums[1];//
    dp[2] = nums[2];//
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    //dp[i] 表示前i个糖果的最大值
    //dp[i] = i 
    for (int i = 3; i < n; i++)
    {
        dp[i] = dp[i-2]+a[i-1] > dp[i-3]+a[i-1] ? dp[i-2]+a[i-1] : dp[i-3]+a[i-1];
    }
    
    cout << dp[n-1];
    delete nums;
    delete dp;
    return 0;
}



// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> datas;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> datas[i][0];
//         for (int j = 1; j <= datas[i][0]; j++)
//         {
//             cin >> datas[i][j];
//         }
//     }
//     cout << "n=" << n << endl;
//     printArr2(datas[0]);
    
//     return 0;
// }