/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == i + 1)
                continue;
            while (i != nums[i] - 1)
            {
                if (nums[i] < 0 || nums[i] >= nums.size() || nums[i] == nums[nums[i] - 1])
                {
                    break;
                }
                temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[temp - 1] = temp;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != (i + 1)) {
                return (i + 1);
            }
        }
        return (nums.size() + 1);
    }
};
int main(){
    Solution s;
    vector<int> && nums = {1,2,0};
    s.firstMissingPositive(nums);
}
// @lc code=end
