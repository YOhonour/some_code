/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end(),[](const string &a,const string &b){return a.size() < b.size();});
        int n = s.size();
        auto wordSet = unordered_set<string>();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(auto &str : wordDict) {
            wordSet.insert(wordDict[i]);
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] && wordSet.find(s.substr(j,i-j)) != wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
int main()
{   
    vector<string> wordDict = {"apple", "pen"};
    string str = "applepenapple";
    Solution s;
    s.wordBreak(str,wordDict);
}
// @lc code=end

