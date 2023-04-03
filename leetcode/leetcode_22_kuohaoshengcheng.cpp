#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

解题关键是：
"(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】

其中 p + q = n-1，且 p q 均为非负整数
*/
vector<vector<string>> dp;
vector<string> generate(int n){
    if (n == 0) return vector<string>({""});
    if (n == 1) return vector<string>({"()"});
    if (n == 2) return vector<string>({"()()","(())"});
    vector<string> last = dp[n-1];
    vector<string> cur;
    for(int i = 0 ;i <= n-1; i++){
        int p = i,q = n-1-i;
        for (size_t j = 0; j < dp[i].size(); j++)
        {
            for (size_t k = 0; k < dp[n-1-i].size(); k++)
            {
                cur.push_back("("+dp[i][j]+")"+dp[n-1-i][k]);
            }
        }
    }
    return cur;
}
vector<string> generateParenthesis(int n)
{
    if (n == 0) return vector<string>();
    for (size_t i = 0; i <= n; i++)
    {
        dp.push_back(generate(i));
    }
    return dp[n];
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0,0,0,0};
    auto a = generateParenthesis(3);
    return 0;
}