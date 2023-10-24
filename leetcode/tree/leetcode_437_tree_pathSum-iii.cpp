/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include "../stdc++.h"
using namespace std; 
class Solution {
public:
    int targetSum_;
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        targetSum_ = targetSum;
        dfs(root,targetSum_);
        return ans;
    }

    void dfs(TreeNode* root, int cur_sum){
        if (root == nullptr) return;
        cur_sum = cur_sum - root->val;
        if (cur_sum == 0){
            ans++;
        }
        
        if (cur_sum > 0){
            dfs(root->left,cur_sum);
            dfs(root->right,cur_sum);
        }
        dfs(root->left,targetSum_);
        dfs(root->right,targetSum_);
        
        return;
    }
};
int main(){
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    a1.right = &a2;
    a2.right = &a3;
    a3.right = &a4;
    a4.right = &a5;
    Solution s;
    s.pathSum(&a1,3);
}
// @lc code=end

