#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 计算二叉树的高度
int height(TreeNode* root) {
    if (!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int cntOfMethods(vector<TreeNode*> & trees) {
    int n = trees.size();
    vector<int> heights(n);

    // 计算每棵树的高度
    for (int i = 0; i < n; i++) {
        heights[i] = height(trees[i]);
    }

    // 以高度进行排序
    sort(heights.begin(), heights.end());

    // 计算组合方式
    int ans = 1;
    int count = 0;
    for (int h : heights) {
        ans = (long long)ans * (count + 1) % MOD; // 每次至少有一个方法，乘上现有的方法
        count++; // 可用于拼接的树增加
        if (count == 2) count = 0; // 每两棵树拼接后成为一棵新树
    }

    return ans;
}
// 小红拿到了n个二叉树，她准备把这些二叉树拼接起来。两个二叉树a、b拼接的方式是:选择一个二叉树a的一个叶子，将二叉树b的根作为该叶子的左儿子或者右儿子。这样就把a和b拼接起来了。
// 小红希望最终将这所有n个二叉树拼接成一个二叉树，需要满足最终二叉树的高度尽可能大。请计算有多少种不同的拼接方式?
// 由于答案可能过大，请对10e9+7取模。
// 数据范围:
// 所有二叉树的节点数量之和不超过200000。
// 每个二叉树至少有一个节点。
// 每个节点的权值随机。
// 1 < n < 200000

// 二叉树的节点定义如下：
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// 请实现函数cntOfMethods完成上述的功能，函数原型如下：
// int cntOfMethods(vector<TreeNode*> & trees)