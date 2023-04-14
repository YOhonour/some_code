#include <iostream>
#include <vector>
#include <algorithm>

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
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
*/
using namespace std;
bool cur(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p != nullptr && q == nullptr) return false;
    if (p == nullptr && q != nullptr) return false;
    if (p->val == q->val) return cur(p->left,q->left) && cur(p->right,q->right);
    return false;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    return cur(p,q);
}
int main()
{
    TreeNode n(-1);
    TreeNode n1(0);
    n1.left = &n;
    return 0;
}