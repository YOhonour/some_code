#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canTransform(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, char> transform;

    for (int i = 0; i < s.size(); ++i) {
        if (transform.find(s[i]) == transform.end()) {
            transform[s[i]] = t[i];
        } else {
            if (transform[s[i]] != t[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;

        if (canTransform(s, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}