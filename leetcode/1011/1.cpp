#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int M, N, X;
    cin >> M >> N;
    cin >> X;

    vector<int> requests(X);
    for (int i = 0; i < X; ++i) {
        cin >> requests[i];
    }

    int minControl = 0;  // 记录最小流控数量
    int windowSum = 0;  // 滑动窗口的请求总数
    queue<int> window;  // 使用队列存储滑动窗口内每分钟的请求

    for (int i = 0; i < X; ++i) {
        windowSum += requests[i];  // 将新的请求加到滑动窗口的总数上
        window.push(requests[i]);  // 将新的请求加入到滑动窗口

        // 如果滑动窗口的大小超过了M分钟，更新窗口
        if (window.size() > M) {
            windowSum -= window.front();  // 去掉窗口最早加入的请求
            window.pop();  // 移除窗口最早加入的请求
        }

        // 检查是否需要流控
        if (windowSum > N) {
            minControl += (windowSum - N);  // 更新最小流控数量
            windowSum = N;  // 将窗口总数更新为N，因为我们已经进行了流控
        }
    }

    cout << minControl << endl;  // 输出最小流控数量

    return 0;
}
