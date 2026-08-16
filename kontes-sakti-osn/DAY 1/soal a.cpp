//
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
    cin >> t;
	while(t--){
		int h, n;\
        cin >> h >> n;
		vector<int> d, c;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            d.push_back(x);
        }
		for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            c.push_back(x);
        }
		set<pair<int, int>> S;
		for(int i = 0; i < n; i++){
			S.insert({1, i});
		}
		int end = 1;
		while(h > 0){
			auto [a, i] = *S.begin();
			S.erase(S.begin());
			end = a;
			h -= d[i];
			S.insert({a + c[i], i});
		}
		cout << end << endl;
	}
}