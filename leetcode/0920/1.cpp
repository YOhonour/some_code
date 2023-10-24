#include <vector>
#include <iostream>
#include <string>
using namespace std;

string caculate(string &s){
    int index = s.find("ab");
    bool flag = index != -1;//是否包含子串
    while(flag){
        s = s.erase(index,2);
        index = s.find("ab");
        flag = index != -1;
    }
    if(s.size() == 0){
        return "YES";
    }
    return "NO";
};

string test_ab(string &s){
    int n = s.size();
    while(s.size()){
        if(s[0] == 'a' && s[1] == 'b') s = s.substr(2,s.size());
        else if(s[0] == 'a' && s[n-1] == 'b') s = s.substr(1, s.size() - 2);
        else {break;}
    }
    if(s.size() == 0){
        return "YES";
    }
    return "NO";
};
int main(){
    string s1 = "aabaababbabb";
    string s2 = "aabaababbabb";
    cout << caculate(s1) << endl;
    cout << test_ab(s2) << endl;
}