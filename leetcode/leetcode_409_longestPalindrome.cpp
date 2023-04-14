#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int longestPalindrome(string s)
{
    unordered_map<char,int> map;
    for (int i = 0; i < s.length(); i++)
    {
        if (map.find(s.at(i)) == map.end()){
            map.insert({s.at(i),1});
        }else{
            map[s.at(i)] = map.at(s.at(i))+1;
        }
    }
    int equl = 0;
    int max_old = 0;
    for (auto i = map.begin(); i != map.end(); i++)
    {
        //偶数的全部放入 奇数的取最多的偶数部分
        if ((*i).second % 2 == 0)
        {
            equl += (*i).second;
        }else{
            max_old = 1;
            equl += (*i).second - 1;
        }
    }
    return equl+max_old;
}
int main()
{
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << longestPalindrome(s) << endl;
    return 0;
}