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
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。


说明：叶子节点是指没有子节点的节点。



小红定义一个数组为“好数组”，当且仅当该数组满足以下条件:
1.数组仅由0 1 2三种元素组成
2.数组相邻的元素不相等例如:[2.1,2.0.1]是好数组.
小红定义一个数组的“陡峭值”为该数组相邻元素的差的绝对值之和。例如，[2,1.2.0.1]的陡峭值为]5。小红想知道，长度为n的所有好数组的陡峭值之和是多少?由于答案过大，请对109+ 7取模。数据范围:2n<109

*/
using namespace std;
bool flag = true;
int curr(TreeNode *p)
{
    if (p->left == nullptr && p->right == nullptr)
        return 1;

    if (p->left != nullptr && p->right == nullptr)
    {
        return curr(p->left) + 1;
    }
    if (p->left == nullptr && p->right != nullptr)
    {
        return curr(p->right) + 1;
    }
    return min(curr(p->left), curr(p->right)) + 1;
}

int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return curr(root);
}
int minD(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    int minDepth = INT_MAX;
    if (root->left != nullptr)
        minDepth = min(minDepth, minD(root->left));
    if (root->right != nullptr)
        minDepth = min(minDepth, minD(root->right));
    
    return minDepth + 1;
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