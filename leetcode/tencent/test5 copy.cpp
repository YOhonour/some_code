#include <iostream>
#include <vector>
#include <random>

using namespace std;
template<typename returnType> vector<returnType> generateRandomArr(int maxLen, returnType maxValue);

typedef unsigned long long uLL;
typedef unsigned int uINT;
/*
����һ������������A,ţţ��֪�������ж�������������;�����������ֵĳ˻����������������ֵ����
һ�������������ָ�����зǿյ�һ���������֡�
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


//������ɳ��������ֵ��������飬����Ϊ��󳤶Ⱥ����ֵ
template<typename returnType> vector<returnType> generateRandomArr(int maxLen, returnType maxValue){
    random_device seed;//Ӳ���������������
	ranlux48 engine(seed());//���������������������
    uniform_int_distribution<int> distrib_len(1, maxLen);//�����������Χ����Ϊ���ȷֲ� Ϊ������
    uniform_int_distribution<returnType> distrib_value(0, maxValue);//�����������Χ����Ϊ���ȷֲ� ����ҿ�
    int len = distrib_len(engine);
    vector<returnType> arr;
    
    for (int i = 0; i < len; i++)
    {
        returnType temp = distrib_value(engine);
        arr.push_back(temp);
    }
    return arr;
}