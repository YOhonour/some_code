#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int minimumDistance(vector<int>& a, vector<int>& b) {
    int positiveSum = 0;
    int negativeSum = 0;
    
    for (int i = 0; i < a.size(); i++) {
        int diff = a[i] - b[i];
        if (diff > 0) positiveSum += diff;
        else negativeSum += diff;
    }
    
    while (positiveSum != 0 && negativeSum != 0) {
        if (abs(positiveSum) > abs(negativeSum)) {
            positiveSum -= a.size();
        } else {
            negativeSum += a.size();
        }
    }

    return abs(positiveSum) + abs(negativeSum);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    cout << minimumDistance(a, b) << endl;

    return 0;
}
