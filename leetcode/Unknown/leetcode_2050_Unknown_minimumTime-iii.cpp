/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

// @lc code=start
#include "../stdc++.h"
using namespace std; 
class Solution
{
public:
    int res = 0;
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        unordered_map<int, vector<int>> map;//图 邻接表
        vector<bool> vis(n, false);
        for (int i = 0; i < relations.size(); i++)
        {
            map[relations[i][0]].push_back(relations[i][1]);
        }
        auto aa = TopologicalSorting(map,5);
        return res;
    }
    vector<int> TopologicalSorting(unordered_map<int, vector<int>> &map,int n){
        unordered_map<int, int> degre;
        for(auto &it: map){
            degre[it.first] = it.second.size();//记录每个节点的出度
        }
        vector<bool> vis(n,false);
        vector<int> ans;
        while (ans.size() < n)
        {
            for(auto &it : degre) {
                if(vis[it.first]) continue;
                degre[it.first] -= 1;
                if(degre[it.first] == 0) {
                    vis[it.first] = true;
                    ans.push_back(it.first);
                }
            }
        }
        
        return ans;
    }
};
int main(){
    vector<vector<int>> relations;
    relations.push_back({1,5});
    relations.push_back({2,5});
    relations.push_back({3,5});
    relations.push_back({3,4});
    relations.push_back({4,5});
    vector<int> time;
    Solution s;
    s.minimumTime(5,relations,time);
}
// @lc code=end
