#include <iostream>

using namespace std;

template <typename T> T average(T a,T b);

int main() {
    cout << average(3,6) << endl;
    cout << average<double>(3,6) << endl;
    cout << average(3.0,6.0) << endl;
    return 0;
}
template <typename T>T average(T a,T b){
    return (a + b) / 2;
}



