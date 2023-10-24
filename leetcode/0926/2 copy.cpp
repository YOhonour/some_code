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
int main() {
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> price(n);
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int maxp=0;
    backtracking(price, val, 0, k, 0, 0, maxp);
    if(maxp==0){
        cout<<-1;
    }
    else{
        cout<<maxp;
    }
    return 0;
}