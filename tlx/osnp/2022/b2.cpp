//https://tlx.toki.id/problems/osnp-2022/B2/
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	ll k;
	cin>>k;
	pair<ll,ll> p[k];
	for(ll i=0; i<k; i++){
		cin>>p[i].second;
	}
	for(ll i=0; i<k; i++){
		cin>>p[i].first;
	}
	sort(p, p+k);
	ll n;
	cin>>n;
	vector<ll> b;
	for(ll i=0; i<n; i++){
		ll a;
		cin>>a;
		b.push_back(a);
	}
	sort(b.rbegin(),b.rend());
	/*for(ll i=0; i<k; i++){
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	for(ll i=0; i<n; i++){
		cout<<b[i]<<endl;
	}*/
	ll ans=0;
	ll i=0;
	ll a=0;
	while(n>0){
		//cout<<ans<<" "<<i<<endl;
		if(p[i].second==0){
			i++;
		}
		p[i].second--;
		n--;
		ans+=b[a]*p[i].first;
		a++;
	}
	cout<<ans<<endl;
	
}