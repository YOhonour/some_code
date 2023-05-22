#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> digi_str = {"",
                           "", "abc", "def",
                           "ghi", "jkl", "mno",
                           "pqrs", "tuv", "wxyz"};
vector<string> res;
string temp;
void rcrr(int index,string &digits){
    if(index >= digits.size()){
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < digi_str[digits[index] - '0'].size(); i++)
    {
        temp.push_back(digi_str[digits[index] - '0'][i]);
        rcrr(index+1,digits);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.size() == 0) return res;
    rcrr(0,digits);
    return res;
}
int main()
{
    vector<string> digi_str2 = {"",
                           "", "abc", "def",
                           "ghi", "jkl", "mno",
                           "pqrs", "tuv", "wxyz"};
    vector<int> nums = {1, 1, 1, 1};
    auto a = letterCombinations("23");
    for(auto it : a){
        cout << it << ' ';
    }
    return 0;
}