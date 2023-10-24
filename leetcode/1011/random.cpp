#include <iostream>
#include <vector>
#include <random>

std::vector<int> generateRandomIntArray(int count, int minValue, int maxValue)
{
    std::vector<int> result;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < count; i++)
    {
        int randomNumber = dist(mt);
        result.push_back(randomNumber);
    }

    return result;
}

void genarateAndPrint()
{
    int count = 500; // 生成10个随机整数
    int minValue = -1000;
    int maxValue = 1000;
    std::vector<int> randomArray = generateRandomIntArray(count, minValue, maxValue);

    std::cout << "随机整数数组：" << std::endl;
    for (int num : randomArray)
    {
        std::cout << num << ",";
    }
    std::cout << std::endl;
}
int generateRandomNumber(int minValue, int maxValue) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    return dist(mt);
}
void test1Data()
{
    int M = generateRandomNumber(1,10);
    int N = generateRandomNumber(1,100);
    int X = generateRandomNumber(1,1000);
    std::vector<int> q = generateRandomIntArray(X,1,1000);
    std::cout << M << ' ' << N << std::endl;
    std::cout << X << std::endl;
    for (int num : q)
    {
        std::cout << num << ",";
    }
    std::cout << std::endl;
}
int main()
{
    // test1Data();
    genarateAndPrint();
    return 0;
}
