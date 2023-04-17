#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct NUM
{
    int c2;
    int c5;
};//pair
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> levelOrder2(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<vector<int>> res;
    if (root == nullptr) return res;
    que.push(root);
    TreeNode *temp;
    while (!que.empty())
    {
        vector<int> curL;
        queue<TreeNode *> temp_que;
        while (!que.empty())
        {
            temp = que.front();
            que.pop();
            curL.push_back(temp->val);
            if (temp->left != nullptr) temp_que.push(temp->left);
            if (temp->right != nullptr) temp_que.push(temp->right);
        }
        res.push_back(curL);
        que = temp_que;
    }
    return res;
}
//将n拆为 2 和 5的因子
pair<int,int> getNUMs(int n){
    int c2 = 0, c5 = 0;
    while (n % 2 == 0 && n > 0) {
        c2 += 1;
        n /= 2;
    }
    while (n % 5 == 0 && n > 0) {
        c5 += 1;
        n /= 5;
    }
    return {c2,c5};
}
// 计算价值
//向上返回2和5的因子数
pair<int,int> dfs(TreeNode *root){
    if (root == nullptr)
    {
        return {0,0};
    }
    auto L = dfs(root->left);//左子树
    auto R = dfs(root->right);//右子树
    auto cur = getNUMs(root->val);//拆分本节点权值
    cur.first = cur.first + L.first + R.first;//c2 相加
    cur.second = cur.second + L.second + R.second;//c5 相加
    root->val = min(cur.first,cur.second);//计算价值
    return cur;//向上层返回
}

//小红定义一个数组为“好数组”，当且仅当该数组满足以下条件:
//1.数组仅由01.2三种元素组成2.数组相邻的元素不相等例如:[2.1,2.0.1是好数组小红定义一个数组的“陡峭值”为该数组相邻元素的差的绝对值之和。
int fun(int n){

}

// int main() {
//     TreeNode n(2);
//     TreeNode n1(5);
//     TreeNode n2(10);
//     TreeNode n3(4);
//     TreeNode n4(5);
//     n.left = &n1;
//     n.right = &n2;
//     n2.left = &n3;
//     n2.right = &n4;
//     auto a = levelOrder2(&n);
//     dfs(&n);
//     auto b = levelOrder2(&n);

//     return 0;
// }
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp0(n+1), dp1(n+1), dp2(n+1);
    dp0[1] = 0;dp1[1] = 0;dp2[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp1[i - 1] + 1 + dp2[i - 1] + 2) % MOD;
        dp1[i] = (dp0[i - 1] + 1 + dp2[i - 1] + 1) % MOD;
        dp2[i] = (dp0[i - 1] + 2 + dp1[i - 1] + 1) % MOD;
    }

    long long ans = (dp0[n] + dp1[n] + dp2[n]) % MOD;
    cout << ans << endl;

    return 0;
}
