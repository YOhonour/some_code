#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/
bool canJump(vector<int> &nums)
{
    vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;
    int tar = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        for (int j = nums[i]; j >= 0; j--)
        {
            if (i + j < nums.size() && dp[i + j] == true)//从后往前 依次查看
            {
                dp[i] = dp[i + j];
                break;
            }
        }
    }
    return dp[0];
}

/*
依次遍历数组中的每一个位置，并实时维护 最远可以到达的位置。
对于当前遍历到的位置 x，如果它在 最远可以到达的位置 的范围内，
那么我们就可以从起点通过若干次跳跃到达该位置，因此我们可以用 far+nums[x] 更新 最远可以到达的位置。

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
bool canJump2(vector<int> &nums)
{
    int far = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i <= far)
        {
            if (far < i+nums[i])
            {
                far = i+nums[i];
            }
        }
        
    }
    return nums.size()-1 <= far;
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {1,0,1,0};
    // vector<int> nums = {0,0,0,0};

    cout << canJump2(nums) << endl;
    return 0;
}