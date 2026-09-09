
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string pesan1, samaran, samaran2;
    cin >> pesan1 >> samaran >> samaran2;

    map<char, char> asli_samaran;
    map<char, char> samaran_asli;

    for(int i = 0; i < n; i++){
        char a = pesan1[i];
        char s = samaran[i];
        if(asli_samaran[a] != '\0' && asli_samaran[a] != s){
            cout << "Pak Dengklek bingung" << endl;
            return 0;
        }
        if(samaran_asli[s] != '\0' && samaran_asli[s] != a){
            cout << "Pak Dengklek bingung" << endl;
            return 0;
        }

        asli_samaran[a] = s;
        samaran_asli[s] = a;
    }

    string ans = "";
    for(int i = 0; i < samaran2.length(); i++){
        char s = samaran2[i];
        if(samaran_asli[s] == '\0'){
            ans += '?'; // s -> ...
        }
        else{
            ans += samaran_asli[s];
        }
    }
    cout << ans << endl;
}