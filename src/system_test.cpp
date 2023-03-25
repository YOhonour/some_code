#include <iostream>
#include <chrono>

using namespace std;
class T{
public:
    int data;
    T(int data){
        this->data = data;
        std::cout << "有参构造 被调用" << std::endl;
    }
    T(){
        std::cout << "默认构造 被调用" << std::endl;
    }
    T(const T& t){
        this->data = t.data;
        //std::cout << "拷贝构造 被调用" << std::endl;
    }
    int test(int a){
        this->data += a;
        return 0;
    }
    ~T(){
        this->data = -1;
    }
    T operator +(const T& t){
        
        return T(this->data + t.data);
    }
    T& operator ++(){
        //std::cout << "前缀自增 被调用" << std::endl;
        this->data++;
        return *this;
    }
    const T operator ++(int){
        T temp = *this;
        //temp.data++;
        this->data++;
        //cout << " temp addres = "<< &temp << endl;
        return temp;
    }
    /*
    前置操作返回的是加1后的值，返回的是对象本身，所以这是左值。
    后置操作返回的是加1前的值，其返回值可以近似的理解为与原操作数值相等的常量，所以是一个右值。
    
    由于后置操作符要返回未加1前的值作为操作的结果，所以必须要保存操作数原来的值（即上一篇说的临时对象），对于比较复杂的类型，这种额外工作可能会花费更大的代价。
    建议：只有在必要时才使用后置操作符。
    */
};
int main() {
    T t = T(1);
    size_t epocs = 1000000;
    auto start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < epocs; i++)
    {
        ++t;
    }
    auto finish = std::chrono::steady_clock::now();
    std::cout << "t.data = " << t.data << std::endl;
    using milliseconds = std::chrono::duration<double, std::milli>;
    milliseconds duration = finish - start;
    std::cout << "++t cost " << duration.count() << "ms" << std::endl;
    T newt;
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i < epocs; i++) {
        t++;
    }
    finish = std::chrono::steady_clock::now();
    std::cout << "newt.data = " << newt.data << std::endl;
    std::cout << "t.data = " << t.data << std::endl;
    duration = finish - start;
    std::cout << "t++ cost " << duration.count() << "ms" << std::endl;


    
    return 0;
}