#include <bits/stdc++.h>
using namespace std;
#define int long long
const int minval = -1e18;
int n, k, dp[105][25][25][25][25], vis[105][25][25][25][25];
char mat[25][25];

signed main(){
    cin >> n >> k;
    vector<int> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i <= 104; i++){
        for(int a = a; a <= 24; a++){
            for(int b = a + 1; b <= 24; b++){
                for(int c = b + 1; c <= 24; c++){
                    for(int d = c + 1; d <= 24; d++){
                        dp[i][a][b][c][d] = minval;
                        vis[i][a][b][c][d] = 0;
                    }
                }
            }
        }
    }
    // cout << 1;
    sort(s.begin(), s.end());
    // states of s sorted
    dp[0][s[0]][s[1]][s[2]][s[3]] = 0;
    vis[0][s[0]][s[1]][s[2]][s[3]] = 1;
    int cntlib = 0;
    int freq[k + 5];
    for(int i = 1; i <= k; i++) freq[i] = 0;
    // dp bekerja setelah ketemu library
    bool sisa = 0;
    for(int ROOM = 0; ROOM < n; ROOM++){
        // cout << ROOM << endl;
        int type; cin >> type;
        if(type == 1){
            int a;
            cin >> a;
            freq[a]++;
            sisa = 1;
        }
        else{
            sisa = 0;
            cntlib++;
            int val = -1;
            for(int a = 1; a <= k; a++){
                for(int b = a + 1; b <= k; b++){
                    for(int c = b + 1; c <= k; c++){
                        // PERPUS SEBELUM YANG MAX yg ada a, b, c sebagai sihir
                        val = -1;
                        for(int d = 1; d <= k; d++){
                            if(d == a || d == b || d == c) continue;
                            vector<int> tmp;
                            tmp.push_back(a);
                            tmp.push_back(b);
                            tmp.push_back(c);
                            tmp.push_back(d);
                            sort(tmp.begin(), tmp.end());
                            int aa = tmp[0], bb = tmp[1], cc = tmp[2], dd = tmp[3];
                            if(vis[cntlib - 1][aa][bb][cc][dd] == 0) continue;
                            int add = 0;
                            for(int i = 1; i <= k; i++){
                                if(mat[aa][i] == '1' || mat[bb][i] == '1' || mat[cc][i] == '1' || mat[dd][i] == '1'){
                                    add += freq[i];
                                }
                            }
                            // if(add == 0) continue;
                            val = max(val, dp[cntlib - 1][aa][bb][cc][dd] + add);
                        }
                        if(val == -1) continue;
                        // INISIASI DP
                        for(int d = 1; d <= k; d++){
                            if(d == a || d == b || d == c) continue;
                            vector<int> tmp;
                            tmp.push_back(a);
                            tmp.push_back(b);
                            tmp.push_back(c);
                            tmp.push_back(d);
                            sort(tmp.begin(), tmp.end());
                            int aa = tmp[0], bb = tmp[1], cc = tmp[2], dd = tmp[3];
                            vis[cntlib][aa][bb][cc][dd] = 1;
                            dp[cntlib][aa][bb][cc][dd] = max(dp[cntlib][aa][bb][cc][dd], val);
                        }
                    }
                }
            }
            for(int i = 1; i <= k; i++) freq[i] = 0;
        }
    }
    // jika perpus bukan ruangan terakhir dikunjungi
    // ulangi sekali lagi ruang type 2
    if(sisa){
        sisa = 0;
            cntlib++;
            int val = -1;
            for(int a = 1; a <= k; a++){
                for(int b = a + 1; b <= k; b++){
                    for(int c = b + 1; c <= k; c++){
                        // PERPUS SEBELUM YANG MAX yg ada a, b, c sebagai sihir
                        val = -1;
                        for(int d = 1; d <= k; d++){
                            if(d == a || d == b || d == c) continue;
                            vector<int> tmp;
                            tmp.push_back(a);
                            tmp.push_back(b);
                            tmp.push_back(c);
                            tmp.push_back(d);
                            sort(tmp.begin(), tmp.end());
                            int aa = tmp[0], bb = tmp[1], cc = tmp[2], dd = tmp[3];
                            if(vis[cntlib - 1][aa][bb][cc][dd] == 0) continue;
                            int add = 0;
                            for(int i = 1; i <= k; i++){
                                if(mat[aa][i] == '1' || mat[bb][i] == '1' || mat[cc][i] == '1' || mat[dd][i] == '1'){
                                    add += freq[i];
                                }
                            }
                            // if(add == 0) continue;
                            val = max(val, dp[cntlib - 1][aa][bb][cc][dd] + add);
                        }
                        if(val == -1) continue;
                        // INISIASI DP
                        for(int d = 1; d <= k; d++){
                            if(d == a || d == b || d == c) continue;
                            vector<int> tmp;
                            tmp.push_back(a);
                            tmp.push_back(b);
                            tmp.push_back(c);                            tmp.push_back(d);
                            sort(tmp.begin(), tmp.end());
                            int aa = tmp[0], bb = tmp[1], cc = tmp[2], dd = tmp[3];
                            vis[cntlib][aa][bb][cc][dd] = 1;
                            dp[cntlib][aa][bb][cc][dd] = max(dp[cntlib][aa][bb][cc][dd], val);
                        }
                    }
                }
            }
            for(int i = 1; i <= k; i++) freq[i] = 0;
    }
    int ans = 0;
    // cout << cntlib << endl;
    for(int a = 1; a <= k; a++){
        for(int b = a + 1; b <= k; b++){
            for(int c = b + 1; c <= k; c++){
                for(int d = c + 1; d <= k; d++){
                    ans = max(ans, dp[cntlib][a][b][c][d]);
                    // cout << dp[4][a][b][c][d] << endl;
                }
            }
        }
    }
    cout << ans << endl;
}