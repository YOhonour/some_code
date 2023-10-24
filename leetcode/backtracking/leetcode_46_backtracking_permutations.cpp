/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &&nums)
    {
        vector<bool> vis(nums.size(), false);
        dfs(nums, 0, vis);
        return res;
    }
    void dfs(vector<int> &nums, int begin, vector<bool> vis)
    {
        if (begin == nums.size() - 1 )
        {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++)
        {

            swap(nums[i], nums[begin]);
            dfs(nums, begin + 1, vis);
            swap(nums[i], nums[begin]);
        }
    }
};
int main()
{
    Solution s;
    s.permute({1, 2, 3});
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end
