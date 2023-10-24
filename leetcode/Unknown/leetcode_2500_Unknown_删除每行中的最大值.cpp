/*
 * @lc app=leetcode.cn id=2500 lang=cpp
 *
 * [2500] 删除每行中的最大值
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            sort(grid[i].begin(),grid[i].end());
        }
        int ans = 0;
        for(int j = 0; j < grid[0].size(); j++) {
            ans += getMax(grid,j);
        }
        return ans;
    }
    int inline getMax(vector<vector<int>>& grid,int y){
        int m = 0;
        for(int i = 0; i < grid.size(); i++) {
            if(grid[i][y] > m) m = grid[i][y];
        }
        return m;
    }
};
// @lc code=end

