#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_set>
using namespace std;
int fun(int x)
{
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((x >> i) & 1)
        {
            cnt++;
        }
    }
    return cnt % 2;
}

int min_capacity(const std::vector<int>& in, const std::vector<int>& out) {
    std::unordered_set<int> parking; // 使用集合模拟停车场
    int max_capacity = 0;
    size_t out_index = 0;

    for (int car : in) {
        parking.insert(car); // 车辆进入停车场
        // 如果Out中的下一辆要离开的车已经在停车场内，则让它离开
        while (out_index < out.size() && parking.find(out[out_index]) != parking.end()) {
            parking.erase(out[out_index]);
            out_index++;
        }
        // 更新最大容量
        if (parking.size() > max_capacity) {
            max_capacity = parking.size();
        }
    }

    return max_capacity + 1;
}


int main() {
    std::vector<int> n = {3, 2, 4, 1};
    std::vector<int> Out = {3, 2, 4, 1};
    
    std::cout << "Minimum capacity needed: " << min_capacity(n, Out) << std::endl;

    return 0;
}
