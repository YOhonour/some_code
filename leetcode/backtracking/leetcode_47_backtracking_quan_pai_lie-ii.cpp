/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &&nums)
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
        set<int> st;
        for (int i = begin; i < nums.size(); i++)
        {
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[begin]);
            dfs(nums, begin + 1, vis);
            swap(nums[i], nums[begin]);
        }
    }
};
int main()
{
    Solution s;
    s.permuteUnique({1, 1, 3});
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end

