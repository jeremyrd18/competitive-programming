#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll botol[n];
	for(ll i=0; i<n; i++){
		cin>>botol[i];
	}
	ll used=0;
	m+=k;
	sort (botol, botol+n);
	for(ll i=0; i<n; i++){
		if(botol[i]>m){
			used++;
			m=botol[i]+k;
		}
	}
	cout<<used;
}
