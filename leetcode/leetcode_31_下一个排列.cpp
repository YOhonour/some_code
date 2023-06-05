/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int i, j;
        bool flag = false;
        for (i = nums.size() - 1; i >= 0; i--){
            if(i > 0){
                if(nums[i-1] < nums[i]){
                    flag = true;
                    break;
                }
            }
        }
        i--;
        if(flag){
            flag = false;
            for (j = nums.size() - 1; j > i; j--)
            {
                if(nums[i] < nums[j]){
                    flag = true;
                    break;
                }
            }
            swap(nums[i], nums[j]);
            sort(nums.begin() + i + 1, nums.end());
        }else{
            sort(nums.begin()  , nums.end());
        }
    }
};
int main()
{
    vector<int> nums = {4,2,0,2,3,2,0};
    Solution solu;
    solu.nextPermutation(nums);
    for (auto it : nums)
    {
        cout << it << ' ';
    }
}
// @lc code=end
