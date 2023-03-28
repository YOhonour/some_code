#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long uLL;
typedef unsigned int uINT;
/*
给出一个正整数数组A,牛牛想知道其中有多少子数组满定;里面所有数字的乘积等于里面所有数字的异或。
一个数组的子数组指数组中非空的一段连续数字。
*/
vector<pair<uLL,uLL>> result;
bool valid(uLL nums[],uLL  startIndex,uLL endIndex){
    uLL prod = 1;
    uLL xor_value = 0;
    for (uLL i = startIndex; i <= endIndex; i++)
    {
        prod = (prod*nums[i]) % INT_MAX;
        xor_value ^= nums[i];
    }
    return prod == xor_value;
}
int test5(uLL nums[], uLL len){
    for (uLL i = 0; i < len; i++)
    {
        for (uLL j = i+1; j < len; j++)
        {
            if (valid(nums,i,j))
            {
                result.push_back({i,j});
            }
            
        }
        
    }
    return result.size();
}
uLL* in;
uLL n;
void getInput(){
    cin >> n;
    in = new uLL[n]{0};
    for (uLL i = 0; i < n; i++)
    {
        cin >> in[i];
    }
}
int main() {
    getInput();
    cout <<  test5(in,n);
    return 0;
}