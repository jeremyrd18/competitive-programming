#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans; cin >> ans;
    for(int i = 1; i <= 6; i++){
        int x;
        cin >> x;
        ans += abs(x);
    }
    cout << ans << endl;
}