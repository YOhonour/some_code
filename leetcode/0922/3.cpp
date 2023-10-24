#include <iostream>
#include <vector>
#include <string>
using namespace std;

// const int MOD = 1e9 + 7;

// int countWays(string t) {
//     int n = t.size();
//     vector<int> dp(n+1, 0);
//     dp[0] = 1;  // 初始状态，空串有1种生成方式

//     for (int i = 1; i <= n; i++) {
//         dp[i] = dp[i-1];  // 添加一个字符的方式
//         for (int j = 2; j <= i/2; j++) {  // 修改了这里的条件
//             if (t.substr(i-j, j) == t.substr(i-2*j+1, j)) {
//                 dp[i] += dp[i-j];
//                 dp[i] %= MOD;
//             }
//         }
//     }
//     return dp[n];
// }

// int main() {
//     string t;
//     cin >> t;
//     cout << countWays(t) << endl;
//     return 0;
// }
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countWays(string t) {
    int n = t.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // 初始化空字符串的构造方式为1种

    for (int i = 1; i <= n; ++i) {
        // 添加一个字符的方法
        dp[i] += dp[i-1];
        dp[i] %= MOD;

        // 通过复制子串得到的方法
        for (int len = 2; i - 2 * len >= 0 && len <= i; ++len) {
            if (t.substr(i - len, len) == t.substr(i - len * 2, len)) {
                dp[i] += dp[i-len];
                dp[i] %= MOD;
            }
        }
    }

    return dp[n];
}
class D{
    int a;
    public:
    D(int i = 0):a(i){}
    void show(){cout << a ;}
};
struct st
{
    int a;
    short b;
    char err[32];
};

// 测试代码
int main() {
    int a = 3,b = 4,c = 5;
    int x = a || b + c && b - c;
    int y = !(a+b) + c - 1 & b + c/2;
    D o1(2);
    D& o2 = o1;
    D *o3 = &o1;
    o1.show();
    o2.show();
    o3->show();
    (*o3).show();
    cout << ' ' << x << ' ' << y << endl;
    st s_t[16];
    char *p = (char*)(s_t[2].err + 32);
    cout << p - (char*)s_t << endl;
    cout <<sizeof(st) << endl;
    return 0;
}
/*
超长序列
题目描述
有一个长度无限长的自然数序列 A，下标从 0 开始。初始时所有数均为 0。先进行n 次修改，然后进行 m 次查询。每次修改给出三个数l，r，x，将范围Al~Ar中的每一个数变成它与x 的异或值。
每次查询给出一个数字 p表示查询 Ap，的值。
输入描述
第一行两个整教n，m，意义如上文所述。
接下来n行3个整数l，r，x，意义如上文所述。
接下来m行1个整数p，意义如上文所述。
对于所有的数据，1<=n，m<=10^4，l<=r，0<=l，r，p<= 10^18，0 <= x <= 10^9
输出描述
输出m行每行一个整数，表示答案
*/