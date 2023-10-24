#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int oddSequenceCount(int num) {
    int start = 1, end = 1, sum = 1, count = 0;
    while (end <= num / 2 + 1) {  // end不会超过num的一半再加1
        if (sum < num) {
            // 扩大窗口
            end += 2;
            sum += end;
        } else if (sum > num) {
            // 缩小窗口
            sum -= start;
            start += 2;
        } else {
            count++;
            // 移动start指针来寻找下一个可能的奇数序列
            sum -= start;
            start += 2;
        }
    }
    return count;
}

int main() {
    int num;
    cin >> num;
    cout << oddSequenceCount(num) << endl;  // 输出：1
    return 0;
}