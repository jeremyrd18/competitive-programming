#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_A = 300000;  // Maximum value of Ai

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> freq(MAX_A + 1, 0);  // Frequency array for values up to MAX_A
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    vector<int> prefix(MAX_A + 1, 0);
    for (int i = 1; i <= MAX_A; i++) {
        prefix[i] = prefix[i - 1] + freq[i];
    }

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int Ai = a[i];
        for (int j = Ai; j <= MAX_A; j += Ai) {
            int left = j, right = min(j + Ai - 1, MAX_A);
            int count = prefix[right] - prefix[left - 1];
            dp[i + 1] += count * (j % Ai);
        }
        dp[i + 1] += dp[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
