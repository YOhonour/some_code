#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int MOD = (int)10e9 + 7;
    int n;
    cin >> n;
    vector<int> vals(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    
    long long sum1 = vals[0], sum2 = vals[vals.size() - 1];
    int l = 1, r = vals.size() - 2;
    int MIN = INT32_MAX;
    int t = INT32_MAX;
    int res_l = l,res_r = r;
    while (l < r)
    {
        if (sum1 + vals[l] < sum2)
        {
            sum1 += vals[l];
            l++;
        }
        else if(sum2 + vals[r] < sum1)
        {
            sum2 += vals[r];
            r--;
        }
        t = abs(sum1-sum2);
        if (MIN > t)
        {
            MIN = t;
            res_l = l;
            res_r = r;
        }
        // else if(MIN == t){
        //     if(){

        //     }
        // }
    }
    cout << MIN << ' ' << res_l << ' ' << res_r << endl;
    return 0;
}