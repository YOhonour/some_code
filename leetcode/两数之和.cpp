#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
pair<int,int> towSum(int nums[], int n,int target)
{
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++)
    {
        std::unordered_map<int, int>::iterator it = map.find(target - nums[i]);
        if (it != map.end())
        {
            return {(*it).second,i};
        }else{
            map.insert({nums[i],i});
        }
    }
    auto re = make_pair<int,int>(-1,-1);
    return re;
}
int main()
{
    int nums[] = {6, -3, -2, 7, -15, 1, 2, 2};
    auto a = towSum(nums,8,-5);
    cout << a.first << ' ' << a.second ;
    return 0;
}