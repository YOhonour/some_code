#include <iostream>

using namespace std;
class Base
{
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};
typedef void (*Fun)(void);

int main() {
    Base b;
    Fun fp = NULL;
    cout << "虚函数表地址：" << (long*)*(long*)(&b) << endl;
    cout << "虚函数表第一个虚函数指针地址：" << (long*)*(long*)(&b) << endl;
    for (int i = 0; i != 3; ++i) {
        fp = (Fun) * ((long long*)*(long long*)(&b) + i);
        fp();
    }
    return 0;
}