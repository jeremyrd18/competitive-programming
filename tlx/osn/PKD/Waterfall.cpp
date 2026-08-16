#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int cy, cx, rock, grid[N][N], memo[N][N];
pair<int, int> batu[N*N];

int dp(int x, int y){
    if(y > cy) return 0;
    int &res = memo[y][x];
    if(res != -1) return res;
    int cur = grid[y][x];
    int ans = 0;
    if(cur >= 1){
        ans++;
        int left = batu[cur].first;
        int right = batu[cur].second;
        if(left > 1){
            ans += (dp(left - 1, y));
        }
        if(right < cx){
            ans += (dp(right + 1, y));
        }
    }
    else ans = dp(x, y + 1);
    return res = ans;
}

signed main(){
    memset(memo, -1, sizeof memo);
    memset(grid, 0, sizeof grid);
    cin >> cy >> cx >> rock;
    for(int i = 1; i <= rock; i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        batu[i] = {x1, x2};
        for(int r = y1; r <= y2; r++){
            for(int c = x1; c <= x2; c++){
                grid[r][c] = i;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= cx; i++){
        ans = max(ans, dp(i, 1));
    }
    cout << ans << endl;
}