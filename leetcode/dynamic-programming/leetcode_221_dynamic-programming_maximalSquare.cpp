/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int m = 0,n = 0;
    bool test(vector<vector<char>>& matrix,int x,int y,int e){
        if(matrix[x][y] != '1') return false;
        for(int i = 1; i < e; i++) {
            if(x+i >= m || matrix[x+i][y] != '1') return false;
        }
        for(int j = 1; j < e; j++){
            if(y+j >= n || matrix[x][y+j] != '1') return false;
        }
        for(int i = 1; i < e; i++) {
            for(int j = 1; j < e; j++) {
                if(matrix[x+i][y+j] != '1') return false;
            }
        }
        return true;
    }
    int maximalSquare1(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int temp = 1;
                    while (test(matrix,i,j,temp+1))
                    {
                        temp++;
                    }
                    res = max(res,temp);
                }
            }
        }
        return res * res;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = 1;
            }
        }
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == '1') {
                dp[0][j] = 1;
                res = 1;
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res * res;
    }
};
int main()
{
    vector<vector<char>> nums = {
   {'0','1'}};
    Solution s;
    s.maximalSquare(nums);
}
// @lc code=end

