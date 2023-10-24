/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        dfs(0, s, 0);
        return res;
    }
    const int MAX = 255;
    const int MIN = 0;
    vector<string> res;
    bool isValid(string &target)
    {
        if (target.size() > 3)
            return false;
        if (target.at(0) == '0' && target.size() > 1)
        {
            return false;
        }
        auto aa = stoi(target);
        return (aa <= MAX && aa >= MIN);
    }
    void dfs(int index, string &s, int dot_cnt)
    {
        if (index == s.size())
        {
            res.emplace_back(s);
            return;
        }

        if (dot_cnt == 3)
        {
            if (s.size() - index > 3)
            {
                return;
            }
            string temp = s.substr(index, s.size() - index);
            if (isValid(temp))
            {
                dfs(s.size(), s, dot_cnt);
            }
        }
        else
        {
            for (int i = 1; i <= 3; i++)
            {
                string temp = s.substr(index, i);
                if (index + i >= s.size())
                {
                    return;
                }
                if (isValid(temp))
                {
                    s.insert(index + i, 1, '.');
                    dfs(index + i + 1, s, dot_cnt + 1);
                    s.erase(index + i, 1);
                }
            }
        }
    }
};
int main()
{
    Solution s;
    s.restoreIpAddresses("0279245587303");
    return 0;
}
// @lc code=end
