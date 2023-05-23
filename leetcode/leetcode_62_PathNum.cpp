#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m,vector<int>(n,1));
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp.at(0).size(); j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // vector<int> nums = {0,0,0,0};

    cout << uniquePaths(3,7) << endl;
    return 0;
}