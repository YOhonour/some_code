#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// 计算x的逆元
long long mod_inverse(long long x) {
    long long result = 1;
    long long base = x;
    long long exponent = MOD - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}
// 计算组合数C(n, k)
long long calculate_combinations(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // 优化，选择较小的k
    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = (result * (n - i + 1)) % MOD;
        result = (result * mod_inverse(i)) % MOD;
    }
    return result;
}


int main() {
    string n;
    int k;
    cin >> n >> k;
    
    int count_5 = 0;
    int count_3 = 0;
    
    for (char digit : n) {
        if (digit == '5') {
            count_5++;
        } else if (digit == '3') {
            count_3++;
        }
    }

    long long ways_to_make_3_multiple = calculate_combinations(count_5, k);
    long long ways_to_make_25_multiple = calculate_combinations(count_3, k);
    
    long long result = (ways_to_make_3_multiple * ways_to_make_25_multiple) % MOD;
    cout << result << endl;
    
    return 0;
}
