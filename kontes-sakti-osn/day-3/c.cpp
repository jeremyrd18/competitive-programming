#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t, n, m;
    cin>>t;
    while(t--){
        int n, m, k, x, y;
        cin>>n>>m>>k;
        int quer[k];
        vector<vector<int>> ve, us;
        for (int i = 0; i < k; i++){
            cin>>y>>x;
            ve.push_back({-y, x, i});
        }
        sort(ve.begin(), ve.end());
        int mi = m + 1;
        for (auto el : ve){
            if (el[1] < mi){
                quer[el[2]] = 1;
                us.push_back({el[1], -el[0]});
            }
            else{
                quer[el[2]] = 0;
            }
            mi = min(mi, el[1]);
        }
        us.push_back({m + 1, n});
        sort(us.begin(), us.end());
        int ans = 0, ny = 1, nx = 0;
        for (int i = 0; i < us.size(); i++){
            ans += (us[i][1] - ny + 1) * (us[i][0] - 1);
            ny = us[i][1] + 1;
        }
        cout<< ans << endl;
        for (int i = 0; i < k; i++){
            cout<<quer[i]<<" ";
        }
        // cout << ans << endl;
        cout << endl;
    }
}