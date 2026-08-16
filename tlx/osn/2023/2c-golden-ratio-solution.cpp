#include <bits/stdc++.h>
using namespace std;
#define int long long


// find best divide index
// use golden ratio (from time complexity, logarithms) :(
// x^2 - 3x + 1 = 0, (double) x = (3 - sqrt(5)) / 2

const double gr = (3 - sqrt(5)) / 2;

signed main(){
    int n, t; cin >> n >> t;
    int l = 1, r = n, mid, bef;
    string s;
    // mid kalo binser -> L + (R - L)*(1 / 2) -> 1/2 karna belah tengah
    bef = l + (r - l) * gr;
    cout << bef << endl;
    while(l <= r){
        mid = (bef + 1) + (r - (bef + 1)) * gr;
        cout << mid << endl;
        cin >> s;
        if(s == "KEBESARAN"){
            r = bef - 1;
            mid = l + (r - l) * gr;
            cout << mid << endl;
            cin >> s;
            bef = mid;
        }
        else if(s == "KEKECILAN"){
            l = bef + 1;
            bef = mid;
        }
        else{
            break;
        }
    }
}