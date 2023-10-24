#include<iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
int getMaxHappiness2(vector<int> nums) {
    sort(nums.begin(),nums.end(),[](int & a, int & b){return a < b;});
    int sum = 0;
    vector<int> not_good;
    vector<int> good;
    for(auto i : nums){
        if(i <= 0){
            not_good.push_back(i);
        }
        else{
            sum+=i;
            good.push_back(i);
        }
        
    };
    if(sum <= 0){
        cout << 0 << endl;
        return 0;
    } 
    long long res = 0;
    int can_add = 0;
    for(int i = 0 ; i < good.size(); i++){
        res += good[i]*(i + 1); 
        can_add += good[i];
    };
    int count = 0;
    int reduce = 0;
    int index =0;
    if(!not_good.empty()){
        while(abs(not_good[index]) > can_add && index <= not_good.size()){
        index++;
    }; 
    }
    
    if(index == not_good.size()) return res ;
    else {
        for(index ; index < not_good.size();index++){
            count++;
            reduce += count * not_good[index];
            
        };
        res += count* can_add+ reduce;
        return res ;;
    }
}
int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    string input;
    getline(cin,input);
    stringstream ss(input);
    string token;
    vector<int> nums;
    while(getline(ss,token,',')){
        nums.push_back(stoi(token));
    }
    int res = getMaxHappiness2(nums);
    cout << res << endl;
}