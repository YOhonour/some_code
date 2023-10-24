#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> memo;

int dfs(const vector<vector<int>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    if (x == n - 1 && y == m - 1) {
        return grid[x][y];
    }

    // 如果该位置已被访问过，直接返回结果
    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    int minValue = INT_MAX;
    for (auto& dir : dirs) {
        int nx = x + dir[0], ny = y + dir[1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            minValue = min(minValue, dfs(grid, nx, ny));
        }
    }

    // 保存结果到memo并返回
    memo[x][y] = grid[x][y] + minValue;
    return memo[x][y];
}

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> grid(n, vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> grid[i][j];
//         }
//     }

//     memo.assign(n, vector<int>(m, -1));
//     cout << dfs(grid, 0, 0) << endl;
//     return 0;
// }


int main() {
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> grid(n, vector<int>(m));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cin >> grid[i][j];
    //     }
    // }
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0}
    };
    
    int n = grid.size(), m = grid[0].size();
    memo.assign(n, vector<int>(m, -1));
    cout << dfs(grid, 0, 0) << endl;
    return 0;
}
