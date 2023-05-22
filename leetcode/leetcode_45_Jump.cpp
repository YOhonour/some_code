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
    int res = 0;
    int targetLocation = nums.size() - 1;
    while (targetLocation != 0)
    {
        for (int i = 0; i < targetLocation; i++)
        {
            if (i + nums[i] >= targetLocation)
            {
                targetLocation = i;
                res ++;
                break;
            }
        }
    }
    return res;
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {2,3,0,1,4};
    // vector<int> nums = {0,0,0,0};

    cout << jump(nums) << endl;
    return 0;
}