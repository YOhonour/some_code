#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    /*
    给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    */
   //思路是 维护一个最大 最小队列 更新的最大值来源有三个：当前nums[i]值、nums[i]*dp_max[i-1](当前值乘以上一轮的最大值)、nums[i]*dp_min[i-1]（如果当前值是负数，就乘以最小队列的）
   //最小队列的来源也是一样的
    int maxProduct(vector<int>& nums) {
    vector<int> dp_max(nums.size(),0);
    vector<int> dp_min(nums.size(),0);
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {

        dp_max[i] = max(max(dp_max[i-1] * nums[i],nums[i]),nums[i]*dp_min[i-1]);
        dp_min[i] = min(min(dp_min[i-1] * nums[i],nums[i]),nums[i]*dp_max[i-1]);
    }
    return *max_element(dp_max.begin(),dp_max.end());
    }
int main()
{
    vector<int> nums = {2,-5,-2,-4,3};
    maxProduct(nums);
}