#include <iostream>
#include <vector>

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
vector<int> nums;
void minser(TreeNode *root){
    if(root==NULL) return;
    if(root->left != NULL)  
        minser(root->left);
    nums.push_back(root->val);
    if(root->right != NULL)
        minser(root->right);
}
bool isValidBST(TreeNode *root)
{
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    minser(root);
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i-1] >= nums[i]) return false;
    }
    return true;
}

int main()
{
    TreeNode n(-1);
    TreeNode n1(0);
    n1.left = &n;
    minser(&n1);
    isValidBST(&n1);
    return 0;
}