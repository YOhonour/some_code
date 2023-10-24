/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int largestRectangleArea2(vector<int> &heights)
    {
        int res = heights[0];
        for (int i = 1; i < heights.size(); i++)
        {
            int minHeight = heights[i];
            for (int j = i; j >= 0; j--)
            {
                minHeight = min(heights[j], minHeight);
                int w = i - j + 1;
                res = max(res, w * minHeight);
            }
        }
        return res;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            left[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();
        
        for(int j = n-1; j >= 0; j--) {
            while (!st.empty() && heights[st.top()] >= heights[j])
            {
                st.pop();
            }
            right[j] = (st.empty() ? n : st.top());
            st.push(j);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res,heights[i] * (right[i]-left[i] - 1));
        }
        return res;
    }
};
int main(){
    vector<int> nums = {6,7,5,2,4,5,9,3};
    Solution s;
    s.largestRectangleArea(nums);
}
// @lc code=end
