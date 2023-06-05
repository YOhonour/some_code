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
        ans += (t);
    }
    return negitive ? ((0 - ans) < INT32_MIN ? INT32_MIN : (0 - ans)) : ans > INT32_MAX ? INT32_MAX
                                                                                        : ans;
}

int myMul(int x, int n)
{
    
    int ans = 0;
    bool pos = (x < 0 && n < 0) || (x > 0 && n > 0) ? true : false;
    int b = n < 0 ? -n : n;
    x = x < 0 ? -x : x;
    while (b > 0)
    {
        if (b & 1 == 1)
        {
            if (ans > INT32_MAX - x)
            {
                return INT32_MAX;
            }
            ans += x;
        }
        b >>= 1;
        x <<= 1;
    }
    return pos ? ans : -ans;
}

// z * y >= x 是否成立 使用快速乘
bool test(int x, int y, int z)
{
    int res = 0, add = y;
    while (z > 0)
    {
        if (z & 1 == 1)
        {
            if (res < x - add)
            {
                return false;
            }
            res += add;
        }

        if (z != 1)
        {
            if (add < x - add)
            {
                return false;
            }
            add += add;
        }
        z >>= 1;
    }
    return true;
}
int divide1(int dividend, int divisor)
{
    if (divisor == 0)
        return 0;
    if (dividend == divisor)
        return 1;
    if (dividend == INT32_MIN)
    {
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return INT32_MAX;
    }
    if (divisor == INT32_MIN)
    {
        if (dividend == divisor)
            return 1;
        else
        {
            return 0;
        }
    }

    bool pos = (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) ? true : false;
    divisor = divisor > 0 ? -divisor : divisor;
    dividend = dividend > 0 ? -dividend : dividend;
    int left = 1, right = INT_MAX;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        bool cheak = test(dividend, divisor, mid); // z * y >= x 是否成立
        if (cheak)
        {
            ans = mid;
            if (mid == INT_MAX)
            {
                break;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return pos ? ans : -ans;
}
int main()
{
    string s1 = "sadbutsad";
    string s2 = "sad";
    cout << divide1(-2147483648, -1) << endl;
}