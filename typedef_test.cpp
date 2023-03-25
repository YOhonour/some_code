#include <iostream>
#include <typeinfo> 
using namespace std;

typedef int* pIINT;

int main() {
    // int *a,b;
    // pIINT c;
    char ch;
    int count = 0;
    cin.get(ch);
    
    auto a = ch + 1;
    cout << "ch + 1  type : " << typeid(a).name() << endl; 
    auto b = ch++;
    cout << "ch++  type : " << typeid(b).name() << endl; 
    auto c = ++ch;
    cout << "++ch  type : " << typeid(c).name() << endl; 

    while (cin.fail() == false)
    {
        if (ch == '\n')
            cout << ch;
        else {
            cout << (char)(ch + 1);

        }
        count ++;
        cin.get(ch);
    }
    cout << "输入完毕" << endl;
    return 0;
}