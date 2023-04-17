#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
*/
using namespace std;
//开辟临时队列遍历
vector<vector<int>> levelOrder2(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<vector<int>> res;
    if (root == nullptr) return res;
    que.push(root);
    TreeNode *temp;
    while (!que.empty())
    {
        vector<int> curL;
        queue<TreeNode *> temp_que;
        while (!que.empty())
        {
            temp = que.front();
            que.pop();
            curL.push_back(temp->val);
            if (temp->left != nullptr) temp_que.push(temp->left);
            if (temp->right != nullptr) temp_que.push(temp->right);
        }
        res.push_back(curL);
        que = temp_que;
    }
    return res;
}
//深度优先遍历
vector<vector<int>> res_arr;
void curr(TreeNode *p,int level){
    if (p == nullptr) return;
    if (level == res_arr.size())
    {
        res_arr.push_back(vector<int>());
    }
    res_arr[level].push_back(p->val);
    curr(p->left,level+1);
    curr(p->right,level+1);
}
vector<vector<int>> levelOrder(TreeNode *root)
{
    curr(root,0);
    return res_arr;
}
int main()
{
    TreeNode n(-1);
    TreeNode n1(0);
    n1.left = &n;
    return 0;
}