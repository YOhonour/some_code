#include <iostream>

#include "stdc++.h"
using namespace std;
int sumOfSquares(vector<int> &nums)
{
    int res = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            res += (nums[i - 1] * nums[i - 1]);
        }
    }
    return res;
}

unordered_map<int, int> num_map;
int maxVal;
void updateBeauty(vector<int> &nums)
{
    for (const auto &pair : num_map)
    {
        if (pair.second > maxVal)
        {
            maxVal = pair.second;
        }
    }
}
void dfs(vector<int> &nums, int k, vector<bool> &vis, int begain);
int maximumBeauty(vector<int> &nums, int k)
{
    vector<bool> vis(nums.size(), false);
    for (int i = 0; i < nums.size(); i++)
    {
        num_map[nums[i]]++;
    }
    dfs(nums, k, vis, 0);
    return maxVal;
}
void dfs(vector<int> &nums, int k, vector<bool> &vis, int begain)
{
    if (begain == nums.size())
    {
        updateBeauty(nums);
        return;
    }
    for (int i = begain; i < nums.size(); i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        for (int j = nums[i] - k; j <= nums[i] + k; j++)
        {

            if (num_map[j] != 0)
            {
                int temp = nums[i];
                nums[i] = j;
                num_map[j]++;
                num_map[temp]--;
                if (num_map[temp] == 0)
                    num_map.erase(temp);
                dfs(nums, k, vis, begain + 1);
                num_map[j]--;
                if (num_map[j] == 0)
                    num_map.erase(j);
                num_map[temp]++;
                nums[i] = temp;
            }
        }
        vis[i] = false;
        dfs(nums, k, vis, begain + 1);
    }
}
int maximumBeauty1(vector<int> &nums, int k)
{
    int maxVal = 0;
    sort(nums.begin(), nums.end());
    for (int l = 0, r = 0; r < nums.size(); r++)
    {
        while (nums[r] - nums[l] > 2 * k)
            l++;
        maxVal = max(maxVal, r - l + 1);
    }
    return maxVal;
}
int finfBeauty(unordered_map<int, int> &freq_map, int m)
{
    int maxCount = 0, Val = -121212;
    for (const auto &pair : freq_map)
    {
        if (pair.second > maxCount && pair.second * 2 > m)
        {
            maxCount = pair.second;
            Val = pair.first;
        }
    }
    return Val;
}
int minimumIndex(vector<int> &nums)
{
    int m = nums.size();
    unordered_map<int, int> freq_map_L;
    unordered_map<int, int> freq_map_R;
    for (int i = 0; i < nums.size(); i++)
    {
        freq_map_R[nums[i]]++;
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        freq_map_L[nums[i]]++;
        freq_map_R[nums[i]]--;
        if (freq_map_R[nums[i]] == 0)
            freq_map_R.erase(nums[i]);
        int bl = finfBeauty(freq_map_L, i + 1);
        int br = finfBeauty(freq_map_R, m - i - 1);
        if (br != -121212 && bl != -121212 && bl == br)
        {
            return i;
        }
    }
    return -1;
}
int longestValidSubstring(string word, vector<string> &forbidden)
{
    unordered_map<string, int> freq_map;
    for (const auto &it : forbidden)
    {
        freq_map[it]++;
    }
    unordered_map<int, vector<string>> unin;
    for (int len = 1; len < word.size(); len++)
    {
        vector<string> temp;
        for (int i = 0; i < word.size() - len; i++)
        {
            temp.push_back(word.substr(i, len));
        }
        unin[len] = temp;
    }
    for (int len =  word.size() - 1; len > 0; len++){
        auto &it = unin[len];
        for(auto &vec : it){
            if()
        }
    }
}
int main()
{
    vector<int> nums = {2, 1, 3, 1, 1, 1, 7, 1, 2, 1};
    for (int i = 0; i < 50; i++)
    {
        // nums.push_back(50);
    }
    cout << minimumIndex(nums);
    return 0;
}