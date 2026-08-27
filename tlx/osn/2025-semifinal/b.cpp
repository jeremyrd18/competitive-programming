#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int h[n], p[n], v[n], pref[n + 1];
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int e = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        e += (p[i] == 0);
        v[i] = h[i] - p[i];
        pref[i + 1] = v[i] + pref[i];
    }
    
    long long ans = -1e18;
    deque<int> dq;
    for(int i = 0; i <= n; i++){
        // erasing pref that is too far away
        if(!dq.empty() && dq.front() < i - e){
            dq.pop_front();
        }

        // possible answer
        if(!dq.empty()){
            ans = max(ans, pref[i] - pref[dq.front()]);
        }

        // better take pref[i] than the pref[j] (j < i) which is bigger, since
        // pref[i] stays longer in the deque dq
        while(!dq.empty() && pref[dq.back()] >= pref[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << ans << endl;
}

/*
idea:
let v be an array of profit (Hi - Pi) for lending the ruko
we want to find the maximum subarray sum of v where the length is maximum E (banyak ruko kosong)
we will use monotonic dequeue & prefix sum
we cannot use kadane since the length of array has a max of E
*/