#include <iostream>

#include "mytime2.hpp"

using namespace std;

//友元函数实现
Time operator*(double d, Time & t){
    Time temp;
    long totalminutes = t.hours * 60 * d + t.minutes * d;
    temp.hours = totalminutes / 60;
    temp.minutes = totalminutes % 60;
    return temp;
}
std::ostream & operator<<(std::ostream & io, const Time & t){
    io << t.hours << " : " << t.minutes;
    return io;
}

int main() {
    Time time(12);
    Time time_copy(22);
    time.show();
    (time*1.5).show();
    (1.5*time).show();

    cout << time  << time_copy;
    return 0;
}