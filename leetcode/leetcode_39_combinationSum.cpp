/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int flag = 0;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        curr(candidates, target);
        return res;
    }
    vector<int> temp;
    void curr(vector<int> &candidates, int target)
    {
        
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            sort(temp.begin(), temp.end());
            for (size_t i = 0; i < res.size(); i++)
            {
                if (res[i] == temp)
                {
                    return;
                }
            }
            res.push_back(vector<int>(temp));
            return;
        }
        for (int i = 0; i < candidates.size(); i++)
        {
            flag ++;
            int cur_tar = target;
            int cur_cand = candidates[i];
            temp.push_back(cur_cand);
            cur_cand = candidates[i];
            curr(candidates, target - candidates[i]);
            auto back =  temp.back();
            temp.resize(temp.size() - 1);
        }
        return;
    }
};
int main(){
    Solution ss;
    vector<int> candidates = {2,3,5};
    int target = 8;
    auto a = ss.combinationSum(candidates,target);
    cout << endl;
}
// @lc code=end
