// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     long long n, m;
//     cin >> n >> m;

//     vector<long long> A(1e5 + 1, 0);  // 初始化序列 A，使用 1e5+1 大小的数组
//     vector<long long> prefixXOR(1e5 + 1, 0);  // 初始化前缀异或数组

//     // 进行 n 次修改
//     for (int i = 0; i < n; ++i) {
//         long long l, r, x;
//         cin >> l >> r >> x;
//         A[l] ^= x;
//         A[r + 1] ^= x;  // 取消 x 的影响
//     }

//     // 计算前缀异或数组
//     for (int i = 1; i < A.size(); ++i) {
//         prefixXOR[i] = prefixXOR[i - 1] ^ A[i];
//     }

//     // 进行 m 次查询
//     for (int i = 0; i < m; ++i) {
//         long long p;
//         cin >> p;
//         cout << prefixXOR[p] << endl;
//     }

//     return 0;
// }
/*
2 2
1 5 1
3 7 2
4
6
*/

#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int left;
    int right;
    long long xorValue;
};

vector<SegmentTreeNode> segmentTree(4 * 1e5 + 1);  // 初始化线段树

void buildTree(int node, int left, int right) {
    segmentTree[node].left = left;
    segmentTree[node].right = right;
    segmentTree[node].xorValue = 0;

    if (left != right) {
        int mid = (left + right) / 2;
        buildTree(2 * node, left, mid);
        buildTree(2 * node + 1, mid + 1, right);
    }
}

void updateTree(int node, int left, int right, long long x) {
    if (left <= segmentTree[node].left && segmentTree[node].right <= right) {
        segmentTree[node].xorValue ^= x;
        return;
    }

    int mid = (segmentTree[node].left + segmentTree[node].right) / 2;

    if (left <= mid) {
        updateTree(2 * node, left, right, x);
    }
    if (right > mid) {
        updateTree(2 * node + 1, left, right, x);
    }
}

long long queryTree(int node, int p) {
    if (segmentTree[node].left == p && segmentTree[node].right == p) {
        return segmentTree[node].xorValue;
    }

    int mid = (segmentTree[node].left + segmentTree[node].right) / 2;

    if (p <= mid) {
        return segmentTree[node].xorValue ^ queryTree(2 * node, p);
    } else {
        return segmentTree[node].xorValue ^ queryTree(2 * node + 1, p);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    buildTree(1, 0, 1e5);

    for (int i = 0; i < n; ++i) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        updateTree(1, l, r, x);
    }

    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        cout << queryTree(1, p) << endl;
    }

    return 0;
}
