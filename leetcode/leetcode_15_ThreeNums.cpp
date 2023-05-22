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
        if (nums[i] > 0) // 这种情况说明没有加起来等于0的
            break;
        if (i > 0 && nums[i] == nums[i - 1])
        { // 相等的最小值遍历情况已经在上一轮跑过了
            i++;
            continue;
        }
        // 此时的左边界j 初始位置应该在“最小值”下一个
        j = i + 1, k = nums.size() - 1;
        while (j < k) // 将双指针逐渐逼近
        {
            int s = nums[i] + nums[j] + nums[k];
            if (s > 0)
                while (j < k && nums[k] == nums[--k])
                    ;
            else if (s < 0)
                while (j < k && nums[j] == nums[++j])
                    ;
            else if (s == 0)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                result_set.push_back(temp);
                while (j < k && nums[j] == nums[++j])
                    ;
                while (j < k && nums[k] == nums[--k])
                    ;
            }
        }
        i++;
    }
    return result_set;
}
bool isValid(vector<vector<int>> &result_set, vector<int> &temp)
{
    bool flag = false;
    for (auto itList : result_set)
    {
        flag = false;
        for (size_t i = 0; i < temp.size(); i++)
        {
            if (itList[i] != temp[i])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            return false;
        }
    }
    return true;
}
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result_set;
    if (nums.size() < 4)
        return result_set;
    sort(nums.begin(), nums.end());
    int l = 0, i = 0, j = 0, k = nums.size() - 1;
    // 从最小的向后遍历

    while (l < nums.size() - 3)
    {

        i = l + 1;
        while (i < nums.size() - 2)
        {
            // 此时的左边界j 初始位置应该在“最小值”下一个
            j = i + 1, k = nums.size() - 1;
            while (j < k) // 将双指针逐渐逼近
            {
                // if (nums[l] == 1000000000 && nums[i] == 1000000000 && nums[j] == 1000000000 && nums[k] == 1000000000)
                // {
                //     return result_set;
                // }
                long long s = (long long)nums[l] + nums[i] + nums[j] + nums[k];
                if (s > target)
                    while (j < k && nums[k] == nums[--k])
                        ;
                else if (s < target)
                    while (j < k && nums[j] == nums[++j])
                        ;
                else if (s == target)
                {
                    vector<int> temp = {nums[l], nums[i], nums[j], nums[k]};
                    if (isValid(result_set, temp))
                    {
                        result_set.push_back(temp);
                    }

                    while (j < k && nums[j] == nums[++j])
                        ;
                    while (j < k && nums[k] == nums[--k])
                        ;
                }
            }
            i++;
        }
        l++;
    }

    return result_set;
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
    // vector<int> nums = {0,0,0,0};

    auto a = fourSum(nums, -11);
    cout << a.size() << endl;
    return 0;
}