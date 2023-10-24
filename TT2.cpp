#include <iostream>
#include <set>
int main() {
    int n;
    std::cin >> n;
    std::set<int> sizes; // 用于存储已经出现的橡皮泥士兵大小
    int total_additions = 0; // 总共需要添加的橡皮泥单位数
    for (int i = 0; i < n; ++i) {
        int size;
        std::cin >> size;
        // 如果当前大小已经出现过，则需要添加足够的单位橡皮泥使其不相同
        while (sizes.count(size) > 0) {
            size++; // 增加橡皮泥单位
            total_additions++; // 增加总单位数
        }
        sizes.insert(size); // 将当前大小添加到集合中
    }
    std::cout << total_additions << std::endl;
    return 0;
}
/*
5
1 1 2 3 3
*/