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
求二叉树的最大深度
*/
using namespace std;
int curr(TreeNode *p,int level){
    if (p == nullptr) return level;
    return max(curr(p->left,level+1),curr(p->right,level+1));
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)  return 0;
    return curr(root,0);
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
    cout << maxDepth(&n);
    return 0;
}