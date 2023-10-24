/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        for(int i = 1; i < nums.size(); i++) {
            dfs(nums.size(),0,i,temp,res,i,nums);
        }
        res.push_back(nums);
        return res;
    }
    
    void dfs(int n ,int begin, int cur_k, vector<int> &temp,vector<vector<int>> &res , int k,vector<int> &nums)
    {
        if(cur_k == 0){
            res.push_back(temp);
            return;
        }
        for (int i = begin; i < n - (k - temp.size()) + 1; i++)
        {
            temp.push_back(nums[i]);
            dfs(n,i + 1, cur_k - 1,temp,res,k,nums);
            temp.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    s.subsets(nums);
    cout << "asdasd" << endl;
    return 0;
}
// @lc code=end
