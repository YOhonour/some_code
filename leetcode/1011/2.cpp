#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long getMaxHappiness(vector<int> books) {
    sort(books.begin(), books.end()); // 按照满意度进行排序
    int n = books.size();
    long long maxHappiness = 0;

    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for(int j = i; j < n; j++) {
            cur += (j - i + 1)*books[j];
        }
        maxHappiness = max(maxHappiness, cur);
    }
    return maxHappiness;
}

int main() {
    // 读入数据
    string input;
    getline(cin, input);
    vector<int> books;
    string tmp = "";
    for (char c : input) {
        if (c == ',') {
            books.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (!tmp.empty()) {
        books.push_back(stoi(tmp));
    }

    // 计算最大的快乐时间
    int result = getMaxHappiness(books);
    cout << result << endl;
    return 0;
}
