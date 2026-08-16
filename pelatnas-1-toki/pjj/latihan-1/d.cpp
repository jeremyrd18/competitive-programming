#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.rbegin(), a.rend());
    int mxb = a[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(a[i].second > mxb){
            mxb = a[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}