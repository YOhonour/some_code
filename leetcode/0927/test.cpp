#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void backtracking(vector<int> &price, vector<int> &val,int begin, int k, int nowPrice, int nowVal, int &maxp){
    if(nowVal != 0){
        double bi = nowPrice;
        bi = bi/nowVal;
        if( bi-k ==0 ){
            maxp = max(nowPrice, maxp);
        }
    }
    for(int i = begin;i<price.size();i++){
        nowPrice +=price[i];
        nowVal +=val[i];
        backtracking(price, val, i+1,k,nowPrice, nowVal, maxp);
        nowPrice -=price[i];
        nowVal -=val[i];
    }
}
class A
{
private:
    /* data */
public:
    A(/* args */){};
    A(int a){};
    A(int a,int b){};
};
class B : public A
{
private:
    /* data */
public:
    using A::A;
};

int main() {
    B b();
    B b1(1);
    B b2(1,2);
    return 0;
}