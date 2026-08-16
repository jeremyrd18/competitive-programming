//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "! " << 1 << " " << 1 << endl;
        return;
    }
    vector<int> mn, mx;
    for(int i = 2; i<=n; i+=2){
        cout << "? " << i - 1 << " " << i << endl;
        string s;
        cin >> s;
        if(s == "<" || s == "="){
            mn.push_back(i - 1);
            mx.push_back(i);
        }
        else{
            mn.push_back(i);
            mx.push_back(i - 1);
        }
    }
    if(n % 2 == 1){
        mn.push_back(n);
        mx.push_back(n);
    }
    while(mn.size() != 1){
        vector<int> temp;
        for(int i = 1; i<mn.size(); i+=2){
            cout << "? " << mn[i - 1] << " " << mn[i] << endl;
            string s;
            cin >> s;
            if(s == "<" || s == "="){
                temp.push_back(mn[i - 1]);
            }
            else{
                temp.push_back(mn[i]);
            }
            
        }
        if(mn.size() % 2 == 1){
            temp.push_back(mn[mn.size() - 1]);
        }
        mn = temp;
    }
    while(mx.size() != 1){
        vector<int> temp;
        for(int i = 1; i<mx.size(); i+=2){
            cout << "? " << mx[i - 1] << " " << mx[i] << endl;
            string s;
            cin >> s;
            if(s == ">" || s == "="){
                temp.push_back(mx[i - 1]);
            }
            else{
                temp.push_back(mx[i]);
            }
        }
        if(mx.size() % 2 == 1){
            temp.push_back(mx[mx.size() - 1]);
        }
        mx = temp;
    }
    cout << "! " << mn[0] << " " << mx[0] << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}