#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;
map<int, int> prime;
vector<int> primes;
vector<pair<int,int> > ans;
vector<pair<int, int> > que;
int use[11];
int cntp[11];

string ask(int x){
    cout << x << endl;
    string temp;
    cin >> temp;
    return temp;
}

bool benar(string s){
    if(s == "+++++"){
        return true;
    }
    return false;
}

bool cari(string s, int a){
	char x = a;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == x){
            return true;
        }
    }
    return false;
}

void aksi(){
//	cout << "e" << endl;
    vector<int> valid;
    for(int x : primes){
        string p = to_string(x);
//        cout << p[0] << endl;
        bool ril = 1;
        for(int i = 0; i < 5; i++){
//        	cout << ans[i].first << " " << p[i] << ans[i].second << endl;
            if(ans[i].first != (p[i] - '0') && ans[i].second == 1){
                ril = 0;
//                cout << ans[i].first << " " << p[i] << " " << ans[i].second << endl;
                break;
            }
        }
//        cout << ril << endl;
        if(ril){
            bool tidak = 1;
            for(auto y : que){
//            	cout << " e";
                if(!(cari(p, y.first))){
                    tidak = 0;
                    break;
                }
            }
            if(tidak){
                valid.push_back(x);
            }
        }
    }
    for(auto p : valid){
//    	cout << " e";
        string temp = ask(p);
        if(benar(temp)) break;
    }
}

void solve(){
    // 1 -> benar, 2 -> salah tempat
    que.clear();
    ans.clear();
    for(int i = 0; i < 5; i++){
        ans.push_back( {-1, 0} );
    }
    string s = ask(23581);
    string tempo = "23581";
    if(benar(s)){
        return;
    }
    memset(cntp, 0, sizeof cntp);
    memset(use, 1, sizeof use);
    for(int i = 0; i < 5; i++){
        if(s[i] == '+'){
            ans[i] = {(tempo[i] - '0'), 1};
//            cout << "deb" << endl;
//			cout << ans[i].first << endl;
        }
        else if(s[i] == '?'){
            que.push_back({s[i] - '0', i});
        }
        else{
            use[(int)s[i]] = 0;
        }
    }
    s = ask(67049);
    tempo = "67049";
    if(benar(s)){
        return;
    }
    for(int i = 0; i < 5; i++){
        if(s[i] == '+'){
            ans[i] = {tempo[i] - '0', 1};
//            cout << ans[i].first << endl;
        }
        else if(s[i] == '?'){
            que.push_back({s[i] -'0', i});
        }
        else{
            use[(int)s[i]] = 0;
        }
    }
    int temp = 0;
    for(int i = 0; i < 5; i++){
        if(ans[i].second == 1){
            temp++;
        }
    }
//    cout << temp << endl;
    if(que.size() + temp == 5){
        aksi();
        return;
    }
    
}

signed main(){
	string s;
    int a;
    cin >> s >> a;
    int t;
    cin >> t;
    for(int i = 2; i <= 100000; i++){
        if(prime[i] == 0){
            if(i >= 10000){
                primes.push_back(i);
            }
            for(int j = i + i; j <= 100000; j += i){
                prime[j] = 1;
                
            }
        }
    }
//    for(auto x : primes){
//    	cout << x << endl;
//	}
    for(int i = 1; i<=t; i++){
        solve();
    }
}
