#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> count(4, 0);
    int unique_chars = 0;
    int min_len = n + 1;
    
    int left = 0;
    for (int r = 0; r < n; r++) {
        int val = s[r] - '0';
        if (count[val] == 0) {
            unique_chars++;
        }
        count[val]++;
        
        while (unique_chars == 3) {
            min_len = min(min_len, r - left + 1);
            int left_val = s[left] - '0';
            count[left_val]--;
            if (count[left_val] == 0) {
                unique_chars--;
            }
            left++;
        }
    }
    
    if (min_len > n) {
        cout << 0 << "\n";
    } else {
        cout << min_len << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}