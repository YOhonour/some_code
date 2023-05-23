#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    obstacleGrid[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < obstacleGrid.size(); i++)
    {
        obstacleGrid[i][0] = obstacleGrid[i][0] == 1 ? 0 : obstacleGrid[i-1][0];
    }
    for (int i = 1; i < obstacleGrid[0].size(); i++)
    {
        obstacleGrid[0][i] = obstacleGrid[0][i] == 1 ? 0 : obstacleGrid[0][i-1];
    }
    for (int i = 1; i < obstacleGrid.size(); i++)
    {
        for (int j = 1; j < obstacleGrid[0].size(); j++)
        {
            obstacleGrid[i][j] = obstacleGrid[i][j] == 1 ? 0 : obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
    }
    return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp.at(0).size(); j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<vector<int>> nums = {{0, 0, 0}, {0, 5, 0}, {0, 0, 0}};
    // vector<int> nums = {0,0,0,0};

    cout << uniquePathsWithObstacles(nums) << endl;
    return 0;
}