#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> result; // 结果
int flag = 0;
vector<char> chars = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
// cur 此时的 待检测解 x: 行坐标 y列坐标
bool valied(const vector<vector<char>>& cur, int row, int clunm, char c)
{
    // 此位置必须是未填写
    if (cur[row][clunm] != '.')
        return false;
    // 相同行 相同列 不能有重复
    for (size_t i = 0; i < cur.size(); i++)
    { // 对比时不考虑未填写的 "."
        if (cur[i][clunm] == '.')
            continue;
        else if (cur[i][clunm] == c)
            return false;
    }
    for (size_t j = 0; j < cur[0].size(); j++)
    {
        if (cur[row][j] == '.')
            continue;
        else if (cur[row][j] == c)
            return false;
    }
    int area_x = (row / 3) * 3, area_y = (clunm / 3) * 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if ((area_x + i) == row && (area_y + j) == clunm) continue;
            if (cur[area_x + i][area_y + j] == c)
                return false;
        }
    }

    return true;
}
// x，y 坐标
void backtracking(vector<vector<char>>& cur, int x, int y)
{
    if (flag == 1) return;
    // 边界
    if (x == ((int)cur.size() - 1) && y == ((int)cur.back().size() - 1)) // 最后一行 最后一列
    {
        // 放置条件是未填写
        if (cur[x][y] == '.')
        {
            for (int j = 1; j < chars.size(); j++) // 依次尝试
            {
                if (valied(cur, x, y, chars[j]))
                {
                    cur[x][y] = chars[j];//复制
                    result = vector<vector<char>>(cur);
                    flag = 1;
                }
            }
        }
        else
        { // 已经有了
            result = vector<vector<char>>(cur);
            flag = 1;
        }
        return;
    }
    // 常规情况 先确定一个 直接向下一个位置
    if (cur[x][y] == '.')
    {
        for (int j = 1; j < chars.size(); j++) // 依次尝试
        {
            if (valied(cur, x, y, chars[j]))
            {
                cur[x][y] = chars[j];
                // 计算下一个下标
                int nx = y == ((int)cur[0].size() - 1) ? x + 1 : x;
                int ny = y == ((int)cur[0].size() - 1) ? 0 : y + 1;
                backtracking(cur, nx, ny);
                cur[x][y] = '.';
            }
        }
    }
    else
    {
        // 直接进入下一个
        int nx = y == ((int)cur[0].size() - 1) ? x + 1 : x;
        int ny = y == ((int)cur[0].size() - 1) ? 0 : y + 1;
        backtracking(cur, nx, ny);
    }
}
void solveSudoku(vector<vector<char>>& board)
{
    backtracking(board, 0, 0);
    board = result;
}
void printQ(vector<string>& res)
{
    cout << "[" << endl;

    for (auto& a : res)
    {
        cout << "  " << a << endl;
    }
    cout << "]," << endl;
}

int main()
{
    int n = 5;
    vector<vector<char>> cur =
    { {'.','.','9','7','4','8','.','.','.'},
    {'7','.','.','.','.','.','.','.','.'},
    {'.','2','.','1','.','9','.','.','.'},
    {'.','.','7','.','.','.','2','4','.'},
    {'.','6','4','.','1','.','5','9','.'},
    {'.','9','8','.','.','.','3','.','.'},
    {'.','.','.','8','.','3','.','2','.'},
    {'.','.','.','.','.','.','.','.','6'},
    {'.','.','.','2','7','5','9','.','.'} };


    solveSudoku(cur);
    for (int i = 0; i < cur.size(); i++)
    {
        for (size_t j = 0; j < cur[i].size(); j++)
        {
            cout << "'" << cur[i][j] << "',";
        }
        cout << endl;
    }
    cout << "=====================" << endl;

    return 0;
}