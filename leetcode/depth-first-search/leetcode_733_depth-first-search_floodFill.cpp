/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size();
        m = image[0].size();
        vector<vector<int>> res(image);
        int num = 0;
        int x = sr, y = sc;
        dfs(sr, sc, color, image[x][y], image, res);
        return res;
    }
    void dfs(int x, int y, int color, int tempValue, vector<vector<int>> &image, vector<vector<int>> &res)
    {
        if (image[x][y] != tempValue)
        {
            return;
        }
        res[x][y] = color;
        image[x][y] = -1;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && image[newX][newY] == tempValue)
            {
                dfs(newX, newY, color, tempValue, image, res);
            }
        }
    }
};
int main()
{
    vector<vector<int>> data = {{1, 1, 1},
                                {1, 1, 0},
                                {1, 0, 1}};
    Solution s;
    s.floodFill(data, 1, 1, 2);
}
// @lc code=end
