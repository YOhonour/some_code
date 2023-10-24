/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int flag = 1;
    string ans;
    string getPermutation(int n, int k)
    {
        vector<bool> used(n + 1, false);
        K = k;
        dfs(ans, n, 0, used);
        return ans;
    }

    int K;
    int dfs(string &path, int n, int cur_N, vector<bool> &used)
    {
        if (cur_N == n)
        {
            ans = path;
            return -1;
        }
        int cnt = factorial[n - cur_N - 1];

        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                continue;
            if (cnt < K)
            {
                K -= cnt;
                continue;
            }
            path.push_back('0' + i);
            used[i] = true;
            dfs(path, n, cur_N + 1, used);
            return 1;
        }
        return 1;
    }
};
int main()
{
    Solution s;
    s.getPermutation(3, 5);
    return 0;
}
// @lc code=end
