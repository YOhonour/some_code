/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap2(vector<int> &height)
    {
        int res = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            int left = 0;
            int right = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                left = height[j] > height[left] ? height[j] : height[left];
            }
            for (int j = i + 1; j < height.size(); j++)
            {
                right = height[j] > height[right] ? height[j] : height[right];
            }
            int min = left > right ? right : left;
            if (min > height[i])
            {
                res += (min - height[i]);
            }
        }
        return res;
    }
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
        {
            return 0;
        }

        vector<int> max_left(height.size(), 0);
        vector<int> max_right(height.size(), 0);
        max_left[1] = height[0];
        max_right[height.size() - 2] = height[height.size() - 1];
        for (int i = 2; i < height.size(); i++)
        {
            max_left[i] = max_left[i - 1] > height[i - 1] ? max_left[i - 1] : height[i - 1];
        }
        for (int i = height.size() - 3; i > 0; i--)
        {
            max_right[i] = max_right[i + 1] > height[i + 1] ? max_right[i + 1] : height[i + 1];
        }
        int res = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {

            int min = max_left[i] > max_right[i] ? max_right[i] : max_left[i];
            if (min > height[i])
            {
                res += (min - height[i]);
            }
        }
        return res;
    }
    //维护一个左右最高高度的矩阵 
    int trap3(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i = 1;i < n; i++){
            lmax[i] = height[i-1] > lmax[i-1] ? height[i-1] : lmax[i-1];
        }
        for(int i = n-2;i >= 0; i--){
            rmax[i] = height[i+1] > rmax[i+1] ? height[i+1] : rmax[i+1];
        }
        int res = 0;
        
        for(int i = 1;i < n; i++){
            int max = min(lmax[i] , rmax[i]);
            int temp = max - height[i];
            if(temp > 0){
                res += (temp);
            }
        }
        return res;
    }
};

int main()
{
    // vector<int> nums = {4, 2, 0, 3, 2, 5};
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap3(nums);
}
// @lc code=end
