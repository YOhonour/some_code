#include <iostream>
#include <chrono>

using namespace std;
class Teat{
public:
    int a[10] = {0};
};

Teat foo(Teat& a){
    Teat b = a;
    b.a[0] = 9;
    return b;
}
Teat foo2(Teat a){
    Teat b = a;
    b.a[0] = 9;
    return b;
}
struct job
{
    char name[20];
    double salary;
    int floor;
};


template<typename AnyType>void Swap(AnyType& a,AnyType& b);//任意类型的函数模板
template<> void Swap<job>(job& a,job& b);//“显示具体化” 指定类型的函数模板，
int main() {
    // int arr[4] = {0};
    // cout << "sizeof(arr) = " << sizeof(arr) << endl;
    // cout << "sizeof(arr[0]) = " << sizeof(&(arr[0])) << endl;
    // int a = 1,b = 3;
    // const int * ar = &a;
    // int const * ar2 = &b;
    // ar = &b;
    // ar2 = &a;
    // *ar2 = 5;
    // *ar = 4;
    // int arr3[3][4] = {0};
    // cout << "sizeof(arr3) = " << sizeof(arr3) << endl;
    // int* & ar4 = &a;
    // cout << *ar << endl;
    int s1 = 1,s2 = 1200;
    std::cout << "s1=" << s1 << ",s2="<< s2 << std::endl;
    Swap<int>(s1,s2);
    std::cout << "s1=" << s1 << ",s2="<< s2 << std::endl;
    Teat t1,t3;
    Teat t2 = foo(t1);

    size_t epocs = 1;
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < epocs; i++)
    {
        foo(t1);
    }
    auto finish = std::chrono::steady_clock::now();
    using milliseconds = std::chrono::duration<double, std::milli>;
    milliseconds duration = finish - start;
    std::cout << "foo(t1) cost " << duration.count() << "ms" << std::endl;
    
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < epocs; i++)
    {
        foo2(t3);
    }
    finish = std::chrono::steady_clock::now();
    duration = finish - start;
    std::cout << "foo2(t3) cost " << duration.count() << "ms" << std::endl;

    return 0;
}

template<typename AnyType>
void Swap(AnyType& a,AnyType& b){
    AnyType temp;
    temp = a;
    a = b;
    b = temp;
}

template<> void Swap<job>(job& a,job& b){
    double t1 = a.salary;
    a.salary = b.salary;
    b.salary = t1;
}