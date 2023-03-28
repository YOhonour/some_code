/*
给定N个字符串，每个字符串全部由小写字母组成，且每个字符串的长度最多为8
请你判断有多少重组字符串，重组字符串有以下规则:
    1.从每个字符串里面都抽取1个字母组成
    2.新字符串不能有2个相同的字母请问总共能组成多少个重组字符串
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> result;
vector<string> base;
//需要判断是否已经有了
void joinResults(string& cur){
    for (size_t i = 0; i < result.size(); i++){
        if (result[i] == cur) return;
    }
    result.push_back(string(cur));
}
vector<string> getInputs(){
    int n;
    cin >> n;
    cin.get();
    vector<string> res;
    char *buf = new char[8];
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s; // 会自动忽略首个分隔符
        // getline(cin,s);//可能会读取到空行，需要使用cin.get();清除 不推荐
        res.push_back(s);
    }
    delete[] buf;
    return res;
}
bool valied(string &cur, char c)
{
    if (cur.length() == 0)
        return true;
    for (size_t i = 0; i < cur.length(); i++)
        if (cur[i] == c)
            return false;
    return true;
}
void solveStrings(string &cur, size_t row)
{

    if (row == base.size() - 1)
    {
        for (int i = 0; i < base[row].length(); i++)
        {
            if (valied(cur, base[row][i]))
            {
                cur.push_back(base[row][i]);//加入当前str
                joinResults(cur);//加入解集
                cur.pop_back();//退出
            }
        }
        return;
    }
    for (int i = 0; i < base[row].length(); i++)
    {
        if (valied(cur, base[row][i]))
        {
            cur.push_back(base[row][i]);
            solveStrings(cur, row+1);//下一行
            cur.pop_back();
        }
    }
}
int main()
{
    base = getInputs();
    char min = 'z';
    for (size_t i = 0; i < base.size(); i++){
        sort(base[i].begin(), base[i].end(), [](auto a, auto b){ return a < b; }); // 升序
    }
    string cur = "";
    solveStrings(cur,0);
    cout << result.size() << endl;
    return 0;
}