#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/
int minPathSum(vector<vector<int>> &grid)
{
    int a,b;
    auto& dp = grid;
    for (size_t i = 1; i < grid.at(0).size(); i++)
    {
        dp[0][i] = dp[0][i] + dp[0][i-1];
    }
    for (size_t i = 1; i < grid.size(); i++)
    {
        dp[i][0] = dp[i][0] + dp[i-1][0];
    }
    
    for (int i = 1; i < grid.size(); i++)
    {
        for (int j = 1; j < grid.at(0).size(); j++)
        {
            a = dp[i][j] + dp[i-1][j];
            b = dp[i][j] + dp[i][j-1];
            dp[i][j] = a < b ? a : b;
        }
    }
    return dp[grid.size()-1][grid.at(0).size() - 1];
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // vector<int> nums = {0,0,0,0};

    cout << minPathSum(nums) << endl;
    return 0;
}