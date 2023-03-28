#include <iostream>
#include <random>
using namespace std;
template<typename returnType> pair<int,returnType*> generateRandomArr(int maxLen, returnType maxValue);
int main() {
    using namespace std;
    int count_arr = 10;
    for (int i = 0; i < count_arr; i++)
    {
        pair a = generateRandomArr(20,100);
        cout << "数组长度=" << a.first << "; ";
        for (int i = 0; i < a.first; i++)
        {
            cout << a.second[i] << " ";
        }
        cout << endl;
    }
    
    pair a = generateRandomArr(20,100.0);
    
    return 0;
}
//随机生成长度随机，值随机的数组，参数为最大长度和最大值
template<typename returnType> pair<int,returnType*> generateRandomArr(int maxLen, returnType maxValue){
    random_device seed;//硬件生成随机数种子
	ranlux48 engine(seed());//利用种子生成随机数引擎
    uniform_real_distribution<> distrib_len(1, maxLen);//设置随机数范围，并为均匀分布
    uniform_real_distribution<> distrib_value(0.0, maxValue);//设置随机数范围，并为均匀分布
    int len = distrib_len(engine);
    returnType* arr = new returnType[sizeof(returnType)*len];

    for (int i = 0; i < len; i++)
    {
        arr[i] = distrib_value(engine);
    }
    return {len,arr};
}