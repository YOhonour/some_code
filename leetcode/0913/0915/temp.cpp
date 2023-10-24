#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;



set<int> possiblelntersections(int n){
    set<int> res;
    vector<int> dp(n+1,0);
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + (i-1);

    }
    res.insert(0);
    res.insert(dp[n]);
    for(int i = 1; i < n ; i++) {
        int rem = n-i;
        set<int> temp = possiblelntersections(rem);
        for(int t : temp){
            res.insert(dp[i] + t + i * rem);
        }
    }
    return res;
}
int main() {
    string line;
    vector<int> numbers;
    for(int i = 1; i < 21; i++) {
        numbers.push_back(i);
    }
    // // 持续从标准输入读取行，直到遇到空行或 EOF
    // while (true) {
    //     getline(cin, line);
    //     if (line.empty()) break;

    //     // 将字符串转换为整数并存储
    //     stringstream ss(line);
    //     int num;
    //     ss >> num;
    //     numbers.push_back(num);
    // }

    for (int n : numbers) {
        long long max_points = n * (n - 1) / 2;
        long long min_points = max((n - 1) * (n - 2) / 2, n-1);

        for (long long i = max_points; i >= min_points; --i) {
            cout << i;
            if (i != min_points) {
                cout << ",";
            }
        }
        if(max_points!=0){
            cout << ',' << 0;
        }
        cout << endl;
        cout << "+++++++++++++++++++++++" << endl;
        set<int> res = possiblelntersections(n);
        for(auto it = res.rbegin();it != res.rend(); ++it){
            cout << *it;
            auto neit = it;
            ++neit;
            if(neit != res.rend()) cout << ',';

        }
        cout << endl;
        
        cout << "========================" << endl;
    }

    return 0;
}