#include <bits/stdc++.h>
using namespace std;
typedef int ll;

int main(){
	ll r, c;
	cin >> r >> c;
	ll pref[r+5][c+5];
	memset(pref, 0, sizeof pref);
	for (ll i=1; i<=r; i++){
		for(ll j=1; j<=c; j++){
			char wow;
			cin>>wow;
			ll temp = wow -'0';
			pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + temp;
		}
	}
    for (ll i=1; i<=r; i++){
		for(ll j=1; j<=c; j++){
			cout<<pref[i][j];
		}
		cout<<endl;
	}
	ll maxSet=0;
	ll cntPrt = pref[r][c];//jumlah peserta / count participant
	//cout<<pref[c];
	for(ll k = 1; k<= cntPrt; k++){
		if(cntPrt % k != 0){
			continue;
		}
		ll panjang = k, lebar = cntPrt/k;
		if(panjang > r || lebar >c) continue;
		for(ll i = panjang; i<=r; i++){
			for(ll j = lebar; j<=c; j++){
				maxSet=max(maxSet, pref[i][j]-pref[i-panjang][j]-pref[i][j-lebar]+pref[i-panjang][j-lebar]);
			}
		}
	}
	if(maxSet==0){
		cout<<-1<<endl;
	}
	else cout<<cntPrt-maxSet;
}