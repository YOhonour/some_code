#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
有 n 个点，第i个点的坐标为 Xi，第i个点的颜色为 Ci如果Ci=0，则第i个点为红点
如果Ci= 1，则第i个点为蓝点
每次你可以做以下两种操作之一:
A.选择一个0，设这个0的坐标为 x，把这个点移动到x-1或x+1
B.选择一个1，将它变为0。
你可以最多做 k 次操作B。求最少要进行多少次操作A可以使得任意两个0之间不存在1。即设两个红点分别在坐标x,y(x <= y)，则不存在任何一个蓝点的坐标在区间[x,y]内。
*/
struct Point
{
    int x;
    int color;
};

int minOperations(vector<Point> &points, int k)
{
    sort(points.begin(), points.end(), [](const Point &a, const Point &b)
         { return a.x < b.x; });
    int n = points.size();
    vector<int> red_opts;
    int left = 0;
    int right = n - 1;
    // while (points[left].color == 1) left++;
    while (points[right].color == 1)
        right--;

    for (int i = 0; i < right; i++)
    {
        if (points[i].color == 1)
        {
            int left_count = points[i].x - points[left].x + 1;
            int right_count = points[right].x - points[i].x + 1;
            if (left_count < right_count)
            {
                left++;
                red_opts.push_back(left_count);
            }
            else
            {
                right--;
                red_opts.push_back(right_count);
            }
        }
    }
    sort(red_opts.begin(), red_opts.end());
    int res = 0;
    for (int i = 0; i < red_opts.size() - k; i++)
    {
        res += red_opts[i];
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<Point> points(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].color;
    }
    cout << minOperations(points, k) << endl;
    return 0;
}
/*
5 1
2 7 9 14 20
0 1 0 0 1
8 0
1 2 3 4 5 6 7 8
0 1 1 1 1 1 1 0
*/
