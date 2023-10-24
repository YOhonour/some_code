/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++)
        {
            dfs(0, i, board, vis);
        }
        for (int i = 1; i < n; i++)
        {
            dfs(i, 0, board, vis);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(n - 1, i, board, vis);
        }
        for (int i = 0; i < n - 1; i++)
        {
            dfs(i, m - 1, board, vis);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        if (board[x][y] != 'O' || vis[x][y])
        {
            return;
        }
        // upLevel_nums++;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == 'O')
            {
                dfs(newX, newY, board, vis);
            }
        }
    }
    void solve2(vector<vector<char>> &board)
    {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = dfs_c(i, j, board, vis);
                }
            }
        }
        int a = board.size();
        return;
    }
    char dfs_c(int x, int y, vector<vector<char>> &board, vector<vector<bool>> vis)
    {

        if (!(x >= 0 && x < n && y >= 0 && y < m))
        {
            return 'O';
        }
        if (vis[x][y] == true)
        {
            return board[x][y];
        }
        if (board[x][y] == 'O')
        {
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dir[i][0], newY = y + dir[i][1];
                board[x][y] = (dfs_c(newX, newY, board,vis) == 'O' || board[x][y] == 'O') ? 'O' : 'X';
            }
        }
        return board[x][y];
    }
};
int main()
{
    vector<vector<char>> data =
        {{'O', 'O', 'O'},
         {'O', 'O', 'O'},
         {'O', 'O', 'O'}};
    Solution s;
    s.solve2(data);
}
// @lc code=end
