#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main() {
    string line;
    vector<int> numbers;
    // 持续从标准输入读取行，直到遇到空行或 EOF
    while (true) {
        getline(cin, line);
        if (line.empty()) break;

        // 将字符串转换为整数并存储
        stringstream ss(line);
        int num;
        ss >> num;
        numbers.push_back(num);
    }
    for(int n : numbers){
        long long max_points = n * (n - 1) / 2;
        long long min_points = max((n - 1) * (n - 2) / 2,n-1);

        for (long long i = max_points; i >= min_points; --i) {
            cout << i;
            if (i != min_points) {
                cout << ",";
            }
        }
        if(max_points != 0) cout << ',' << 0;
        cout << endl;
    }

    return 0;
}
