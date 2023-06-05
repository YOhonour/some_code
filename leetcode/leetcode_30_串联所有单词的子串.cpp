/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start

#include "stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordCount = words.size();
        int wordLen = wordCount > 0 ? words[0].size() : 0;
        int subStrLen = wordCount * wordLen;
        vector<int> res;
        if (subStrLen == 0 || subStrLen > s.size())
        {
            return res;
        }
        for (int start = 0; start < wordLen; start++)
        {
            unordered_map<string, int> diff;
            int left = start;
            int right = left + subStrLen - 1;
            for (int j = 0; j < wordCount; j++) {
                string&& temp = s.substr(left + j * wordLen, wordLen);
                if (++diff[temp] == 0) {
                    diff.erase(temp);
                }
            }

            for (int j = 0; j < wordCount; j++)
            {
                string& temp = words[j];
                if (--diff[temp] == 0) {
                    diff.erase(temp);
                }
            }
            for (int i = start; i + subStrLen - 1 < s.size(); i += wordLen) {
                if (i != start) {
                    
                    string&& temp = s.substr(i - wordLen, wordLen);
                    if (--diff[temp] == 0) {
                        diff.erase(temp);
                    }
                    string&& temp2 = s.substr(i+ subStrLen - wordLen, wordLen);
                    if (++diff[temp2] == 0) {
                        diff.erase(temp2);
                    }
                }
                if (diff.empty()) {
                    res.push_back(i);
                }
            }
            
        }
        return res;
    }
};
// int main(){
//     Solution s;
//     string str = "barfoothefoobarman";
//     vector<string> words = {"foo","bar"};
//     cout << s.findSubstring(str,words).size();
//     return 0;
// }
// @lc code=end
