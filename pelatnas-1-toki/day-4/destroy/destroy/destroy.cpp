#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define pii pair < int, int >
#define vi vector <int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007,
          maxn = 200005;

vector < int > adj[maxn];
int szadj[maxn];
vi ans;
int udah[maxn];

void dfs2(int nd, int par) {
	if(szadj[nd] == 0){
		if(udah[nd] != 1){
			udah[nd] = 1;
			ans.pb(nd);
		} 
		return;
	} 
	if(szadj[nd] % 2 == 0) {
		if(nd != par) szadj[par]--;
		szadj[nd] = 0;
		if(udah[nd] == 0){
      udah[nd] = 1;
		  ans.pb(nd);
    }
		for(auto x : adj[nd]) {
			if(x != par) {
				szadj[x]--;
				dfs2(x, nd);
			}
		}
	}
}

void dfs1(int nd, int par) {
	//	if(szadj[nd] == 0){
	//		if(nd == par) return;
	//		szadj[par]--;
	//		return;
	//	}
	// cout << nd << endl;
	for (auto x: adj[nd]) {
		if (x != par) {
			dfs1(x, nd);
		}
	}
	if (szadj[nd] % 2 == 0) {
		dfs2(nd, par);
	}
}

vector < int > destroy(int n, vi u, vi v) {
	memset(udah, 0, sizeof udah);
	for (int i = 0; i < n - 1; i++) {
		adj[u[i]].pb(v[i]);
		adj[v[i]].pb(u[i]);
	}
	for (int i = 1; i <= n; i++) {
		szadj[i] = adj[i].size();
	}
	dfs1(1, 1);
	// for (auto x: ans) {
	// 	cout << x << " ";
	// }
	// cout << endl;
	if (ans.size() != n) {
		ans = {};
		for (int i = 0; i < n; i++) ans.pb(-1);
	}
	return ans;
}