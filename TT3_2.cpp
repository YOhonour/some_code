#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, u, v;
    cin >> n >> u >> v;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefixSum(n);
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    unordered_map<long long, int> prefixSumDividedCount;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        long long currentPrefixSum = (i > 0) ? prefixSum[i] : 0;
        long long prefixSumDivided = currentPrefixSum / v;

        // 查找是否有prefixSumDivided - u的值，如果有，累加次数
        if (prefixSumDividedCount.find(prefixSumDivided - u) != prefixSumDividedCount.end()) {
            count += prefixSumDividedCount[prefixSumDivided - u];
        }

        // 更新哈希表
        prefixSumDividedCount[prefixSumDivided]++;

    }

    cout << count << endl;

    return 0;
}
