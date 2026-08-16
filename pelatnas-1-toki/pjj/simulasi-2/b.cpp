#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>

const int MOD = 1000000007;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int l = 0, r = 0;
    while(r < n && l < n){
        if(l > r){
            r++;
            continue;
        }
        if(l == r){
            ans = max(ans, 1LL);
            r++;
            continue;
        }
        int mx = 1;
        int tm = 0;
        int temp = 0;
        int tmp = 0;
        int cnt = 1;
        for(int i = l + 1; i <= r; i++){
            if(a[i] == a[i - 1]) temp++;
            else{
                temp++;
                if(temp == mx){
                    cnt++;
                }
                else if(temp > mx){
                    mx = temp;
                    cnt = 1;
                }
                temp = 0;
            }
        }
        if(temp != 0){
            temp++;
            if(temp == mx){
                cnt++;
            }
            else if(temp > mx){
                mx = temp;
                cnt = 1;
            }
            temp = 0;
        }
        cout << l << " " << r << " " << cnt << endl;
        if(cnt % 2 == 1){
            temp = 0;
            int idx = 0;
            int med = cnt / 2 + 1;
            for(int i = l + 1; i <= r; i++){
                if(a[i] == a[i - 1])temp++;
                else{
                    temp++;
                    if(temp == mx){
                        idx++;
                        if(idx == med){
                            for(int j = l + 1; j <= r; j++){
                                tmp += abs(a[i - 1] - a[j]);
                            }
                            break;
                        }
                    }
                    temp = 0;
                }
            }
        }
        else{
            temp = 0;
            int idx = 0;
            int med = cnt / 2 + 1;
            for(int i = l + 1; i <= r; i++){
                if(a[i] == a[i - 1])temp++;
                else{
                    temp++;
                    if(temp == mx){
                        idx++;
                        if(idx == med){
                            for(int j = l + 1; j <= r; j++){
                                tmp += abs(a[i - 1] - a[j]);
                            }
                            break;
                        }
                    }
                    temp = 0;
                }
            }
            temp = 0;
            idx = 0;
            med = cnt / 2;
            int p = 0;
            for(int i = l + 1; i <= r; i++){
                if(a[i] == a[i - 1])temp++;
                else{
                    temp++;
                    if(temp == mx){
                        idx++;
                        if(idx == med){
                            for(int j = l + 1; j <= r; j++){
                                p += abs(a[i - 1] - a[j]);
                            }
                            tmp = min(tmp, p);
                            break;
                        }
                    }
                    temp = 0;
                }
            }
        }
        cout << "harga " << tmp << endl;
        if(tmp > k){
            l++;
        }
        else{
            ans = max(ans, r - l + 1);
            r++;
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}