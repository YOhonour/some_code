#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct tmp2 //重写仿函数
{
    bool operator() (vector<int> &a, vector<int> &b) 
    {
        return a[2] > b[2]; //小顶堆
    }
};
int main() {
    int n,m,s;
    cin >> n >> m >> s;
    vector<vector<int>> edge(m,vector<int>(3,0));
    priority_queue <vector<int>,vector<vector<int>>,tmp2 > q;
    for (size_t i = 0; i < m; i++)
    {
        vector<int> temp(3,0);
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        temp = edge[i];
        q.push(temp);
    }
    
    return 0;
}