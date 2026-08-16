#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, p, q;
	cin >> n >> p >> q;
	pair<int,int> e[n];
	for(int i = 0; i<n; i++){
		cin >> e[i].first;
		e[i].second = i;
	}
	sort(e, e+n);
	map<int, int> ans;
	priority_queue<pair<int, int> > pq; // ans and batas atas(top)
	int up = 0;
	for(int i = 0; i<n; i++){
		bool ok = 0;
		while(up < n && e[up].first - e[i].first <= p){
			up++;
			ok = 1;
		}
		if(ok) up--;
		pq.push({up - i + 1, up});
		while(pq.top().second < i){
			pq.pop();
		}
		ans[e[i].second] = pq.top().first;
	}
	for(int i = 0; i<q; i++){
		int x;
		cin >> x;
		cout << ans[x - 1] << endl;
	}
	return 0;
}

