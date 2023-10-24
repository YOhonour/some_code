#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>
using namespace std;

// 全局变量用于方向控制
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// 深度优先搜索
int dfs(int x, int y, vector<vector<int>>& grid, int m, int n,vector<vector<bool>> &vis,bool trick_is_aviliable) {
    if (x < 0 || y < 0 || x >= m || y >= n || vis[x][y] == true) {
        return 0;
    }
    bool flag = false;
    if(grid[x][y] == -1){
        if(trick_is_aviliable){
            grid[x][y] = 0;
            trick_is_aviliable = false;
            flag = true;
        }
    }
    int ret = grid[x][y];
    vis[x][y] = true;// 标记为已访问
    // 在四个方向上进行搜索
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        ret += dfs(nx, ny, grid, m, n, vis,trick_is_aviliable);
    }
    if(flag){
        grid[x][y] = -1;
        trick_is_aviliable = true;
    }
    return ret;
}
//计算最大金币数
int maxGold(vector<vector<int>>& grid){
    int m = grid.size(), n = grid[0].size();
    int max_gold = 0;
    bool flag = true;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == -1){
                // 尝试使用技能 从-1开始向周围搜索
                grid[i][j] = 0;
                vector<vector<bool>> vis(m,vector<bool>(n,false));
                int tempGold = dfs(i, j, grid, m, n,vis,flag);
                max_gold = max(max_gold, tempGold);
                //恢复
                grid[i][j] = -1;
            }
        }
    }
    return max_gold;
}
// 主函数
int main() {
    vector<vector<int>> grid;
    string input;
    while (true){
        getline(cin,input);
        if (input.empty()) {
            break;
        }
        auto re_if = remove_if(input.begin(), input.end(), [](char c) { return c == '[' || c == ']' || c == ' '; });
        input.erase(re_if, input.end());
        //1, 0, -1
        istringstream iss(input);
        vector<int> numbers;
        string temp;
        while (getline(iss, temp, ',')) {
            numbers.push_back(std::stoi(temp));
        }
        grid.push_back(numbers);
    }
    int max_gold = maxGold(grid);
    cout << max_gold; 
    return 0;
}