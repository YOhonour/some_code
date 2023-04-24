#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
/*
算法的思路大概如下：

    统计原字符串 $s$ 中字符 'R' 的数量，记为 $r$。

    计算 $s$ 的字典序排名，记为 $rank$。

    枚举新字符串的第一个字符，可以是 'R' 也可以是 'B'。如果新字符串的第一个字符是 'R'，则其权值为 $r$；否则其权值为 $r-1$。将其加入结果中。

    对于新字符串的剩余 $n-1$ 个字符，从左往右逐位确定，设当前确定到第 $i$ 位，已确定的前缀为 $pre$，则有以下两种情况：

        如果 $pre_i = s_i$，那么当前位可以和 $s_i$ 一样，也可以和 $s_i$ 之后的任意一个字符一样。此时，如果 $s_i$ 是 'R'，则对结果的贡献为 $r-i$；否则对结果的贡献为 $r-i-1$。

        如果 $pre_i < s_i$，那么当前位必须和 $s_i$ 一样。此时，如果 $s_i$ 是 'R'，则对结果的贡献为 $r-i$；否则对结果的贡献为 $r-i-1$。如果在确定第 $i$ 位时，当前前缀 $pre$ 已经小于 $s$ 的前缀，那么直接退出循环，不需要继续计算。

    返回结果。

注：这个算法的时间复杂度是 $O(n)$，可以通过本题。
*/
int res = 0;
int count_R = 0;
int dp(string &s)
{
    if (s.size() < 1)
    {
        return 0;
    }

    vector<int> dp(s.size() + 2, 0);
    for (size_t i = 2; i < dp.size(); i++)
    {
        if (dp[i - 1] >= count_R)
        {
            dp[i] = (dp[i-1] * 2 + 1) % MOD;
        }
        else
        {
            if (s[i - 2] == 'R')
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] =  (dp[i-1]  + 1 ) % MOD;
            }
        }
    }
    return dp[s.size()];
}
void dfs(string &s, int index, int last_v)
{
    if (index >= s.size())
    {
        res = (res + last_v) % MOD;
        return;
    }
    if (last_v >= count_R)
    {
        if (s[index] == 'R')
        {
            dfs(s, index + 1, last_v + 1);
            s[index] = 'B';
            dfs(s, index + 1, last_v);
            s[index] = 'R';
        }
        else
        {
            dfs(s, index + 1, last_v);
            s[index] = 'R';
            dfs(s, index + 1, last_v + 1);
            s[index] = 'B';
        }
    }
    else
    {
        if (s[index] == 'R')
        {
            dfs(s, index + 1, last_v + 1);
        }
        else
        {
            dfs(s, index + 1, last_v);
            s[index] = 'R';
            dfs(s, index + 1, last_v + 1);
            s[index] = 'B';
        }
    }
}

int main()
{
    // int n;
    // cin >> n;
    string s;
    cin >> s;
    int t = s[0] == 'R' ? 1 : 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
            count_R++;
    }
    cout <<  MOD *2 << endl;
    dfs(s, 1, t);
    cout << res << endl;
    res = dp(s);
    cout << res << endl;

    return 0;
}
