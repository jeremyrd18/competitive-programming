#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> t;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int udah = 0;
        int waktu = 0;
        int idx = 0;
        while(true){
            if(waktu > t){
                ans--;
                break;
            }
            if(idx == 0 && udah == 1){
                waktu += c[i];
            }
            idx++;
            ans++;
            waktu += a[i];
            if(idx % b[i] == 0){
                udah = 1;
                idx = 0;
            }
            else{
            }
        }
    }
    cout << ans << endl;
}