#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void cek(string s, string possible){
    int idxpos = 0;
    int strlen = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == possible[idxpos]){
            strlen++;
            idxpos++;
            idxpos %= 3;
        }
    }
    ans = max(ans, strlen);
}

int main(){
    string s;
    cin >> s;
    cek(s, "OSN");
    cek(s, "ONS");
    cek(s, "NOS");
    cek(s, "NSO");
    cek(s, "SNO");
    cek(s, "SON");

    if(ans < 3){
        cout << -1;
    }
    else cout << ans;
}