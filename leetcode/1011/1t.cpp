#include <iostream>
#include <vector>

using namespace std;

int minFlowControl(int M, int N, int X, vector<int>& requests) {
    int totalRequests = 0;
    int flowControlled = 0;

    for (int i = 0; i < X; i++) {
        totalRequests += requests[i];

        if (i >= M) {
            totalRequests -= requests[i - M];
        }

        if (totalRequests > N) {
            flowControlled += (totalRequests - N);
            totalRequests = N;
        }
    }

    return flowControlled;
}

int main() {
    int M, N, X;
    cin >> M >> N;
    cin >> X;

    vector<int> requests(X);
    for (int i = 0; i < X; i++) {
        cin >> requests[i];
    }

    int result = minFlowControl(M, N, X, requests);
    cout << result << endl;

    return 0;
}
