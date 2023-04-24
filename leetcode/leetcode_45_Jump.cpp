#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/
int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), INT_MAX);
    dp[nums.size() - 1] = 0;
    int tar = nums.size() - 1;
    int res = 0;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        for (int j = nums[i]; j >= 0; j--)
        {
            if (i + j < nums.size() && dp[i + j] < INT_MAX && dp[i] < 1 + dp[i + j] ) // 从后往前 依次查看
            {
                dp[i] = 1 + dp[i + j] ;
                break;
            }
        }
    }
    return dp[0];
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {2,3,0,1,4};
    // vector<int> nums = {0,0,0,0};

    cout << jump(nums) << endl;
    return 0;
}