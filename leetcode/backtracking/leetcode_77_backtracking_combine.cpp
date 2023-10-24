/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        vector<bool> vis(n+1,false);
        dfs(n,1,k,temp,vis,k);
        return res;
    }
    void dfs(int n ,int begin, int cur_k, vector<int> &temp,vector<bool> &vis , int k)
    {
        if(cur_k == 0){
            res.push_back(temp);
            return;
        }
        // for (int i = begin; i <= n; i++)
        // 更新搜索的上界  假如已经找到了 a 个，那么剩余的数字个数应该为 k - a -> b 个，
        // 所以搜索的上界相对于n来说，最后的b-1个数字是没有意义的，因为不够凑足k个值
        for (int i = begin; i <= n - (k - temp.size()) + 1; i++)
        {
            //if(vis[i]) continue;
            temp.push_back(i);
            //vis[i] = true;
            dfs(n,i + 1, cur_k - 1,temp,vis,k);
            temp.pop_back();
            //vis[i] = false;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    auto a = s.combine(4, 2);
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end
