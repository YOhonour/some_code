/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int m, n;
        char inline count(int x, int y, vector<vector<char>> &board)
    {
        char c = '0';
        for (int i = 0; i < dir.size(); i++)
        {
            int newX = x + dir[i][0], newY = y + dir[i][1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'M')
            {
                c++;
            }
        }
        if (c == '0')
            c = 'B';
        return c;
    }
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        m = board.size();
        n = board[0].size();

        dfs(click[0], click[1], board);
        return board;
    }
    void dfs(int x, int y, vector<vector<char>> &board)
    {
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] != 'E')
            return;
        board[x][y] = count(x, y, board);
        if (board[x][y] == 'B')
        {
            for (int i = 0; i < dir.size(); i++)
            {

                int newX = x + dir[i][0], newY = y + dir[i][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n)
                {
                    dfs(newX, newY, board);
                }
            }
        }
    }
};
int main()
{
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    string s = "newX = x + dir[i][0], newY = y + dir[i][1];\nif (newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'M')\n{\nc++;\n}";
    for (int i = 0; i < dir.size(); i++)
    {
        printf("newX = x + %d, newY = y + %d;\nif (newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'M')\n{\nc++;\n}\n", dir[i][0], dir[i][1]);
    }
}
// @lc code=end
