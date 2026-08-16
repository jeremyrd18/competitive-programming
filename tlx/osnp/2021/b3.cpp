#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int h[1005],k[1005],d[1005];
int memo[1005][10005];
int dp(int idx, int uang){
	if(uang<=0) return 0;
	if(idx>n) return 0;
	if(memo[idx][uang]!=-1) return memo[idx][uang];
	int ans=dp(idx+1,uang);//skip
	if(h[idx]<=uang){
		if(d[idx]==1){
			ans=max(k[idx]+dp(idx+1,uang-h[idx]),ans);
		}
		else{
			ans=max(k[idx]+dp(idx, uang-h[idx]),ans);	
		}
	}
	memo[idx][uang]=ans;
	return memo[idx][uang];
}

int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>h[i]>>k[i]>>d[i];
	}
	memset(memo, -1, sizeof memo);
	cout<<dp(1, m)<<endl;
}