#include <iostream>

using namespace std;

class MyValue
{
private:
    int v;
public:
    MyValue(/* args */);
    MyValue(int default_num);

    MyValue& operator=(const MyValue&);
    ~MyValue();
    void add(int num = 1);
    void subtract(int num = 1);
    void show() const;
    //在函数声明后加const表示：该成员函数将不修改对象内部数据，并且此时函数内的this指针也为const（不能使用this指针修改成员属性）

    //static const int Months = 12;
    enum {Months = 12};
    double costs[Months];
};

MyValue::MyValue(/* args */)
{
    std::cout << "MyValue default constructer has been called" << std::endl;
}
MyValue::MyValue(int default_num)
{
    std::cout << "MyValue constructer has been called with default_num = " << default_num << std::endl;
    this->v = default_num;
}
MyValue& MyValue::operator=(const MyValue& other)
{
    std::cout << "MyValue copy constructer has been called with other value = " << other.v << std::endl;
    this->v = other.v;
    return *this;
}
MyValue::~MyValue()
{
    std::cout << "bye bye !" << std::endl;
}

void MyValue::add(int num)
{
    this->v += num;
}
void MyValue::subtract(int num)
{
    this->v -= num;
}
void MyValue::show() const
{
    std::cout << "value = " << (this->v) << std::endl;
}
int main() {
    
    MyValue list[4]{1,2,3};
    list[3] = MyValue(100);
    list[3].show();
    return 0;
}