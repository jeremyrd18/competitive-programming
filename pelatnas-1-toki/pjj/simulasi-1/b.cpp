#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<string> dp(100000);
    vector<int> len(100000);
    len[0] = len[1] = 0;
    dp[0] = "-";
    dp[1] = "";
    int ans = 0;
    vector<char> temp;
    if(n % 3 == 0){
        cout << '-' << endl;
        return;
    }
    while(n > 100000){
        ans++;
        if(n % 2 == 0){
            n /= 2;
            temp.push_back('x');
        }
        else{
            n -= 3;
            temp.push_back('+');
        }
    }
    for(int i = 2; i <= n; i++){
        len[i] = 0;
        dp[i] = "-";
        if(i % 2 == 0){
            if(i >= 4){
                if(len[i - 3] > len[i / 2] && dp[i / 2] != "-"){
                    dp[i] = dp[i / 2] + "x";
                    len[i] = len[i / 2] + 1;
                }
                else if(dp[i - 3] != "-"){
                    dp[i] = dp[i - 3] + "+";
                    len[i] = len[i - 3] + 1;
                }
            }
            else if(dp[i / 2] != "-"){
                dp[i] = dp[i / 2] + "x";
                len[i] = len[i / 2] + 1;
            }
        }
        else if(i >= 4 && dp[i - 3] != "-"){
            dp[i] = dp[i - 3] + "+";
            len[i] = len[i - 3] + 1;
        }
    }
    if(dp[n] == "-"){
        cout << "-" << endl;
    }
    else{
        cout << dp[n];
        for(int i = temp.size() - 1; i >= 0; i--){
            cout << temp[i];
        }
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
    
}