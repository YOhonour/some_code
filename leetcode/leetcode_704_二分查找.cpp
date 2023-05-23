/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binary_search_curr(nums,0,nums.size()-1,target);
    }

    int binary_search_curr(vector<int> &nums, int left_index, int right_index, int target)
    {
        int avg = (left_index + right_index) / 2;
        if (nums[avg] == target)
            return avg;
        if (left_index == right_index)
        {
            return -1;
        }
        if (target > nums[avg])
        {
            return binary_search_curr(nums, avg+1, right_index, target);
        }
        else
        {
            return binary_search_curr(nums, left_index, avg, target);
        }
    }
};
int main(){
    Solution solu;
    vector<int> nums = {-1,0,3,5,9,12};
    cout << solu.search(nums,2);
    return 0;
}
// @lc code=end
