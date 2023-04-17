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

*/
using namespace std;
#define MYNULL -((int)10e9 + 9)
//根据层序遍历生成二叉树不能处理NULL值，除非使用string类型
TreeNode * generateTree(vector<int> &nums)
{
    TreeNode *root = new TreeNode();
    if (nums.empty()) return root;
    vector<TreeNode *> treeList(nums.size());//新建的树节点数组
    for (int i = 0; i < nums.size(); i++) {//依次赋值
        if (nums[i] == MYNULL)//null无法表示，只能抽一个出来
        {
            continue;
        }
        treeList[i] = new TreeNode(nums[i]);
    }
    
    for(int i = 0;i < nums.size();i++){
        if (treeList[i] == nullptr) continue;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l < nums.size()){
            treeList[i]->left = treeList[l];
        }
        if(r < nums.size()){
            treeList[i]->right = treeList[r];
        }
    }
    return treeList.front();
}
TreeNode* buildTree(vector<int>& nums) {
    if (nums.empty()) return NULL;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q{{root}};
    int i = 1;
    while (i < nums.size() && !q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        if (nums[i] != -1) {
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }
        ++i;
        if (i < nums.size() && nums[i] != -1) {
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        ++i;
    }
    return root;
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
    vector<int> nums = {5,4,8,11,MYNULL,13,4,7,2,MYNULL,MYNULL,MYNULL,1};
    auto a = buildTree(nums);
    return 0;
}