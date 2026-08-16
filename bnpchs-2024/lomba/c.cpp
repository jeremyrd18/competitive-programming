#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> cnt[11];

int cek(int num, int bas){
    int ans = 0;
    for(int i = 1; i <= 10; i++){
        if(num >= bas * i){
            ans = i;
        }
    }
    return ans;
}

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.rbegin(), a.rend());
    int div = 10000000000;
    int lsx = 9;
    int i = 0;
    while(div > 0 && i < n){
        int lsxx = lsx;
        int tmp = a[i] % div;
        if(tmp >= div / 10){
            int divt = div;
            while(divt > 0 && lsxx >= 0){
                int tmpx = a[i] % divt;
                int lsd = cek(tmpx, divt/10);
                cnt[lsxx].push_back(lsd);
                lsxx--;
                divt /= 10;
            }
            i++;
        }
        else{
            div /= 10;
            lsx--;
        }
    }
    // for(int i = 0; i <= 10; i++){
    //     cout << "num " << i << endl;
    //     for(auto v : cnt[i]){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    int idx = 10;
    int diver = 10000000000;
    while(k > 0 && idx >= 0 && diver > 0){
        for(auto v : cnt[idx]){
            if(k <= 0) break;
            if(k > 9 - v){
                ans += (9 - v) * diver;
                k -= (9 - v);
            }
            else{
                ans += k * diver;
                k = 0;
            }
        }
        idx--;
        diver /= 10;
    }
    if(k % 10 == 0){
        cout << ans + sum << endl;
    }
    else{
        cout << ans + sum - 10 + (k % 10) << endl;
    }
}