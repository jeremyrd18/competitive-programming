//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    string s;
    cin >> s;
    string r = "";
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'L') continue;
        if(s[i] == 'W'){
            r += 'W';
        }
        else{
            r += 'D';
        }
    }
    string ril = "";
    for(int i = 0; i < r.length(); i++){
        if(r[i] == 'W'){
            if(i + 1 >= r.length()){
                ril += 'W';
            }
            else if(r[i + 1] == 'D'){
                int j = i;
                int lamp = 0;
                string temp = "W";
                string jaga = "";
                while(true){
                    if(j + 1 >= r.length()) break;
                    if(lamp == 1 && r[j + 1] == 'W'){
                        temp += 'W';
                        lamp = 0;
                    }
                    else if(lamp == 0 && r[j + 1] == 'D'){
                        lamp = 1;
                        temp += 'D';
                    }
                    else if(lamp == 0){
                        for(int k = 0; k < temp.length(); k++){
                            if(temp[k] == 'W'){
                                jaga += 'W';
                            }
                        }
                        temp = jaga;
                        break;
                    }
                    else{
                        break;
                    }
                    j++;
                }
                ril += temp;
                i = j;
            }
            else{
                ril += 'W';
            }
        }
        else ril += 'D';
    }
    // cout << ril << endl;
    int streakw = 0;
    for(int i = 0; i < ril.length(); i++){
        if(ril[i] == 'D'){
            streakw = 0;
            ans++;
        }
        else{
            ans += 2;
            streakw++;
            if(streakw >= 3){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}