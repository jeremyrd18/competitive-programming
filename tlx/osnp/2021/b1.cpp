//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll fpb=__gcd(a,b);
	ll kpk = a*b/fpb;
	ll ans=kpk/a+kpk/b;
	cout<<ans;
}