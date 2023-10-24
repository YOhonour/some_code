/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        int start = 0,end = 0;
        for(int i = 0;i < n; i ++ ){
            auto [L1,R1] = expandCenter(s,i,i);
            auto [L2,R2] = expandCenter(s,i,i+1);
            if(R1 -L1 > end -start){
                start = L1;
                end = R1;
            }
            if(R2 -L2 > end -start){
                start = L2;
                end = R2;
            }
        }
        return s.substr(start,end - start + 1);
    }
    pair<int,int> expandCenter(string &s,int L,int R){
        int n = s.size();
        while(L >= 0 && R < n && s[L] == s[R]){
            L--;
            R++;
        }
        return {L+1,R-1};
    }
};
int main()
{
    string str = "babad";
    Solution s;
    s.longestPalindrome(str);
}
// @lc code=end

