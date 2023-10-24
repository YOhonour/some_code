#include <iostream>
#include <vector>

using namespace std;

int fun(int a){
    int b = 0;
    static int c = 3;
    a = (c++,b++);
    return (a);
}
int main() {
    int a = 2,i,k;
    for(i = 0; i < 2; i++) {
        k = fun(a++);
    }
    cout << k;
    return 0;
}
