#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    pair<string, string> p[n];
    for(int i = 0; i < n; i++){
        string s;
        string a;
        cin >> s >> a;
        p[i] = {s, a};
    }
    sort(p, p + n);
    while(q--){
        string s;
        cin >> s;
        int l = 0, r = n - 1;
        string ans;
        while(l <= r){
            int mid = (l + r) / 2;
            string nama = p[mid].first;
            string nomor = p[mid].second;
            if(s == nama){
                ans = nomor;
                break;
            }
            else if(s > nama){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}