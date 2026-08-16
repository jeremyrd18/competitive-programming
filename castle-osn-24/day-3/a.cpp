#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(data, 0, 0, n - 1);
    }

    int queryMax(int left, int right) {
        return queryMax(0, 0, n - 1, left, right);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& data, int pos, int left, int right) {
        if (left == right) {
            tree[pos] = data[left];
        } else {
            int mid = (left + right) / 2;
            build(data, 2 * pos + 1, left, mid);
            build(data, 2 * pos + 2, mid + 1, right);
            tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
        }
    }

    int queryMax(int pos, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) return 0;
        if (ql <= left && qr >= right) return tree[pos];
        int mid = (left + right) / 2;
        return max(queryMax(2 * pos + 1, left, mid, ql, qr), queryMax(2 * pos + 2, mid + 1, right, ql, qr));
    }
};

long long solve(const vector<int>& A, int left, int right, SegmentTree& segTree, vector<int>& prefixXOR) {
    if (left > right) return 0;
    if (left == right) {
        return (1LL * A[left] * A[left]) % MOD;
    }

    int mid = (left + right) / 2;
    long long leftResult = solve(A, left, mid, segTree, prefixXOR);
    long long rightResult = solve(A, mid + 1, right, segTree, prefixXOR);

    long long crossResult = 0;
    for (int i = mid; i >= left; --i) {
        for (int j = mid + 1; j <= right; ++j) {
            int currentXOR = prefixXOR[j + 1] ^ prefixXOR[i];
            int currentMax = segTree.queryMax(i, j);
            long long V = (1LL * currentXOR * currentMax) % MOD;
            crossResult = (crossResult + V) % MOD;
        }
    }

    return (leftResult + rightResult + crossResult) % MOD;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> prefixXOR(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefixXOR[i] = prefixXOR[i - 1] ^ A[i - 1];
    }

    SegmentTree segTree(A);
    long long result = solve(A, 0, N - 1, segTree, prefixXOR);
    cout << result << endl;

    return 0;
}
