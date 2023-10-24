#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    // 计算最大公因数（GCD）的函数
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int count(vector<int>& nums, int u, int v) {
    int n = nums.size();
    vector<int> prefixSum(n + 1);

    // 计算数组的前缀和
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // 计算子区间的和
            int subarraySum = prefixSum[j] - prefixSum[i - 1];
            int subarrayLen = j - i + 1;

            // 检查子区间的平均值是否等于 u/v
            if (subarraySum * v == subarrayLen * u) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = count(arr, u, v);
    cout << result << endl;

    return 0;
}