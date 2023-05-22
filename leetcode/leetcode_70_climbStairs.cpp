#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。


*/
int climbStairs(int n)
{
    
    if (n < 3)
    {
        return n;
    }
    int *dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> nums = {0,0,0,0};

    cout << climbStairs(10) << endl;
    return 0;
}