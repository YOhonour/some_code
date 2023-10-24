#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestUniqueFlavorsSegment(int L, vector<int>& a) {
    int n = a.size();
    int left = 0;
    int maxLength = 0;
    unordered_map<int, int> flavorCounts;

    for (int right = 0; right < n; ++right) {
        // 更新当前右指针指向的口味在字典中的计数
        flavorCounts[a[right]]++;

        // 如果当前口味的种类数大于1，移动左指针缩小窗口
        while (flavorCounts[a[right]] > 1) {
            flavorCounts[a[left]]--;
            if (flavorCounts[a[left]] == 0) {
                flavorCounts.erase(a[left]);
            }
            left++;
        }

        // 更新最大长度
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int L;
    cin >> L;
    vector<int> a(L);

    for (int i = 0; i < L; ++i) {
        cin >> a[i];
    }

    int result = longestUniqueFlavorsSegment(L, a);
    cout << result << endl;

    return 0;
}
/*
5
1 2 3 3 4
*/ 
