#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    int MAXI = 1000000007;
    while(t--){
        int v, e;
        cin >> v >> e;
        vector<int> dis(v + 3, MAXI), a(e + 3), b(e + 3), c(e + 3);
        for(int i = 0; i < e; i++) cin >> a[i] >> b[i] >> c[i];
        dis[0] = 0;
        for(int i = 1; i <= v; i++){
            for(int j = 0; j < e; j++){
                int aa = a[j], bb = b[j], cc = c[j];
                if(dis[aa] != MAXI){
                    dis[bb] = min(dis[bb], dis[aa] + cc);
                }
            }
        }
        bool skibidi = 0;
        for(int j = 0; j < e; j++){
            int aa = a[j], bb = b[j], cc = c[j];
            if(dis[aa] != MAXI && dis[bb] > dis[aa] + cc){
                cout << "Pak Dengklek tidak mau pulang" << endl;
                skibidi = 1;
                break;
            }
        }
        if(skibidi) continue;
        if(dis[v - 1] == MAXI) cout << "Tidak ada jalan" << endl;
        else cout << dis[v - 1] << endl;
    }
}