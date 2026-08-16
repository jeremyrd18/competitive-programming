#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    int pref[n];
    int suf[n];
    
    suf[n - 1] = (s[n - 1] == 'P');
    pref[0] = (s[0] == 'O' || s[0] == 'S' || s[0] == 'N');


    bool foundO = 0, foundS = 0, foundP = 0, foundN = 0;
    int startidx = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'O'){
            foundO = 1;
        }
        if(s[i] == 'S'){
            foundS = 1;
        }
        if(s[i] == 'N'){
            foundN = 1;
        }
        if(s[i] == 'P'){
            foundP = 1;
        }
        if(foundO && foundS && foundN && foundP){
            startidx = i;
            break;
        }
    }

    if(startidx == -1){
        cout << -1;
        return 0;
    }

    for(int i = 1; i < n; i++){
        pref[i] = pref[i - 1] + (s[i] == 'O' || s[i] == 'S' || s[i] == 'N');
    }

    for(int i = n - 2; i >= 0; i--){
        suf[i] = suf[i + 1] + (s[i] == 'P');
    }

    int ans = 0;
    // cout << startidx << " " << pref[startidx] << " " << suf[startidx] << endl;
    for(int i = startidx; i < n; i++){
        int temp = pref[i] + suf[i];
        if(suf[i] == 0){
            break;
        }
        // if(s[i] == 'P'){
        //     temp--;
        // }
        ans = max(ans, temp);
    }
    if(ans < 4){
        cout << -1 << endl;
    }
    else cout << ans;

}