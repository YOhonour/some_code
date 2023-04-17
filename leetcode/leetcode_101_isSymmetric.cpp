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
对称二叉树
*/
using namespace std;
bool cur(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p != nullptr && q == nullptr) return false;
    if (p == nullptr && q != nullptr) return false;
    if (p->val == q->val) return cur(p->left,q->right) && cur(p->right,q->left);
    return false;
}

bool isSymmetric(TreeNode *root)
{
    return cur(root->left,root->right);
}
int main()
{
    TreeNode n(2);
    TreeNode n1(3);
    TreeNode n2(3);
    TreeNode n3(4);
    TreeNode n4(5);
    TreeNode n5(4);
    n.left = &n1;n.right = &n2;
    n1.left = &n3;n1.right = &n4;
    n2.right = &n5;
    cout << isSymmetric(&n);
    return 0;
}