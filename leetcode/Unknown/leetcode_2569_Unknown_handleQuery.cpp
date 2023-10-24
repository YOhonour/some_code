/*
 * @lc app=leetcode.cn id=2569 lang=cpp
 *
 * [2569] 更新数组后处理求和查询
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        long long res = 0;
        vector<long long> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            switch (queries[i][0])
            {
            case 1:
                handle_1(nums1, nums2, queries[i]);
                break;
            case 2:
                handle_2(nums1, nums2, queries[i]);
                break;
            case 3:
                ans.push_back(handle_3(nums1, nums2, queries[i]));
                break;
            default:;
            }
        }
        return ans;
    }
    void handle_1(vector<int> &nums1, vector<int> &nums2, vector<int> &query)
    {
        for (int i = query[1]; i <= query[2]; i++)
        {
            nums1[i] ^= 1;
        }
    }
    void handle_2(vector<int> &nums1, vector<int> &nums2, vector<int> &query)
    {
        for (int i = query[2]; i < nums2.size(); i++)
        {
            nums2[i] = nums2[i] + nums1[i] * query[1];
        }
    }
    long long handle_3(vector<int> &nums1, vector<int> &nums2, vector<int> &query)
    {
        long long ans = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            ans += nums2[i];
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1 = {1, 0, 1};
    vector<int> nums2 =
        {0, 0, 0};
    vector<vector<int>> queries =
    {
        {1, 1, 1},
        {2, 1, 0},
        {3, 0, 0}
    };
    Solution s;
    s.handleQuery(nums1,nums2,queries);
}
// @lc code=end
