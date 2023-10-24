/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, temp, 0, res);
        return res;
    }
    void dfs(vector<int> &candidates, int target, vector<int> &temp, int begin, vector<vector<int>> &res)
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
            temp.push_back(candidates[i]);
            //下一轮搜索的起点为i，而不是每轮都从头搜索，如果是轮从头搜索 得到的是满足和为target的全排
            //从i开始，能避免下层搜索选择上层已经选过的值
            dfs(candidates, target - candidates[i], temp, i, res);
            temp.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 6, 7};
    s.combinationSum(nums, 7);
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end
