#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i].first >> prices[i].second;
    }
    sort(prices.begin(), prices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second - a.first > b.second - b.first;
    });

    int cnt = 0, cost = 0;
    for (int i = 0; i < n && cnt < y; i++) {
        if (prices[i].first <= prices[i].second || x >= prices[i].first) {
            cnt++;
            cost += prices[i].first <= prices[i].second ? prices[i].first : prices[i].second;
            x -= prices[i].first <= prices[i].second ? prices[i].first : 0;
        }
    }
    cout << cnt << ' ' << cost << endl;
    return 0;
}