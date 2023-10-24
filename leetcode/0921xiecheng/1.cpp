#include <iostream>
#include <vector>
#include <set>

std::vector<int> construct_b(const std::vector<int>& a) {
    int n = a.size();
    std::set<int> candidates;
    for (int i = 1; i <= n; ++i) {
        candidates.insert(i);
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        if (*candidates.begin() != a[i]) {
            b[i] = *candidates.begin();
            candidates.erase(candidates.begin());
        } else {
            auto it = candidates.upper_bound(a[i]); 
            if (it == candidates.end()) {
                it = candidates.begin();
            }
            b[i] = *it;
            candidates.erase(it);
        }
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b = construct_b(a);
    for (int bi : b) {
        std::cout << bi << " ";
    }
    std::cout << std::endl;

    return 0;
}
