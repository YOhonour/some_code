#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

std::vector<int> generate(int n) {
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = i + 1; // 创建一个包含1到n的有序数组
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(result.begin(), result.end(), g); // 随机打乱数组

    return result;
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<int> randomPermutation = generate(n);

    std::ofstream outputFile("data.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < n; ++i) {
            outputFile << randomPermutation[i];
            if (i < n - 1) {
                outputFile << ' '; // 在数字之间添加空格
            }
        }
        outputFile.close();
        std::cout << "Random permutation saved to data.txt" << std::endl;
    } else {
        std::cerr << "Error opening data.txt for writing." << std::endl;
    }

    return 0;
}
