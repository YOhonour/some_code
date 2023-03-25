#ifndef _MYTIME2_H_
#define _MYTIME2_H_

#include<iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h,int m);
    void AddMin(int m);
    void AddHr(int h);
    void show();
    Time operator*(double d) const;

    //友元函数声明
    friend Time operator*(double d, Time & t);
    //friend void operator<<(std::ostream & io, const Time & t); //这个版本不能 cout << time << time
    friend std::ostream& operator<<(std::ostream & io, const Time & t);
};

Time::Time(){}

Time::Time(int h,int m=0)
{
    this->hours = h;
    this->minutes = m;
}

void Time::AddMin(int m){
    this->minutes += m;
}
void Time::AddHr(int h){
    this->hours += h;
}
Time Time::operator*(double d) const
{
    Time temp;
    long totalminutes = hours * 60 * d + minutes * d;
    temp.hours = totalminutes / 60;
    temp.minutes = totalminutes % 60;
    return temp;
}
void Time::show(){
    std::cout << this->hours << " : " << this->minutes << std::endl;
}


#endif