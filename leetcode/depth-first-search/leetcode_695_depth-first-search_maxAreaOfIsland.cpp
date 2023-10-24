/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int max = 0;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                }
            }
        }
        return max;
    }
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        deque<pair<int, int>> cheak;
        cheak.push_back({x, y});
        grid[x][y] = 0;
        int cunt = 0;
        while (!cheak.empty())
        {
            auto aa = *cheak.begin();
            // grid[aa.first][aa.second] = 0;
            cunt++;
            cheak.pop_front();

            if (aa.first + 1 < grid.size() && grid[aa.first + 1][aa.second] == 1)
            {
                cheak.push_back({aa.first + 1, aa.second});
                grid[aa.first + 1][aa.second] = 0;
            }
            if (aa.first - 1 >= 0 && grid[aa.first - 1][aa.second] == 1)
            {
                cheak.push_back({aa.first - 1, aa.second});
                grid[aa.first - 1][aa.second] = 0;
            }
            if (aa.second + 1 < grid[0].size() && grid[aa.first][aa.second + 1] == 1)
            {
                cheak.push_back({aa.first, aa.second + 1});
                grid[aa.first][aa.second + 1] = 0;
            }
            if (aa.second - 1 >= 0 && grid[aa.first][aa.second - 1] == 1)
            {
                cheak.push_back({aa.first, aa.second - 1});
                grid[aa.first][aa.second - 1] = 0;
            }
        }
        max = max < cunt ? cunt : max;
    }
};
int main()
{
    vector<vector<int>> data = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    Solution s;
    s.maxAreaOfIsland(data);
}
// @lc code=end
