#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 100000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        if (i >= 2) {
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
    return 0;
}
