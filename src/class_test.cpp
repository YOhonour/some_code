#include <iostream>

using namespace std;
class baseOrigin
{
private:
public:
    int m_age = 10;
    static int b;
};
int baseOrigin::b = -1;

class baseA:virtual public baseOrigin
{
private:
public:
    int m_age = 12;
    static int b;
};
int baseA::b = 1;

class baseB:virtual public baseOrigin
{
private:
public:
    int m_age = 10;
    static int b;
    int C = 23;
};
int baseB::b = 2;


class classTest : public baseB, public baseA
{
public:
    int m_age = 100;
};

int main() {
    classTest cl_test;
    //cl_test.a = 200;
    cl_test.baseA::m_age = 12;
    cl_test.baseB::m_age = 25;
    cout << "cl_test.baseA::m_age = " << cl_test.baseA::m_age << endl;
    cout << "cl_test.baseB::m_age = " << cl_test.baseB::m_age << endl;
    cout << "cl_test.a = " << cl_test.m_age << endl;

    cout << sizeof(classTest)<< endl;
    cout << sizeof(cl_test)<< endl;
    cout << baseA::b << endl;
    cout << cl_test.baseA::b << endl;
    cout << cl_test.baseB::b << endl;
    cout << classTest::baseA::b << endl;
    return 0;
}