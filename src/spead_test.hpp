#include <iostream>
#include <chrono>

void printSpead(size_t times,void (*func)()){
    size_t epocs = 1000000;
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < epocs; i++)
    {
        func();
    }
    auto finish = std::chrono::steady_clock::now();
    using milliseconds = std::chrono::duration<double, std::milli>;
    milliseconds duration = finish - start;
    std::cout << "func() cost " << duration.count() << "ms" << std::endl;
}