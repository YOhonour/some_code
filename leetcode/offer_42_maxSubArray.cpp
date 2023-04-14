#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值

*/
int maxSubArray(vector<int> &nums)
{
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    int temp_sum = nums[0];
    int ans = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        ans = max(ans,dp[i]);
    }
    return ans;
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    return 0;
}