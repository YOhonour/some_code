#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
有一只跳蚤的家在数轴上的位置 x 处。请你帮助它从位置 0 出发，到达它的家。
跳蚤跳跃的规则如下：
    它可以 往前 跳恰好 a 个位置（即往右跳）。
    它可以 往后 跳恰好 b 个位置（即往左跳）。
    它不能 连续 往后跳 2 次。
    它不能跳到任何 forbidden 数组中的位置。
跳蚤可以往前跳 超过 它的家的位置，但是它 不能跳到负整数 的位置。

给你一个整数数组 forbidden ，其中 forbidden[i] 是跳蚤不能跳到的位置，同时给你整数 a， b 和 x ，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 x 的可行方案，请你返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-jumps-to-reach-home
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*

    dp[i]
*/
int cur = 0;
int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{
    
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0, 0, 0, 0};

    cout << 1 << endl;
    return 0;
}