#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    a *= 5000;
    b *= 10000;
    c *= 19000;
    int g1 = 11520, g2 = 7920, g3 = 14400, g4 = 18000;
    bool udaha = 0, udahb = 0, udahc = 0, barua = 0, barub = 0;
    map<int, int> mp;
    int lastsisa = 0;
    if(c != 0){
        while(true){
            if(udaha == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(abs(a - g1) <= dipake1){
                    dipake1 = abs(a - g1);
                    dipake = a - g1;
                }
                if(abs(a - g2) <= dipake1){
                    dipake1 = abs(a - g2);
                    dipake = a - g2;
                }
                if(abs(a - g3) <= dipake1){
                    dipake1 = abs(a - g3);
                    dipake = a - g3;
                }
                if(abs(a - g4) <= dipake1){
                    dipake1 = abs(a - g4);
                    dipake = a - g4;
                }
                mp[a - dipake]++;
                if(dipake <= 0){
                    // cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    udaha = 1;
                    int sisa = abs(dipake - 0);
                    b -= sisa;
                    barua = 1;
                }
                a = dipake;
            }
            else if(udahb == 0){
                if(b <= 0 && barua == 1){
                    udahb = 1;
                    int sisa = abs(b - 0);
                    c -= sisa;
                }
                barua = 0;
                int dipake = 100000000, dipake1 = 100000000;
                if(abs(b - g1) <= dipake1){
                    dipake1 = abs(b - g1);
                    dipake = b - g1;
                }
                if(abs(b - g2) <= dipake1){
                    dipake1 = abs(b - g2);
                    dipake = b - g2;
                }
                if(abs(b - g3) <= dipake1){
                    dipake1 = abs(b - g3);
                    dipake = b - g3;
                }
                if(abs(b - g4) <= dipake1){
                    dipake1 = abs(b - g4);
                    dipake = b - g4;
                }
                mp[b - dipake]++;
                if(dipake <= 0){
                    // cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    udahb = 1;
                    int sisa = abs(dipake - 0);
                    c -= sisa;
                    barub = 1;
                }
                b = dipake;
            }
            else if(udahc == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(c - g1 <= dipake1 && c - g1 >= 0){
                    dipake1 = abs(c - g1);
                    dipake = c - g1;
                }
                if(c - g2 <= dipake1 && c - g2 >= 0){
                    dipake1 = abs(c - g2);
                    dipake = c - g2;
                }
                if(c - g3 <= dipake1 && c - g3 >= 0){
                    dipake1 = abs(c - g3);
                    dipake = c - g3;
                }
                if(c - g4 <= dipake1 && c - g4 >= 0){
                    dipake1 = abs(c - g4);
                    dipake = c - g4;
                }
                if(dipake == 100000000){
                    cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    cout << c << endl;
                    return;
                }
                // cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                mp[c - dipake]++;   
                c  = dipake;
            }
            else break;
        }
    }
    else if(c == 0 && b > 0 && a > 0){
    	c = b;
        while(true){
            
            if(udaha == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(abs(a - g1) <= dipake1){
                    dipake1 = abs(a - g1);
                    dipake = a - g1;
                }
                if(abs(a - g2) <= dipake1){
                    dipake1 = abs(a - g2);
                    dipake = a - g2;
                }
                if(abs(a - g3) <= dipake1){
                    dipake1 = abs(a - g3);
                    dipake = a - g3;
                }
                if(abs(a - g4) <= dipake1){
                    dipake1 = abs(a - g4);
                    dipake = a - g4;
                }
                mp[a - dipake]++;
                if(dipake <= 0){
                    // cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    udaha = 1;
                    int sisa = abs(dipake - 0);
                    c -= sisa;
                    barua = 1;
                }
                a = dipake;
            }
            else if(udahc == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(c - g1 <= dipake1 && c - g1 >= 0){
                    dipake1 = abs(c - g1);
                    dipake = c - g1;
                }
                if(c - g2 <= dipake1 && c - g2 >= 0){
                    dipake1 = abs(c - g2);
                    dipake = c - g2;
                }
                if(c - g3 <= dipake1 && c - g3 >= 0){
                    dipake1 = abs(c - g3);
                    dipake = c - g3;
                }
                if(c - g4 <= dipake1 && c - g4 >= 0){
                    dipake1 = abs(c - g4);
                    dipake = c - g4;
                }
                if(dipake == 100000000){
                    cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    cout << c << endl;
                    return;
                }
                // cout << c << endl;
                mp[c - dipake]++;   
                c  = dipake;
            }
            else break;
        }
    }
    else if(a > 0 && b == 0 && c == 0){
    	c = a;
        while(true){
            if(udahc == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(c - g1 <= dipake1 && c - g1 >= 0){
                    dipake1 = abs(c - g1);
                    dipake = c - g1;
                }
                if(c - g2 <= dipake1 && c - g2 >= 0){
                    dipake1 = abs(c - g2);
                    dipake = c - g2;
                }
                if(c - g3 <= dipake1 && c - g3 >= 0){
                    dipake1 = abs(c - g3);
                    dipake = c - g3;
                }
                if(c - g4 <= dipake1 && c - g4 >= 0){
                    dipake1 = abs(c - g4);
                    dipake = c - g4;
                }
                if(dipake == 100000000){
                    cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    cout << c << endl;
                    return;
                }
                mp[c - dipake]++;   
                c  = dipake;
            }
            else break;
        }
    }
    else if(a == 0 && c == 0 && b > 0){
    	c = b;
        while(true){
            
            if(udahc == 0){
                int dipake = 100000000, dipake1 = 100000000;
                if(c - g1 <= dipake1 && c - g1 >= 0){
                    dipake1 = abs(c - g1);
                    dipake = c - g1;
                }
                if(c - g2 <= dipake1 && c - g2 >= 0){
                    dipake1 = abs(c - g2);
                    dipake = c - g2;
                }
                if(c - g3 <= dipake1 && c - g3 >= 0){
                    dipake1 = abs(c - g3);
                    dipake = c - g3;
                }
                if(c - g4 <= dipake1 && c - g4 >= 0){
                    dipake1 = abs(c - g4);
                    dipake = c - g4;
                }
                if(dipake == 100000000){
                    cout << mp[11520] << " " << mp[7920] << " " << mp[14400] << " " << mp[18000] << endl;
                    cout << c << endl;
                    return;
                }
                mp[c - dipake]++;   
                c  = dipake;
            }
            else break;
        }
    }
    
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}