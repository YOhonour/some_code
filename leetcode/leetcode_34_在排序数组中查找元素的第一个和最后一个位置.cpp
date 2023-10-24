/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include "stdc++.h"
using namespace std;
class Solution {
public:
    int binarySerch_L(vector<int>& nums, int target,int l, int r){
        int mid = l + (r - l) / 2;
        if(l == r){
            return nums[mid] == target ? mid : -1;
        }
        if (target <= nums[mid]){
            return binarySerch_L(nums,target,l,mid);
        }else{
            return binarySerch_L(nums,target,mid + 1,r);
        }
    }
    int binarySerch_R(vector<int>& nums, int target,int l, int r){
        int mid = r - (r - l) / 2;
        if(l == r){
            return nums[mid] == target ? mid : -1;
        }
        if (target < nums[mid]){
            return binarySerch_R(nums,target,l,mid-1);
        }else{
            return binarySerch_R(nums,target,mid,r);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.size() < 1) return res;
        res[0] = binarySerch_L(nums,target,0,nums.size() - 1);
        res[1] = binarySerch_R(nums,target,0,nums.size() - 1);
        return res;
    }
};

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    Solution solu;
    string aastr = "sdasd";
    vector<char> cc = {'a','b','b'};
     auto aa = solu.searchRange(nums, 8);
    cout << aa[0] << ' ' << aa[1] ;

}
// @lc code=end

