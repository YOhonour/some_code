/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    struct CMP
    {
        bool cmp(const vector<int> &A, const vector<int> &B)
        {
            if (A[0] != B[0])
                return A[0] > B[0];
            else
                return A[1] > B[1];
        }
    };
    static bool cmp1(const vector<int> &A, const vector<int> &B)
    {
        if (A[0] != B[0])
            return A[0] < B[0];
        else
            return A[1] < B[1];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp1);
        int res = lengthOfLIS(envelopes);
        return res;
    }
    int lengthOfLIS(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int maxLen = 1;
        vector<int> f = {nums[0][1]};
        for (int i = 1; i < n; i++)
        {
            if (int num = nums[i][1]; num > f.back())
            {
                f.push_back(num);
            }
            else
            {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};
int main()
{
    vector<vector<int>> nums = {{5, 4},
                                {6, 4},
                                {6, 7},
                                {2, 3}};
    Solution s;
    cout << s.maxEnvelopes(nums);
}
// @lc code=end
