/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    bool cmp(vector<int> &p1,vector<int> &p2)
    {
        return p1[0] < p2[0];
    };
    
    bool isValid(vector<int> &p1,vector<int> &p2){
        if(p1[0] >= p1[1] || p2[0] >= p2[1]) return false;
        return p1[1] < p2[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n == 1) return 1;
        int res = 0;
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(n,1);
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(isValid(pairs[j],pairs[i])){
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
int main(){
    vector<vector<int>> nums = {{1,2},
{7,8},
{4,5}};
    Solution s;
    s.findLongestChain(nums);
}
// @lc code=end

