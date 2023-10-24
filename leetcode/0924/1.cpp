#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minimumDeletionsToGoodString(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    int deletions = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            deletions++;
        }
    }
    if ((s.size() - deletions) % 2 != 0) {
        deletions++;
    }
    return deletions;
}

int main() {
    string s;
    cin >> s;
    cout << minimumDeletionsToGoodString(s) << endl;
    return 0;
}