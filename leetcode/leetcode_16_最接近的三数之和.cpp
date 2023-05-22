#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return vector<vector<int>>();
    vector<vector<int>> result_set;
    sort(nums.begin(), nums.end());
    int i = 0, j = 0, k = nums.size() - 1;
    // 先固定一个 剩下两个从两端向中间遍历
    bool flag = true;
    while (i < nums.size() - 2)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
        {
            i++;
            continue;
        }
        j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int s = nums[i] + nums[j] + nums[k];
            if (s > 0)
            {
                while (j < k && nums[k] == nums[--k])
                    ;
            }
            else if (s < 0)
            {
                while (j < k && nums[j] == nums[++j])
                    ;
            }
            else if (s == 0)
            {
                result_set.push_back({nums[i], nums[j], nums[k]});
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
int threeSumClosest(vector<int> &nums, int target)
{
    int i = 0, j = 0, k = 0;
    int temp = INT32_MAX;
    int s = 0;
    int res = 0;
    sort(nums.begin(), nums.end());
    while (i < nums.size() - 2)
    {
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            s = nums[i] + nums[j] + nums[k];
            int te = abs(s - target);
            if (te < temp)
            {
                temp = te;
                res = s;
            }
            if (s > target)
            {
                while (j < k && nums[k] == nums[--k])
                    ;
            }
            else if (s < target)
            {
                while (j < k && nums[j] == nums[++j])
                    ;
            }
            else if (s == target)
            {
                return s;
            }
        }
        i++;
    }
    return res;
}
int main()
{
    vector<int> nums = {1,1,1,1};
    cout << threeSumClosest(nums, 0);
    return 0;
}