#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
	cin>>n;
	ll suku1=1;
	ll suku2=1;
	while(suku2<=n){
		ll temp=suku1;
		suku1 = suku2;
		suku2 +=temp;
		if(n%suku2==0){
			cout<<n*suku1/suku2;
			return 0;
		}
	}
	cout<<-1;
}