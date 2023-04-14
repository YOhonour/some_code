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

using namespace std;
vector<TreeNode *> tree;
vector<int> nums;
void minser(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
        minser(root->left);
    tree.push_back(root);
    nums.push_back(root->val);
    if (root->right != NULL)
        minser(root->right);
}
void recoverTree(TreeNode *root)
{
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL) return ;
    minser(root);
    sort(nums.begin(),nums.end());
    for (size_t i = 0; i < tree.size(); i++)
    {
        tree[i]->val = nums[i];
    }
}
int main()
{
    TreeNode n(-1);
    TreeNode n1(0);
    n1.left = &n;
    recoverTree(&n1);
    return 0;
}