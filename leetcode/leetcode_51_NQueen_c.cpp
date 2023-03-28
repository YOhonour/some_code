#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<string>> result; // 结果
// cur 此时的 待检测解 x: 行坐标 y列坐标
bool valied(const vector<string> &cur, int x, int y) {
    // 某一行 某一列 还有相同斜线
    if (x == 0) return true;
    for (int i = 0; i < x; i++)// 上方
        if (cur[i][y] == 'Q') return false;
    int t_x = x - 1, t_y = y + 1; // 45°斜上方是否有 下标边界为 x=0，y=n-1
    while (t_x >= 0 && t_y < cur[0].length())
        if (cur[t_x--][t_y++] == 'Q')
            return false;
    t_x = x - 1, t_y = y - 1; // 左上下标边界时 x=0，y=0
    while (t_x >= 0 && t_y >= 0)
        if (cur[t_x--][t_y--] == 'Q')
            return false;
    return true;
}
// x: 行，n: n皇后问题的大小
void backtracking(vector<string> &cur, int x, int y, int n)
{
    // 边界
    if (x == n - 1) {
        for (int i = 0; i < n; i++) {
            if (valied(cur, x, i)) {
                cur[x][i] = 'Q';
                result.push_back(vector<string>(cur));
                cur[x][i] = '.';
            }
        }
        return;
    }
    //常规情况
    for (int i = 0; i < n; i++) {
        if (valied(cur, x, i)) {
            // 如果此位置(x,y) 可以放置Q，就执行放置并且进入下一层搜索，下层搜索结束后，取消赋值，进入本行的下一个位置
            cur[x][i] = 'Q';
            backtracking(cur, x + 1, 0, n);
            cur[x][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<string> re(n, string(n, '.'));
    backtracking(re, 0, 0, n);
    return result;
}
void printQ(vector<string> &res)
{
    cout << "[" << endl;

    for (auto &a : res)
    {
        cout << "  " << a << endl;
    }
    cout << "]," << endl;
}

int main()
{
    int n = 5;
    vector<string> re(n, string(n, '.'));
    backtracking(re, 0, 0, n);
    for (int i = 0; i < result.size(); i++)
    {
        printQ(result[i]);
    }

    return 0;
}