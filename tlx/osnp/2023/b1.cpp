#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, m;
    cin >> n >> m;
    int a[n], sumA = 0, sumB = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sumA += a[i];
    }
    vector<int> b;
    map<int, int> freqB;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(freqB[x] == 0) b.push_back(x);
        freqB[x] += 1;
        sumB += x;
    }
    sort(b.begin(), b.end());
    if(sumA * m > sumB * n){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    int banyakKentang = 0;
    for(int i = b.size() - 1; i >= 1; i--){
        int change = b[i] * freqB[b[i]];
        sumA += change;
        sumB -= change;
        ans += change;
        banyakKentang += freqB[b[i]];
        if(sumA * (m - banyakKentang) > sumB * (n + banyakKentang)){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
