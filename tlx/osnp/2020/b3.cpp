//
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n,maxDay=-1;
	cin>>n;
	ll s[n+2], e[n+2], p[n+2];
	for(ll i=1; i<=n; i++){
		cin>>s[i]>>e[i]>>p[i];
		maxDay=max(maxDay,e[i]);
	}
	ll dp[maxDay+3];
	memset(dp, 0, sizeof dp);
	for(ll i=1; i<=maxDay; i++){
		dp[i]=dp[i-1];
		for(ll j=1; j<=n; j++){
			if(e[j]<=i){
				dp[i]=max(dp[i], dp[s[j]-1]+p[j]);
			}
		}
	}
	cout<<dp[maxDay]<<endl;
}
