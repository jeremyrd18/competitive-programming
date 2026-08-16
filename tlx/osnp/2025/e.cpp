#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    vector<int> dp(n, -1);
    int L = 0;
    deque<pair<int, int> > pos_dp; // dp, index

    for(int i = 0; i < n; i++){
        while(a[i] - a[L] > k){
            L++;
        }
        int X = i - m;
        if(X >= -1){    
            int val = (X == -1)? 0 : dp[X];
            if(val != -1){
                while(!pos_dp.empty() && pos_dp.back().first <= dp[X]){
                    pos_dp.pop_back();
                }
                pos_dp.push_back({val, X});
            }
        }

        while(!pos_dp.empty() && pos_dp.front().second < L - 1){
            pos_dp.pop_front();
        }

        if(!pos_dp.empty()){
            dp[i] = 1 + pos_dp.front().first;
        }
    }
    cout << dp[n - 1] << endl;
}

/*
Firstly, sort A in ascending order
Next, let dp[i] be the maximum ikat bambu with bamboes 1 to i
we have dp[i] = 1 + max(dp[j]) where j are all the possible reach for i
Notice if j is possible, we have a[i] - a[j] < = k (we can only cut a[i] at max k)

My approach
- L is a left-pointer tahat keeps track on the rightest L such that A[i] - a[left] <= K
- X = i - m, is the rightest dp index that can be chosen.
- We iterate j from L to I to find which dp is the best, but using sliding window, where:
    - use deque to store possible dp's from L to i in a descending order
    - pop_back when dp[X] is bigger than the back (while loop)
    - pop_front when front is at index below L (while loop)
*/