/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 1) return 0;
        vector<int> dp(s.size(),0);
        int max = 0;
        for(int i = 1; i < dp.size(); i++) {
            if(s.at(i) == ')'){
                if(s.at(i-1) == '('){
                    dp[i] = i - 2 >= 0 ? dp[i-2] + 2 : 2;
                }else if (i - dp[i-1] - 1 >= 0 && s.at(i - dp[i-1] - 1) == '('){
                    dp[i] = dp[i-1] + 2;
                    if(i - dp[i-1] - 1 - 1 >= 0){
                        dp[i] += dp[i - dp[i-1] - 1 - 1];
                    }
                }
                if(dp[i] > max) max=dp[i];
            }
        }
        return max;
    }
};
int main(){
    Solution sss;
    cout << sss.longestValidParentheses("()(()");
}
// @lc code=end

