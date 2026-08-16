#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    long long m;
	cin >> n >> m;
	int a[n + 3];
	long long sum = 0;
	int maxleng = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		maxleng = max(maxleng, a[i]);
	}
	if(sum < m){
		cout << -1 << endl;
		return 0;
	}
	int l = 0, r = maxleng, ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		long long tebang = 0;
		for(int i = 1; i<=n; i++){
			if(a[i] > mid){
				tebang += (a[i] - mid);
			}
		}
		if(tebang >= m){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
}