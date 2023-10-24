/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(i, j, grid);
                }
            }
        }
        return num;
    }
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        if (grid[x][y] != '1')
        {
            return;
        }
        // upLevel_nums++;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1')
            {
                dfs(newX, newY, grid);
            }
        }
    }
};
int main()
{
    vector<vector<char>> data = {{1, 1, 1},
                                {1, 1, 0},
                                {1, 0, 1}};
    Solution s;
    s.numIslands(data);
}
// @lc code=end
