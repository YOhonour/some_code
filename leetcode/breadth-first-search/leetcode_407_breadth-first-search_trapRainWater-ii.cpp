/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    struct CMP
    {
        bool operator()(vector<int> &a,vector<int>& b){
            return a[2] > b[2];
        }
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>>,CMP> pq;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    pq.push({i,j,heightMap[i][j]});
                    vis[i][j] = true;
                }
            }
        }
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};
        int res = 0;
        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int x = temp[0];
            int y = temp[1];
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                if (temp[2] > heightMap[nx][ny]) {
                    res += temp[2] - heightMap[nx][ny];
                }
                pq.push({nx,ny,max(heightMap[nx][ny],temp[2])});

            }
        }
        return res;
    }
};
int main(){
    vector<vector<int>> he = {{1,4,3,1,3,2},
{3,2,1,3,2,4},
{2,3,3,2,3,1}};
    Solution s;
    s.trapRainWater(he);
}
// @lc code=end

