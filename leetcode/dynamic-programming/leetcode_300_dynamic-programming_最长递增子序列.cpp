/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f = {nums[0]};
        int n = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(int num =nums[i]; f.back() < nums[i]){
                f.push_back(num);
            }else{
                auto it = lower_bound(f.begin(),f.end(),num);
                *it = num;
            }
        }
        return f.size();
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> f,ans;
        int n = 0;
        for(int i = 0; i < obstacles.size(); i++) {
            if(int num = obstacles[i]; obstacles.empty() || f.back() >= obstacles[i]){
                f.push_back(num);
                ans.push_back(f.size());
            }else{
                int index = upper_bound(f.begin(),f.end(),num) - f.begin();
                ans.push_back(index + 1);
                f[index] = num;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,3,2};
    Solution s;
    s.longestObstacleCourseAtEachPosition(nums);
}
// @lc code=end

