#include <iostream>
#include <stack>
#include <algorithm>
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/
using namespace std;
int longestValidParentheses(string s) {
    if (s.length() < 2) return 0;
    int dp_size = s.length();
    //vector<int> dp(dp_size, 0);//dp表示 第i个字符所能匹配的最大长度
    int* dp = new int[dp_size] {0};
    int max = 0;
    for (int i = 1; i < dp_size; i++)
    {
        if (s.at(i) == ')') {
            if (s.at(i - 1) == '(') {
                //第一种情况是 前一个字符是可以匹配上的
                dp[i] = (i - 2) < 0 ? 2 : dp[i - 2] + 2;
            }
            else if ((i - dp[i - 1] - 1) >= 0 && s.at(i - dp[i - 1] - 1) == '(') {
                //第二种情况是 可以与上一段有效字符串之前的那个匹配上，如果可以匹配上，更新的值应该考虑当前匹配字段再上一个的dp值
                dp[i] = dp[i - 1] + 2;
                dp[i] = i - dp[i] < 0 ? dp[i] : dp[i] + dp[i - dp[i]];
            }
            else {
                dp[i] = 0;
            }
            max = max < dp[i] ? dp[i] : max;
        }
        else {
            dp[i] = 0;
        }
    }
    return max;
}
    int longestValidParentheses2(string s) {
        //栈方法 错误
        if(s.length() < 2) return 0;
        stack<char> stack;
        int max = 0;
        bool flag = false;
        int temp = 0;
        int last_endIndex = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if(!stack.empty() && stack.top()=='(' && s.at(i) == ')'){
                if(flag == false ){
                    temp = 0;
                }
                temp += 2;
                flag = true;
                max = max < temp ? temp : max;
                stack.pop();
                last_endIndex = i;
            }else {
                flag = false;
                stack.push(s.at(i));
            }
        }
        return max;
    }
int main() {
    cout << longestValidParentheses("()(())");
    return 0;
}