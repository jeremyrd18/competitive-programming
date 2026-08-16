//#include "art.h"
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>


vector<vi> pos;

int NN;

void generate(int idx, int k, vi v, int sz){
	if(sz == k){
		pos.pb(v);
		return;
	}
	if(idx >= NN){
		return;
	}
	generate(idx + 1, k, v, sz);
	v.pb(idx);
	generate(idx + 2, k, v, sz + 1);
}


std::vector<int> calculate_steps(int n, std::vector<int> a) {
	NN = n;
	if(n == 1){
		return {0};
	}
	else if(n == 2){
		if(a[0] != a[1]){
			return {0};
		}
		else return{1};
	}
	else if(n == 3){
		if(a[1] < a[2] && a[1] < a[0]){
			return {0, 0};
		}
		else{
			int k1 = a[1] - max(a[0], a[2]);
			if(k1 < 0){
				return {0, a[1] - min(a[0], a[2]) + 1};
			}
			else{
				if(a[1] > a[2] && a[1] > a[0]) return {0, a[1] - min(a[0], a[2]) + 1};
				return {k1 + 1, a[1] - min(a[0], a[2]) + 1};
			}
		}
	}
	int gn = 0;
	for(int i = 0; i < n; i++){
		if(i == 0){
			if(a[i] > a[i + 1]) gn++;
		}
		else if(i == n - 1){
			if(a[i] > a[i - 1]) gn++;
		}
		else{
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				gn++;
			}
		}
	}
	
	vi ans;
	for(int i = 0; i < gn; i++) ans.pb(0);

	if(gn == (n + 1) / 2) return ans;

	for(int k = gn + 1; k <= (n + 1) / 2; k++){
		pos = {};
		generate(0, k, {}, 0);
		int harga = 1e9;
		
		for(vi v : pos){
			int tmp = 0;
			int newa[n + 5];
			for(int i = 0; i < n; i++){
				newa[i] = a[i];
			}
			for(auto x : v){
				
//				cout << x << " ";
				if(x == 0){
					if(newa[x] > newa[x + 1]) continue;
					tmp += newa[x + 1] - newa[x] + 1;
					newa[x + 1] = newa[x] - 1;
				}
				else if(x == n - 1){
					if(newa[x] > newa[x - 1]) continue;
					tmp += newa[x - 1] - newa[x] + 1;
					newa[x - 1] = newa[x] - 1;
				}
				else{
					if(newa[x] <= newa[x + 1]){
						tmp += newa[x + 1] - newa[x] + 1;
						newa[x + 1] = newa[x] - 1;
					}
					if(newa[x] <= newa[x - 1]){
						tmp += newa[x - 1] - newa[x] + 1;
						newa[x - 1] = newa[x] - 1;
					}
				}
			}
//			cout << endl;
//			if(tmp < harga){
//				for(auto x : v){
//					cout << x << " ";
//				}
//				cout << endl;
//			}
			harga = min(harga, tmp);
		}
		ans.pb(harga);
	}
	return ans;
}

int main() {
  int N;
  std::cin >> N;
  
  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::vector<int> ans = calculate_steps(N, A);
  for (int i = 0; i < ans.size(); i++) {
    if (i != 0) std::cout << " ";
    std::cout << ans[i];
  }
  std::cout << "\n";
}
