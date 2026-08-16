#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int b, c, d;
	cin >> b >> c >> d;
	int times = c - d;
	if(times == 0){
		if(b >= c){
			cout << b - c << endl;
			return 0;
		}
		else cout << 0 << endl;
		return 0;
	}
	else{
		set<int> usage;
		for(int i = 1; i*i <= times; i++){
//			bool ok =i > c;
//			cout << ok << endl;
			if(times % i == 0 && i <= b && i > d){
				usage.insert(i);
			}
//			cout << times/i << " "
			if(times % i == 0 && (times % (times/i)) == 0 && times/i <= b && times/i > d){
				usage.insert(times/i);
			}
		}
		cout << usage.size() << endl;
	}
}