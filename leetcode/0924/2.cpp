#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getMin(vector<int> &a,vector<int> &b){
    int n = a.size();
    vector<int> diff(n);
    // 计算差值数组diff
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }

    // 对差值数组diff排序
    sort(diff.begin(), diff.end());

    // 计算中位数
    int median = diff[n / 2];

    long long min_distance = 0; // 使用长整型以防溢出

    // 计算最小距离
    for (int i = 0; i < n; i++) {
        min_distance += abs(diff[i] - median);
    }
    return min_distance;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    // 读取数组a和b
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    
    cout << getMin(a,b) << endl;
    return 0;
}
/*
3
1 4 1
4 1 4
*/