#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100010;
int n,m,k;
int a[12][N];
int dp[N];
signed main(){
	memset(dp,0,sizeof(dp));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			for(int p = i-1; p >= max(i-k, 0LL); p--){
				dp[p+1] = max(dp[p] + a[j][i], dp[p+1]);
			}
		}
	}
	cout << dp[m-k+1] << endl;
}