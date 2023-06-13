#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector<vector<char>> &cur, int row, int clunm)
{
    // 此位置是未填写 直接通过
    if (cur[row][clunm] == '.')
        return true;
    char c = cur[row][clunm];
    // 相同行 相同列 不能有重复
    for (size_t i = 0; i < cur.size(); i++)
    { // 对比时不考虑未填写的 "."
        if (cur[i][clunm] == '.')
            continue;
        else if (cur[i][clunm] == c && i != row)
            return false;
    }
    for (size_t j = 0; j < cur[0].size(); j++)
    {
        if (cur[row][j] == '.')
            continue;
        else if (cur[row][j] == c && j != clunm)
            return false;
    }
    int area_x = (row / 3) * 3, area_y = (clunm / 3) * 3;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            
            if (cur[area_x + i][area_y + j] == '.') continue;
            if ((area_x + i) == row && (area_y + j) == clunm) continue;
            if (cur[area_x + i][area_y + j] == c)
                return false;
            // if (cur[area_x + i][area_y + j] == '.')
            //     continue;
            // char cc = cur[area_x + i][area_y + j];
            // for (size_t k = 0; k < 3; k++)
            // {
            //     for (size_t l = 0; l < 3; l++)
            //     {
            //         if (k == i && l == j)
            //             continue;
            //         if (cur[area_x + k][area_y + l] == cc)
            //             return false;
            //     }
            // }
        }
    }

    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    if (n != 9 || m != 9)
    {
        return false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!isValid(board, i, j))
            {
                return false;
            }
        }
    }
}
int main()
{
    vector<vector<char>> board =
        {
            {'8', '3', '.',      '.', '7', '.',     '.', '.', '.'},
            {'6', '.', '.',      '1', '9', '5',     '.', '.', '.'},
            {'.', '9', '8',      '.', '.', '.',     '.', '6', '.'},
    
            {'8', '.', '.',      '.', '6', '.',     '.', '.', '3'},
            {'4', '.', '.',      '8', '.', '3',     '.', '.', '1'},
            {'7', '.', '.',      '.', '2', '.',     '.', '.', '6'},
    
            {'.', '6', '.',      '.', '.', '.',     '2', '8', '.'},
            {'.', '.', '.',      '4', '1', '9',     '.', '.', '5'},
            {'.', '.', '.',      '.', '8', '.',     '.', '7', '9'}};

    cout << isValidSudoku(board);
    return 0;
}