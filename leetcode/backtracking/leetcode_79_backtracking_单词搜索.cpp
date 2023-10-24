/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(i, j, 0, word, board, vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int x, int y, int offset, string &word, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        bool flag = false;
        if (offset == word.size() - 1)
            return true;

        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == false && board[newX][newY] == word.at(offset + 1))
            {
                flag |= dfs(newX, newY, offset + 1, word, board, vis);
            }
        }
        vis[x][y] = false;
        return flag;
    }
};
// @lc code=end
