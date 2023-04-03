#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
*/
/*
总结：
    1.在循环递增下标并且需要访问数组时，需要提前进行边界判定 （否则Leeetcode报错：AddressSanitizer: heap-buffer-overflow）
    2.跳过下一个相同数字时 使用：while ( j < k && nums[j] == nums[++j]);//j指针向前移动


*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return vector<vector<int>>();
    vector<vector<int>> result_set;
    sort(nums.begin(), nums.end());
    int i = 0, j = 0, k = nums.size() - 1;
    // 从最小的向后遍历
    bool flag = true;
    while (i < nums.size() - 2)
    {
        if (nums[i] > 0)//这种情况说明没有加起来等于0的
            break;
        if(i > 0 && nums[i] == nums[i - 1]) {//相等的最小值遍历情况已经在上一轮跑过了
            i ++;
            continue;}
        //此时的左边界j 初始位置应该在“最小值”下一个
        j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int s = nums[i] + nums[j] + nums[k];
            if (s > 0)
                while ( j < k && nums[k] == nums[--k]);
            else if (s < 0)
                while ( j < k && nums[j] == nums[++j]);
            else if (s == 0){
                vector<int> temp = {nums[i], nums[j], nums[k]};
                result_set.push_back(temp);
                while (j < k && nums[j] == nums[++j]);
                while (j < k && nums[k] == nums[--k]);
            }
        }
        i++;
    }
    return result_set;
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0,0,0,0};
    
    auto a = threeSum(nums);
    cout << a.size() << endl;
    return 0;
}