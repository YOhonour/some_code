/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> nums_;
    int res = -1;
    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left < 0 || left > nums.size() - 1 || right < 0 || right > nums.size() - 1 || left > right)
        {
            return -1;
        }
        if ((target > nums[right] && target < nums[left]))
        {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            res = mid;
            return mid;
        }
        if (left == right)
        {
            return -1;
        }
        if (nums[left] < nums[right])
        // 如果当前范围内数组是有序的，正常二分
        {
            if (target < nums[mid])
            {
                return binarySearch(nums, target, left, mid - 1);
            }
            else
            {
                return binarySearch(nums, target, mid + 1, right);
            }
        }
        else
        {
            // 此时数组内包含的旋转数组部分
            if (nums[mid] >= nums[left])
            {
                /* 左边有序 */
                if (target <= nums[mid] && target > nums[right])
                {
                    return binarySearch(nums, target, left, mid - 1);
                }
                else
                {
                    return binarySearch(nums, target, mid + 1, right);
                }
            }
            else
            {
                // 右边有序
                if (target >= nums[mid] && target < nums[left])
                {
                    return binarySearch(nums, target, mid + 1, right);
                }
                else
                {
                    return binarySearch(nums, target, left, mid - 1);
                }
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }
        binarySearch(nums, target, 0, nums.size() - 1);
        return res;
    }
};
int main()
{
    vector<int> nums = {3,7,9,1,2};
    Solution solu;
    cout << solu.search(nums, 0);
}
// @lc code=end
