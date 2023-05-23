#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
有一份由 n 个问题组成的调查问卷，每个问题的答案要么是 0（no，否），要么是 1（yes，是）。

这份调查问卷被分发给 m 名学生和 m 名导师，学生和导师的编号都是从 0 到 m - 1 。
学生的答案用一个二维整数数组 students 表示，其中 students[i] 是一个整数数组，
包含第 i 名学生对调查问卷给出的答案（下标从 0 开始）。导师的答案用一个二维整数数组 mentors 表示，
其中 mentors[j] 是一个整数数组，包含第 j 名导师对调查问卷给出的答案（下标从 0 开始）。

每个学生都会被分配给 一名 导师，而每位导师也会分配到 一名 学生。配对的学生与导师之间的兼容性评分等于学生和导师答案相同的次数。

例如，学生答案为[1, 0, 1] 而导师答案为 [0, 0, 1] ，那么他们的兼容性评分为 2 ，因为只有第二个和第三个答案相同。
请你找出最优的学生与导师的配对方案，以 最大程度上 提高 兼容性评分和 。

给你 students 和 mentors ，返回可以得到的 最大兼容性评分和 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-compatibility-score-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
思路：
*/
int check(vector<int> &a, vector<int> &b)
{
    int s = 0;
    for (size_t i = 0; i < a.size() && i < b.size(); i++)
    {
        if (a[i] == b[i])
        {
            s++;
        }
    }
    return s;
}
/*
从一个未匹配点开始，依次遍历所有能够与它相连的未匹配点，如果当前的未匹配点还没有被匹配，
则将它们匹配起来，并继续向下寻找可以匹配的点。如果当前的未匹配点已经被匹配了，那么我们就需要判断当前的匹配是否可以被替换为一个更优的匹配。
*/

int myDfs(vector<vector<int>> &allscore, int row, int clum, int temp);
int ans = 0;
bool vis[8]; // 老师的访问情况
int m, n;
int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
{
    m = students.size();
    n = mentors.size();
    vector<vector<int>> allscore(m, vector<int>(n, 0));
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            allscore[i][j] = check(students[i], mentors[j]);
        }
    }
    for (size_t i = 0; i < m; i++)
    {
        vis[i] = true;            // 选择当前老师
        myDfs(allscore, 0, i, 0); // 进入下一层搜索
        vis[i] = false;
    }

    return ans;
}
int myDfs(vector<vector<int>> &allscore, int row, int clum, int temp)
{
    temp += allscore[row][clum];
    // match 为匹配情况i和j匹配 即match[i] = j,没有匹配为match[i]=-1，vis为访问情况
    if (row == allscore.size() - 1)
    { // 最后一个学生
        ans = ans > temp ? ans : temp;
        return ans;
    }

    for (size_t i = 0; i < n; i++)
    {
        if (!vis[i]) // 遍历未选择的老师
        {
            vis[i] = true;                     // 选择当前老师
            myDfs(allscore, row + 1, i, temp); // 进入下一层搜索
            vis[i] = false;                    //
        }
    }
    return 0;
}
int main()
{

    // vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> a = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> b = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    // vector<int> nums = {0,0,0,0};
    auto sss = maxCompatibilitySum(a, b);

    return 0;
}