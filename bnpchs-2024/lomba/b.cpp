#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N;
    cin >> N;  
    vector<int> A(N);  
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int tots = 0;
    for (int i = 0; i < N; ++i) {
        tots += A[i];
    }
    int mxs = tots;
    int les = 0;
    for (int i = 0; i < N; ++i) {
        int ss = les * A[i] + (tots - les - A[i]);
        mxs = max(mxs, ss);
        les += A[i];
    }
    cout << mxs << endl;
}
