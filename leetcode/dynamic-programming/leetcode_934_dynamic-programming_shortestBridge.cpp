/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int res = -1;
    vector<pair<int, int>> origin_st;
    queue<pair<int, int>> origin_q;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shortestBridge(vector<vector<int>> &grid)
    {
        bool flag = false;
        for (int i = 0; i < grid.size() && !flag; i++)
        {
            for (int j = 0; j < grid[0].size() && !flag; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs_change(grid, i, j);
                    flag = true;
                    break;
                }
            }
        }
        // 上一步 将一个岛屿全部变为了3
        //  寻找从3出发 到1的最短距离
        // bfs(origin_st, grid, 0);
        // return res;
        return bfs_(origin_q, grid, 0);
    }
    void bfs(vector<pair<int, int>> &st, vector<vector<int>> &grid, int level)
    {
        vector<pair<int, int>> temp;
        while (!st.empty() && res == -1)
        {
            auto cur = st.back();
            st.pop_back();
            for (auto &di : dir) // 四个方向
            {
                int newX = cur.first + di[0];
                int newY = cur.second + di[1];
                if (!isValid(grid, newX, newY) && grid[newX][newY] != 3)
                {
                    if (grid[newX][newY] == 1)
                    {
                        res = level;
                        return;
                    }
                    else
                    {
                        grid[newX][newY] = 3;
                        temp.push_back({newX, newY});
                    }
                }
            }
        }
        bfs(temp, grid, level + 1);
    }
    int bfs_(queue<pair<int, int>> &q, vector<vector<int>> &grid, int level)
    {
        while (!q.empty())
        {
            int cur_level_len = q.size();
            for (int i = 0; i < cur_level_len; i++)
            {
                auto cur = q.front();
                q.pop();
                for (auto &di : dir) // 四个方向
                {
                    int newX = cur.first + di[0];
                    int newY = cur.second + di[1];
                    if (!isValid(grid, newX, newY) && grid[newX][newY] != 3)
                    {
                        if (grid[newX][newY] == 1)
                        {
                            return level;
                        }
                        else
                        {
                            grid[newX][newY] = 3;
                            q.push({newX, newY});
                        }
                    }
                }
            }
            level++;
        }
    }
    void dfs_change(vector<vector<int>> &grid, int x, int y)
    {
        if (x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size() || grid[x][y] == 0 || grid[x][y] != 1)
            return;
        grid[x][y] = 3;
        origin_st.push_back({x, y}); // 将第一个岛屿的坐标都记下来
        origin_q.push({x, y}); // 将第一个岛屿的坐标都记下来
        dfs_change(grid, x + 1, y);
        dfs_change(grid, x - 1, y);
        dfs_change(grid, x, y + 1);
        dfs_change(grid, x, y - 1);
    }
    bool inline isValid(vector<vector<int>> &grid, int x, int y)
    {
        return x >= grid.size() || x < 0 || y < 0 || y >= grid[0].size();
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, 1, 1},
                                {1, 0, 0, 0, 1},
                                {1, 0, 1, 0, 1},
                                {1, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1}};
    ;
    cout << s.shortestBridge(grid) << endl;

    // for (auto &a : grid)
    // {
    //     for (auto b : a)
    //     {
    //         cout << ' ' << b;
    //     }
    //     cout << endl;
    // }
}
// @lc code=end
