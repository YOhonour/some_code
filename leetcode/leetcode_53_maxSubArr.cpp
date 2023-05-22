#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。


*/
int maxSubArray(vector<int> &nums)
{
    int temp = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (temp + nums[i] <= 0 || temp <= 0)
        {
            temp = nums[i];
        }
        else
        {
            temp += nums[i];
        }
        ans = ans > temp ? ans : temp;
    }
    return ans;
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {0,0,0,0};

    cout << maxSubArray(nums) << endl;
    return 0;
}