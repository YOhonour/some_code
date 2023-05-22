#include <iostream>
#include <vector>

using namespace std;
pair<int,int> MaxSum(int nums[], int n)
{
    int t = nums[0];
    int res = 0;
    int ans_l = 0, ans_r = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (t <= 0)
        {
            t = nums[i];
            l = i;
            r = i;
        }
        else
        {
            t += nums[i];
            r = i;
        }
        if (t > res)
        {
            res = t;
            ans_l = l;
            ans_r = r;
        }
        res = t > res ? t : res;
    }
    return {ans_l,ans_r};
}
int main()
{
    int nums[] = {6, -3, -2, 7, -15, 1, 2, 2};
    auto a = MaxSum(nums, 8);
    for (int i = a.first; i <= a.second; i++)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}