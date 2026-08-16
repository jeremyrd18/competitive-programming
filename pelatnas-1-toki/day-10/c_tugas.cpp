#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>

bool comp(pii a, pii b){
	return (a.fi - a.se) < (b.fi - b.se);
}

signed main(){
	int n;
	cin >> n;
	vector<pii> tmp;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		tmp.pb({x, y});
	}
	
	vector<pii> one, two;
	bool udah[n + 5];
	memset(udah, 0, sizeof udah);
	
	int p;
	cin >> p;
	
	for(int i = 0; i < p; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		udah[x] = 1;
		udah[y] = 1;
		two.pb({tmp[x].fi + tmp[y].fi, tmp[x].se + tmp[y].se});
	}
	
	for(int i = 0; i < n; i++){
		if(!udah[i]){
			one.pb(tmp[i]);
		}
	}
	
	sort(one.begin(), one.end(), comp);
	sort(two.begin(), two.end(), comp);
	
	int szone = one.size(), sztwo = two.size();
	
	int pref1[szone + 5], pref2[sztwo + 5], suf1[szone + 5], suf2[sztwo + 5];
	
	memset(pref1, 0, sizeof pref1);
	memset(pref2, 0, sizeof pref2);
	memset(suf1, 0, sizeof suf1);
	memset(suf2, 0, sizeof suf2);
	
	
	for(int i = 1; i <= szone; i++) pref1[i] = pref1[i - 1] + one[i - 1].fi;
	for(int i = szone; i >= 1; i--) suf1[i] = suf1[i + 1] + one[i - 1].se;
	
	for(int i = 1; i <= sztwo; i++) pref2[i] = pref2[i - 1] + two[i - 1].fi;
	for(int i = sztwo; i >= 1; i--) suf2[i] = suf2[i + 1] + two[i - 1].se;
	
	int ans = 1e16;
	
	for(int i = 0; i <= sztwo; i++){
		if(n / 2 - (i * 2) < 0 || (n / 2 - (i * 2)) >= szone || szone - (n / 2 - (i * 2)) < 0 || szone - (n / 2 - (i * 2)) >= szone) continue;
		ans = min(pref2[i] + suf2[sztwo - i] + pref1[(n / 2 - (i * 2))] + suf1[szone - (n / 2 - (i * 2))], ans);
		cout << i << " "ans << endl;
	}
	cout << ans << endl;
}