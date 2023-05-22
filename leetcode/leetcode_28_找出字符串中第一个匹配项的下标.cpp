#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
int strStr(string haystack, string needle)
{
    if (needle.size() > haystack.size())
    {
        return -1;
    }
    bool f = false;
    for (int i = 0; i < haystack.size(); i++)
    {
        int off = 0;
        if (haystack[i] == needle[0])
        {
            f = true;
            for (int j = 1; j < needle.size(); j++)
            {
                if (i + j >= haystack.size())
                {
                    return -1;
                }
                else if (needle[j] != haystack[i + j])
                {
                    f = false;
                    break;
                }
            }
        }
        if (f == true)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string s1 = "sadbutsad";
    string s2 = "sad";
    cout << strStr(s1,s2) << endl;
}