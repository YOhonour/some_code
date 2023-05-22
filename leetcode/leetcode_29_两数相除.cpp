#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
int divide(int dividend, int divisor)
{
    bool negitive = false;
    if (divisor == 1)
    {
        return dividend;
    }
    if (divisor == -1)
    {
        long long ans = 0 - (long long)dividend;
        return ans > INT32_MAX ? INT32_MAX : ans;
    }
    negitive ^= dividend < 0;
    negitive ^= divisor < 0;
    long long a = dividend < 0 ? 0 - (long long)dividend : dividend;
    long long b = divisor < 0 ? 0 - (long long)divisor : divisor;
    long long ans = 0;
    long long t = 1;
    
    while (a >= (b << 1))
    {
        b <<= 1;
        t <<= 1;
    }
    ans = t > 1 ? ans + t : ans;
    while (a >= b)
    {
        a -= b;
        ans+= (t);
    }
    return negitive ? ((0 - ans) < INT32_MIN ? INT32_MIN : (0 - ans)) : ans > INT32_MAX ? INT32_MAX : ans;
}
int main()
{
    string s1 = "sadbutsad";
    string s2 = "sad";
    cout << divide(2147483647, 3) << endl;
}