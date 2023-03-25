#include <iostream>
#include <vector>
#include <set>

#include<algorithm>

using namespace std;
/*
敌人的位置将被一个二维坐标(x,y)所描述。
小美有一个全屏技能，该技能能一次性将若干敌人一次性捕获。捕获的敌人之间的横坐标的最大差值不能大于A，纵坐标的最大差值不能大于B
现在给出所有敌人的坐标，你的任务是计算小美一次性最多能使用技能捕获多少敌人。
*/
/*
1.将所有的点按照横坐标从小到大排序
2.枚举第一个点P，将所有横坐标在[P P+A]范围内的点按照纵坐标从小到大排序
3.用一个队列Q来存储横坐标在[P P+A]范围内的点，其中第一个点为当前枚举的点P.
4.依次取出队列Q中的点，并将纵坐标在[Q.front0.y, Qfront0.y+B]范围内的点加入队列Q中。

统计队列Q的大小，即为以点P为左端点，最大横坐标为P+A的矩形中点的数量.枚举所有点作为左端点，重复上述步骤，取最大值即为所求
*/
int zhandou(int N, int X, int Y, vector<vector<int>> dots){
    //首排序 X Y
    sort(dots.begin(),dots.end(),[&](const vector<int>& a, const vector<int>& b){
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    int count = 0;
    for (int i = 0; i < dots.size(); i++)
    {
        int X_shift = 0;
        int begin_index = i + 1;
        set<vector<int>> temp;
        temp.insert(dots[i]);
        while (true)
        {
            if ((dots[begin_index][0] - dots[i][0]) >= X) break;
            temp.insert(dots[begin_index]);
            begin_index++;
        }
        for(set<vector<int>>::iterator iter=temp.begin();iter!=temp.end();i++){
            if (((*iter)[1] - dots[i][1]) > Y) {
                temp.erase((*iter));
            }
        }
        if (count < temp.size())
        {
            count = temp.size();
        }
    }
    
    return count;
}
int main() {

    vector<vector<int>> prices = {
        {1, 1},
    {2, 2},
{3, 3},
{1, 3},
{1, 4}
    };
    int c = zhandou(5,1,2,prices);
    cout << c ;
    return 0;
}