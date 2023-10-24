/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<bool> vis(candidates.size(), false);
        sort(candidates.begin(), candidates.end());//先排序 减少搜索 这样只需要前后比较
        dfs(candidates, target, temp, 0);//深度优先遍历
        return res;
    }
    void dfs(vector<int> &candidates, int target, vector<int> &temp, int begin)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = begin; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0)
                break;
            
            if(i > begin && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], temp, i + 1);
            temp.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    s.combinationSum2(nums, 30);
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end
