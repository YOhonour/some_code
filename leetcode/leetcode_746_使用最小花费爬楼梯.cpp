/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 2; i < cost.size(); i++) {
            cost[i] = (cost[i-1] < cost[i-2] ? cost[i-1]:cost[i-2] ) + cost[i];
        }
        return cost[cost.size()-1]<cost[cost.size()-2]? cost[cost.size()-1]: cost[cost.size()-2];
    }
};
// @lc code=end

