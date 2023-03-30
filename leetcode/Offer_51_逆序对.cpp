#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        //本质是归并排序 只是在交换的时候计数
        if (nums.size() == 0)
            return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int> &nums, int l, int r)
    {
        int len = r - l + 1;       // 数组长度
        int mid = l + (r - l) / 2; // 中点下标
        int *temp = new int[len];
        for (int i = 0; i < len; i++)
        {
            temp[i] = nums[i];
        }

        return mergeRucr(nums, temp, l, r);
    }
    int mergeRucr(vector<int> &nums, int temp[], int l, int r)
    {
        if (l == r)
            return 0;
        int len = r - l + 1;       // 数组长度
        int mid = l + (r - l) / 2; // 中点下标
        int re = mergeRucr(nums, temp, l, mid) + mergeRucr(nums, temp, mid + 1, r);//左右有序
        int pl = l, pr = mid + 1, p = l;
        while (pl <= mid && pr <= r)//合并
        {
            if (temp[pl] <= temp[pr])
            {
                nums[p] = temp[pl];//左边的更小就取左边
                pl++;
            }
            else
            {
                
                re += (mid - pl + 1);
                nums[p] = temp[pr];
                pr++;
            }
            p++;
        }
        if (pl > mid)
        {
            while (pr <= r)
            {
                nums[p] = temp[pr];
                pr++;
                p++;
            }
        }
        else
        {
            while (pl <= mid)
            {
                nums[p] = temp[pl];
                pl++;
                p++;
            }
        }

        //将合并好的部分复制回辅助数组中 提供给上层操作
        for (int i = l; i <= r; i++)
        {
            temp[i] = nums[i];
        }
        return re;
    }
};