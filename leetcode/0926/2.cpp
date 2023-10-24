#include <iostream>
#include <vector>
using namespace std;

vector<int> p, w;
int n, k;
int maxP = 0;

void dfs(int idx, int currentP, int currentW) {
    // 到达叶子结点
    if (idx == n) {
        if (currentP == currentW * k) {
            maxP = max(maxP, currentP);
        }
        return;
    }
    
    // 不选择当前物品
    dfs(idx + 1, currentP, currentW);

    // 选择当前物品
    dfs(idx + 1, currentP + p[idx], currentW + w[idx]);
}

int main() {
    cin >> n >> k;
    p.resize(n);
    w.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    dfs(0, 0, 0);

    cout << (maxP > 0 ? maxP : -1) << endl;
    return 0;
}