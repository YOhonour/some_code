#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int, int> get_pair(int i, int j)
    {
        if (i > j)
            return pair<int, int>(j, i);
        else
            return pair<int, int>(i, j);
    };
int main()
{
    
    int n;
    set<pair<int, int>> set;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; i < n; j++)
        {
            pair<int, int> insert_num = get_pair(nums[i], nums[j]);
            set.insert(insert_num);
        }
    }
    cout << set.size();
};