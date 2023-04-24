#include <iostream>
#include <vector>
#include <unordered_map>

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


unordered_map<int ,int> map;

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
    for (size_t i = 0; i < inorder.size(); i++)
    {
        map.insert({inorder[i],i});
    }
    
    return rcur(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
TreeNode *rcur(vector<int> &preorder, int l, int r, vector<int> &inorder, int a, int b)
{
    if (l > r || a > b || a < 0)
        return NULL;
    if (l == r) {
        return new TreeNode(preorder[l]);
    }
    // 在中序中搜索头节点
    int head_in = map.at(preorder[l]);
    int left_tree_len = head_in - a;
    TreeNode *curNode = new TreeNode(inorder[head_in]);
    curNode->left = rcur(preorder, l + 1, l + left_tree_len, inorder, a, head_in - 1);
    curNode->right = rcur(preorder, l + left_tree_len+1, r, inorder, head_in + 1, b);
    return curNode;
}
int getIndex(vector<int> &inorder,int val){

}