/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        res.push_back(temp);
        for(int i = 1; i < nums.size(); i++) {
            dfs(n,i,0,i,temp,nums,res);
        }
        res.push_back(nums);
        return res;
    }
    void dfs(int n,int Len,int begin, int cur_K, vector<int> &temp,vector<int> &nums,vector<vector<int>> &res)
    {
        if (cur_K == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = begin; i < n - (Len - temp.size()) + 1; i++) {
            if(i > begin && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            dfs(n,Len,i + 1,cur_K-1,temp,nums,res);
            temp.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto a = s.subsetsWithDup(nums);
    cout << "asdasd" << endl;
    return 0;
}

// @lc code=end
