/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        auto head = dfs(inorder, 0, n - 1, postorder, 0, n - 1);
        return head;
    }
    TreeNode *dfs(vector<int> &inorder, int i_x, int i_y, vector<int> &postorder, int p_x, int p_y)
    {
        if (i_x >= i_y)
        {
            return new TreeNode(inorder[i_y]);
        }
        int headVal = postorder[p_y];
        int i;
        for (i = i_x; i <= i_y; i++)
        {
            if (inorder[i] == headVal)
                break;
        }
        int leftLen = i - i_x;
        int rightLen = i_y - i;
        TreeNode *curHead = new TreeNode(headVal);
        curHead->left = leftLen == 0 ? nullptr : dfs(inorder, i_x, i - 1, postorder, p_x, p_x + leftLen - 1);
        curHead->right = rightLen == 0 ? nullptr : dfs(inorder, i + 1, i_y, postorder, p_x + leftLen, p_y - 1);
        return curHead;
    }
};
template <int64_t T, int64_t U>
struct Pow
{
    static const int64_t value = T * Pow<T, U - 1>::value;
};
template <int64_t T>
struct Pow<T, 0>
{
    static const int value = 1;
};
class C1
{
};
class C2
{
public:
    C2(){};
    virtual ~C2(){};
};
class C3 : public C2
{
public:
    virtual ~C3(){};

private:
    char *m_pData;
};
int _tmain()
{

    char *pS4 = " 123456 ";
    char ayS5[] = {" 123456 "};
    printf("%d,%d,%d,%d,%d,\r\n", sizeof(C1), sizeof(C2), sizeof(C3), sizeof(pS4), sizeof(ayS5));
    return 0;
}

class Base
{
public:
    virtual ~Base()
    {
        cout << "DestructorBase" << endl;
    }
};
class Derived : public Base
{
public:
    ~Derived()
    {
        cout << "Destructor Derived" << endl;
    }
};
int main()
{
    Base *pBase = new Derived();
    delete pBase;
}

// @lc code=end
