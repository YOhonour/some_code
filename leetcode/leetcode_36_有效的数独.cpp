/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                char cur = board[i][j];
                for (int i_ = 0; i_ < board.size(); i_++)
                {
                    if(i == i_) continue;
                    if(cur == board[i_][j]){
                        return false;
                    }
                }
                for (int j_ = 0; j_ < board.size(); j_++)
                {
                    if(j == j_) continue;
                    if(cur == board[i][j_]){
                        return false;
                    }
                }
                int bi = i / 3;
                int bj = j / 3;
                
            }
        }
    }
};
// @lc code=end

