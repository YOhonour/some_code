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
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        dfs(candidates, target,0);
        return res;
    }
    vector<int> temp;
    vector<int> temp_;
    // void curr(vector<int> &candidates, int target)
    // {

    //     if (target < 0)
    //     {
    //         return;
    //     }
    //     if (target == 0)
    //     {
    //         sort(temp.begin(), temp.end());
    //         for (size_t i = 0; i < res.size(); i++)
    //         {
    //             if (res[i] == temp)
    //             {
    //                 return;
    //             }
    //         }
    //         res.push_back(vector<int>(temp));
    //         return;
    //     }
    //     for (int i = 0; i < candidates.size(); i++)
    //     {
    //         flag ++;
    //         int cur_tar = target;
    //         int cur_cand = candidates[i];
    //         temp.push_back(cur_cand);
    //         cur_cand = candidates[i];
    //         curr(candidates, target - candidates[i]);
    //         auto back =  temp.back();
    //         temp.resize(temp.size() - 1);
    //     }
    //     return;
    // }
    unordered_map<int, vector<int>> res_map;
    bool curr(vector<int> &candidates, int target)
    {
        auto it = res_map.find(target);
        if (it != res_map.end())
        {
            temp.insert(temp.end(), (*it).second.begin(), (*it).second.end());
            target = 0;
        }
        if (target < 0)
        {
            return false;
        }
        if (target == 0)
        {
            temp_ = temp;
            sort(temp_.begin(), temp_.end());
            for (size_t i = 0; i < res.size(); i++)
            {
                if (res[i] == temp_)
                {
                    return true;
                }
            }
            res.push_back(vector<int>(temp_));
            return true;
        }
        for (int i = 0; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            bool flag = curr(candidates, target - candidates[i]);
            if (flag == true)
            {
                res_map.insert({target - candidates[i], vector<int>(temp)});
            }
            temp.pop_back();
        }
        return false;
    }
    void dfs(vector<int> &candidates, int target, int begin)
    {
        if (target == 0)
        {
            res.push_back((temp));
            return;
        }
        for (int i = begin; i < candidates.size(); i++)
        {
            if(target - candidates[i] < 0) break;
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i],i);
            temp.pop_back();
        }
        return;
    }
};
int main()
{
    Solution ss;
    vector<int> candidates = {8,7,4,3};
    int target = 11;
    auto a = ss.combinationSum(candidates, target);
    cout << endl;
}
// @lc code=end
