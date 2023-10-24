#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

std::string minWindow(std::string s, std::string t) {
    if(s.empty() || t.empty()) {
        return "";
    }

    // 初始化哈希表
    std::unordered_map<char, int> dict_t, window_counts;
    for(char c : t) {
        dict_t[c]++;
    }

    int left = 0, right = 0, min_len = INT_MAX, start_idx = 0, matched_chars = 0;
    while(right < s.size()) {
        char c = s[right];
        if(dict_t.find(c) != dict_t.end()) {
            window_counts[c]++;
            if(window_counts[c] == dict_t[c]) {
                matched_chars++;
            }
        }

        while(matched_chars == dict_t.size() && left <= right) {
            char ch = s[left];
            if(right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }

            if(dict_t.find(ch) != dict_t.end()) {
                window_counts[ch]--;
                if(window_counts[ch] < dict_t[ch]) {
                    matched_chars--;
                }
            }
            left++;
        }

        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
}

int main() {
    std::string A = "DKAFWADCBEILBCEA", B = "BCA";
    std::cout << minWindow(A, B) << std::endl;  // Expected: "BANC"
    return 0;
}
