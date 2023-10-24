#include <iostream>
#include <unordered_map>
#include <string>

std::string cleanString(const std::string &s) {
    std::string result;
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int minValueAfterKChanges(const std::string &s, int k, std::unordered_map<std::string, int> &memo) {
    if (k == 0) {
        return cleanString(s).length();
    }
    if (s.empty() || s.size() <= 1) {
        return s.length();
    }

    // If (s, k) is already computed, return it
    if (memo.find(s) != memo.end()) {
        return memo[s];
    }

    int min_val = s.length();

    for (int i = 0; i < s.length(); ++i) {
        std::string changed = s;
        changed[i] = (s[i] == '0' ? '1' : '0');
        min_val = std::min(min_val, minValueAfterKChanges(changed, k - 1, memo));
    }

    memo[s] = min_val;
    return min_val;
}

int main() {
    std::string input = "00";
    int k = 1;
    std::unordered_map<std::string, int> memo;
    std::cout << "Minimum value after " << k << " changes: " << minValueAfterKChanges(input, k, memo) << std::endl;
    return 0;
}
