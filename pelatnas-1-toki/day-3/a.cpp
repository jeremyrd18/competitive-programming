#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void updateRange(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;
        
        if (start == end) {
            tree[node] += val;
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int idx) {
        if (start == end) return tree[node];
        
        int mid = (start + end) / 2;
        if (idx <= mid)
            return tree[node] + query(2 * node, start, mid, idx);
        else
            return tree[node] + query(2 * node + 1, mid + 1, end, idx);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * size, 0);
    }

    void update(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    int getValue(int idx) {
        return query(1, 0, n - 1, idx);
    }
};

int longestTepatDuaSubarray(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> lastSeen;
    SegmentTree segTree(n);
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        int elem = arr[right];
        
        if (lastSeen.count(elem)) {
            int lastIdx = lastSeen[elem];
            segTree.update(lastIdx + 1, right, 1);
        }
        
        lastSeen[elem] = right;

        while (segTree.getValue(left) > 0) {
            left++;
        }

        if (right - left + 1 > maxLength) {
            bool isTepatDua = true;
            for (auto& [key, count] : lastSeen) {
                int occurrences = 0;
                for (int i = left; i <= right; ++i) {
                    if (arr[i] == key) occurrences++;
                }
                if (occurrences != 2) {
                    isTepatDua = false;
                    break;
                }
            }
            if (isTepatDua) maxLength = right - left + 1;
        }
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = longestTepatDuaSubarray(arr);
    cout << result << endl;
    return 0;
}
