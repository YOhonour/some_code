#include <iostream>
#include <vector>

using namespace std;
/*
小红很喜欢"red"字符串，她定义一个字符串的美丽度为：该字符串包含的"red"子序列的数量。
注意子序列是可以不连续的，例如"rreed"包含了4个"red"子序列，因此美丽度为4。

小红定义一个字符串的权值为：该字符串所有连续子串的美丽度之和。
例如，"redd"的权值为3，因为它包含了一个"red"连续子串，美丽度为1，包含了一个"redd"连续子串，美丽度为2。其它连续子串的美丽度都为0。

小红想知道，长度为n的、仅由字符'r'、'e'、'd'构成的所有字符串（共有3^n个字符串）的权值之和是多少？答案请对10^9+7取模。
*/
int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 6;
    for (int i = 0; i < dp.size(); i++)
    {
        
        
    }
    
    return 0;
}