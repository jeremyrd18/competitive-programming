#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve() {
    int n, m, i;
    cin >> n >> m;
    
    // Input string s
    string s;
    cin >> s;
    
    // Ensure the size of the string matches the expected length n
    if (s.size() != n) {
        cerr << "Input string length does not match n" << endl;
        return;
    }

    // Input the indices
    vector<int> num(m);
    map<int, int> cnt;
    for (i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;  // Convert to 0-based index
        num[i] = x;
        cnt[x]++;
    }

    // Input the replacement characters
    vector<char> a(m);
    for (i = 0; i < m; i++) {
        cin >> a[i];
    }

    // Sort the replacement characters
    sort(a.begin(), a.end());
    
    // Sort the indices
    sort(num.begin(), num.end());

    // Use a deque to facilitate the replacement process
    deque<char> aa(a.begin(), a.end());

    i = 0;
    while (i < m) {
        s[num[i]] = aa.front();  // Replace the character at the specified index
        aa.pop_front();  // Remove the used character from the deque
        for (int v = 1; v < cnt[num[i]]; v++) {
            aa.pop_back();  // Remove additional characters from the end of the deque
        }
        i += cnt[num[i]];  // Move to the next distinct index
    }

    // Output the modified string
    cout << s << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
