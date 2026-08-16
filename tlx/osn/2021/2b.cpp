#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int par[N], sum[N];

int getroot(int u){
    if(par[u] == u) return u;
    return par[u] = getroot(par[u]);
}

bool cek(int a, int b){
    return getroot(a) == getroot(b);
}

void join(int u, int v){
    if(cek(u, v)) return;
    int ru = getroot(u);
    int rv = getroot(v);
    sum[ru] += sum[rv];
    par[rv] = ru;
}

signed main(){
    int n;
    cin >> n;
    vector<int> a(n), don(33, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> sum[i];
    }
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
    vector<int> msb(n);
    vector<bool> onbit(33, 0);
    for(int i = 0; i < n; i++){
        // int x = __builtin_clz(a[i]);
        // cout << x << " ";
        for(int j = 0; j < 31; j++){
            if((a[i] & (1 << j))){
                msb[i] = j;
            }
        }
        // cout << msb[i] << " ";
        // msb[i] = x;
        onbit[msb[i]] = 1;
    }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << msb[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < msb[i]; j++){
            if(!((1 << j) & a[i]) && onbit[j]){
                if(don[j] == -1){
                    don[j] = i;
                }
                else join(don[j], i);
            }
        }
    }
    // int ans = 0;
    for(int i = 0; i < n; i++){
        if(don[msb[i]] != -1){
            join(don[msb[i]], i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << sum[getroot(i)] << endl;
    }
}