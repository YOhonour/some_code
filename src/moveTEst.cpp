#include <iostream>

using namespace std;
class Dot
{
public:
    int x;
    int y;
    int *data = nullptr;
    int LEN = 10;
    /* data */
    Dot(Dot &dot);
    Dot(Dot &&dot);
    Dot(int x, int y);
    ~Dot();
    Dot&& operator+(Dot &dot);
};

Dot::Dot(Dot &dot)
{
    cout << "拷贝构造" << endl;
    this->x = dot.x;
    this->y = dot.y;
    this->data = new int[dot.LEN];
    for (int i = 0; i < dot.LEN; i++)
        this->data[i] = dot.data[i];
}
Dot::Dot(Dot &&dot)
{
    cout << "移动构造" << endl;
    this->x = dot.x;
    this->y = dot.y;
    this->data = dot.data;

    dot.data = nullptr;
    dot.x = 0;
    dot.y = 0;
}
Dot::Dot(int x, int y)
{
    this->x = x;
    this->y = y;
    this->data = new int[this->LEN];
}

Dot::~Dot()
{
}
Dot&& Dot::operator+(Dot &dot)
{
    Dot temp(this->x + dot.x,
             this->y + dot.y);
    return std::move(temp);
}
int main()
{
    Dot d1(1, 2);
    Dot d2 = d1;

    Dot d3(d1 + d2);
    Dot d4 = (d1 + d2);
    return 0;
}