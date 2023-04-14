#include <iostream>
#include <vector>
#include <random>

using namespace std;
template<typename returnType> vector<returnType> generateRandomArr(int maxLen, returnType maxValue);

typedef unsigned long long uLL;
typedef unsigned int uINT;
/*
给出一个正整数数组A,牛牛想知道其中有多少子数组满定;里面所有数字的乘积等于里面所有数字的异或。
一个数组的子数组指数组中非空的一段连续数字。
*/
vector<pair<uLL,uLL>> result;
bool valid(vector<uLL>& nums,uLL  startIndex,uLL endIndex){
    uLL prod = 1;
    uLL xor_value = 0;
    for (uLL i = startIndex; i <= endIndex; i++)
    {
        prod = (prod*nums[i]) % INT_MAX;
        xor_value ^= nums[i];
    }
    return prod == xor_value;
}
int test5(vector<uLL>& nums, uLL len){
    for (uLL i = 0; i < len; i++)
    {
        for (uLL j = i+1; j < len; j++){
            if (valid(nums,i,j)) {
                result.push_back({i,j});
            }
        }
    }
    return result.size();
}
vector<uLL> nums;
uLL n;
void getInput(){
    cin >> n;
    nums = vector<uLL>(n,0);
    for (uLL i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}
int main() {
    //getInput();
     
    vector<uLL> re = generateRandomArr(20,(uLL)10);

    cout <<  test5(re,re.size());
    return 0;
}


//随机生成长度随机，值随机的数组，参数为最大长度和最大值
template<typename returnType> vector<returnType> generateRandomArr(int maxLen, returnType maxValue){
    random_device seed;//硬件生成随机数种子
	ranlux48 engine(seed());//利用种子生成随机数引擎
    uniform_int_distribution<int> distrib_len(1, maxLen);//设置随机数范围，并为均匀分布 为闭区间
    uniform_int_distribution<returnType> distrib_value(0, maxValue);//设置随机数范围，并为均匀分布 左闭右开
    int len = distrib_len(engine);
    vector<returnType> arr;
    
    for (int i = 0; i < len; i++)
    {
        returnType temp = distrib_value(engine);
        arr.push_back(temp);
    }
    return arr;
}