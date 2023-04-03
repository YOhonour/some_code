#include <iostream>
#include <vector>
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *rcur(vector<int> &preorder, int l, int r, vector<int> &inorder, int a, int b);




int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode * a = buildTree(preorder,inorder);
    return 0;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() != inorder.size() || preorder.size() == 0)
        return NULL;
    return rcur(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
TreeNode *rcur(vector<int> &preorder, int l, int r, vector<int> &inorder, int a, int b)
{
    if (l > r || a > b || a < 0)
        return NULL;
    if (l == r) {
        return new TreeNode(preorder[l]);
    }
    int curHead = l;
    // 在中序中搜索头节点
    int head_in = a;
    while (head_in < inorder.size() && head_in <= b && inorder[head_in] != preorder[curHead])
        head_in++;
    int left_tree_len = head_in - a;
    int right_tree_len = b - head_in;
    TreeNode *curNode = new TreeNode(inorder[head_in]);
    curNode->left = rcur(preorder, l + 1, l + left_tree_len, inorder, a, head_in - 1);
    curNode->right = rcur(preorder, l + left_tree_len+1, r, inorder, head_in + 1, b);
    return curNode;
}