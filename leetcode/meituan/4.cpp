#include "stdc++.h"
using namespace std;
/*
网在商店里有N个物品，每个物品有原价和折扣价小美相要购买商品。小美拥有X元，一共Y张折扣券
*/
vector<int> shangdian(int N, int X, int Y, vector<vector<int>> prices)
{
    // 分类 ：贪心查找

    // 首先根据折扣价增序排序
    sort(prices.begin(), prices.end(), [&](const vector<int> &a, const vector<int> &b)
         {
             // 按照折扣力度最大排序
             return ((double)a[0] / a[1]) == ((double)b[0] / b[1]) ? a[1] < b[1] : ((double)a[0] / a[1]) > ((double)b[0] / b[1]);
             // return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
         });

    cout << "--------" << endl;

    for (auto item : prices)
    {
        cout << item[0] << " " << item[1] << endl;
    }
    cout << "--------" << endl;
    // 在Y个商品后按照原价排序
    sort(prices.begin() + Y, prices.end(), [&](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    for (auto item : prices)
    {
        cout << item[0] << " " << item[1] << endl;
    }
    cout << "--------" << endl;
    int count = 0;
    int pay = 0;
    int pt = 0;
    while (X > 0)
    {
        // 按照价格从便宜到昂贵购买，将是购买数量最多的optimal
        // 扩展：要求价值最高-> 也需要优先购买折扣商品，但是此时的折扣力度排序
        if (Y > 0)
        {
            if (X >= prices[pt][1])
            {
                pay += prices[pt][1];
                X -= prices[pt][1];
                --Y;
                count++;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (X >= prices[pt][0])
            {
                pay += prices[pt][0];
                X -= prices[pt][0];
                count++;
            }
            else
            {
                break;
            }
        }
        pt++;
    }
    return {count, pay};
}
// int main()
// {
//     vector<vector<int>> prices = {
//         {2, 1},
//         {3, 2},
//         {2, 1},
//         {10, 8},
//         {6, 5},
//         {4, 3},
//         {2, 1},
//         {10, 9},
//         {5, 4},
//         {4, 2}};

//     // vector<vector<int>> prices;

//     // int N,X,Y;
//     // cin >> N >> X >> Y;
//     // for (int i = 0; i < N; i++)
//     // {
//     //     int a,b;
//     //     cin >> a >> b;
//     //     vector<int> t = {a,b};
//     //     prices.push_back(t);
//     // }

//     vector<int> out = shangdian(10, 30, 3, prices);
//     // vector<int> out = shangdian( N,X,Y,prices);

//     cout << out[0] << " " << out[1] << endl;
//     return 0;
// }
const int N = 105;
int n, x, y;
int a[N], b[N];
int dp[N][5001][51];
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    int ans = 0, mon = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            for (int k = 0; k <= y; k++)
            {
                if (dp[i - 1][j][k] == -1)
                    continue;
                if (j <= x - a[i])
                {
                    dp[i][j + a[i]][k] = max(dp[i][j + a[i]][k], dp[i - 1][j][k] + 1);
                    int t = dp[i][j + a[i]][k];
                    if (t > ans)
                        ans = t, mon = j + a[i];
                    else if (t == ans)
                        mon = min(mon, j + a[i]);
                }
                if (j <= x - b[i] && k != y)
                {
                    dp[i][j + b[i]][k + 1] = max(dp[i][j + b[i]][k + 1], dp[i - 1][j][k] + 1);
                    int t = dp[i][j + b[i]][k + 1];
                    if (t > ans)
                        ans = t, mon = j + b[i];
                    else if (t == ans)
                        mon = min(mon, j + b[i]);
                }
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            }
        }
    }
    cout << ans << ' ' << mon << endl;
}
