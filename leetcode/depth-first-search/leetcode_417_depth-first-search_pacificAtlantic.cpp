/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n = 0, m = 0;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++)
        {
            dfs(0, i, pacific, heights);
        }
        for (int i = 1; i < n; i++)
        {
            dfs(i, 0, pacific, heights);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(n - 1, i, atlantic, heights);
        }
        for (int i = 0; i < n - 1; i++)
        {
            dfs(i, m - 1, atlantic, heights);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (atlantic[i][j] && pacific[i][j])
                {
                    // vector<int> cell;
                    // cell.emplace_back(i);
                    // cell.emplace_back(j);
                    // res.emplace_back(cell);
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(int x, int y, vector<vector<bool>> &ocean, vector<vector<int>> &heights)
    {
        if (ocean[x][y])
        {
            return;
        }
        ocean[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && heights[newX][newY] >= heights[x][y])
            {
                dfs(newX, newY, ocean, heights);
            }
        }
    }
};
int main()
{
    vector<vector<int>> data = {{1, 2, 2, 3, 5},
                                {3, 2, 3, 4, 4},
                                {2, 4, 5, 3, 1},
                                {6, 7, 1, 4, 5},
                                {5, 1, 1, 2, 4}};
    Solution s;
    s.pacificAtlantic(data);
}
// @lc code=end
