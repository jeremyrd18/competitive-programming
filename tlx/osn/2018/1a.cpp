#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

const int mod = 1000000007;
int memo[100005];

int fac(int x){
    if(x == 0 || x == 1) return 1;
    if(memo[x] != -1){
        return memo[x];
    }
    return memo[x] = x * fac(x - 1);
}

signed main(){
    memset(memo, -1, sizeof memo);
    string dummy; cin >> dummy;
    int n, k;
    cin >> n >> k;
    vector<int> bridge(k);
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        bridge[i] = x;
    }
    vector<int> old[k];
    vector<int> neww[k];
    for(int i = 1; i <= n; i++){
        int x; cin >> x; x--;
        old[x].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x; x--;
        neww[x].push_back(i);
    }
    int ans = 1;
    bool noans = 0;
    for(int i = 0; i < k; i++){
        int sz = old[i].size();
        int adalama = 0, adabaru = 0;
        int ataslama = 0, atasbaru = 0, bawahlama = 0, bawahbaru = 0;
        for(int j = 0; j < sz; j++){
            if(old[i][j] == bridge[i]){
                adalama = 1;
            }
            else if(old[i][j] < bridge[i]){
                bawahlama++;
            }
            else ataslama++;
        }
        for(int j = 0; j < sz; j++){
            if(neww[i][j] == bridge[i]){
                adabaru = 1;
            } 
            else if(neww[i][j] < bridge[i]){
                bawahbaru++;
            }
            else atasbaru++;
        }
        if(bawahlama == atasbaru && ataslama == bawahbaru){
            if(adalama == 0){
                ans *= fac(ataslama) * fac(atasbaru);
                ans %= mod;
            }
            else{
                int case1 = fac(ataslama) * fac(atasbaru); case1 %= mod;
                int case2 = (fac(ataslama) * fac(atasbaru + 1)) - case1; case2 %= mod;
                int case3 = (fac(ataslama + 1) * fac(atasbaru)) - case1; case3 %= mod;
                ans *= (case1 + case2 + case3);
                ans %= mod;
            }
        }
        else if(bawahlama + adalama == atasbaru && ataslama == bawahbaru + adabaru){
            if(adalama == 1 && adabaru == 1){
                ans *= fac(atasbaru) * fac(bawahbaru + 1);
                ans %= mod;
            }
            else if(adalama == 1 && adabaru == 0){
                ans *= fac(atasbaru) * fac(bawahbaru);
                ans %= mod;
            }
            else if(adalama == 0 && adabaru == 1){
                ans *= fac(atasbaru) * fac(bawahbaru + 1);
                ans %= mod;
            }
        }
        else if(bawahlama == atasbaru + adabaru || ataslama + adalama == bawahbaru){
            if(adalama == 1 && adabaru == 1){
                ans *= fac(atasbaru + 1) * fac(bawahbaru);
                ans %= mod;
            }
            else if(adalama == 1 && adabaru == 0){
                ans *= fac(atasbaru) * fac(bawahbaru);
                ans %= mod;
            }
            else if(adalama == 0 && adabaru == 1){
                ans *= fac(atasbaru + 1) * fac(bawahbaru);
                ans %= mod;
            }
        }
        else noans = 1;
    }
    if(!noans){
        cout << (ans + 2 * mod ) % mod << endl;
    }
    else cout << 0 << endl;
}