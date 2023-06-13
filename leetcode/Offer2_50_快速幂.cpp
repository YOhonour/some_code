#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double myPow(double x, int n)
{
    double ans = 1;
    long long b = n;
    if (b < 0){
        x = 1/x;
        b = -1*b;
    }
    while (b > 0)
    {
        if(b & 1 == 1){
            ans *= x;
        }
        b >>= 1;
        x = x*x;
    }
    
    return ans;
}
int myMul(int x, int n)
{
    int ans = 0;
    bool pos = (x < 0 && n < 0) || (x > 0 && n > 0) ? true : false;
    int b = n < 0 ? -n : n;
    x = x < 0 ? -x : x;
    while (b > 0)
    {
        if(b & 1 == 1){
            ans += x;
        }
        b >>= 1;
        x <<= 1;
    }
    return pos ? ans : -ans;
}

int main(){
    cout << myMul(2,-2);
}