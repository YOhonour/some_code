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
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
*/
using namespace std;
bool flag = true;
int curr(TreeNode *p)
{
    if(p == nullptr) return 0;
    int l = curr(p->left) + 1;
    int r = curr(p->right) + 1;
    if (!(l-r == 0 || l-r == 1 || l-r == -1)) {
        flag = false;
    }

    return max(l,r);
    //return l > r ? l : r;
}

bool isBalanced(TreeNode *root)
{
    curr(root);
    return flag;
}
int main()
{
    TreeNode n(2);
    TreeNode n1(3);
    TreeNode n2(3);
    TreeNode n3(4);
    TreeNode n4(5);
    TreeNode n5(4);
    n.left = &n1;
    n.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n2.right = &n5;
    return 0;
}