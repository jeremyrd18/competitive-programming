#include <bits/stdc++.h>

using namespace std;


void initialize(int x, int y, int z) {
  NA = x;
  NB = y;
  NC = z;
//  cout << NA << NB << NC << endl;
}

int guess(int K) {
	if(K == 0){
		int y = ask(0, NB, NC);
		if(y == 0){
			return 0;
		}
		return NA;
	}
	int l = 0, r = NA;
    int mid = K;
    mid /= 2;
    int ans = mid, tengah = K - 1;
    int tmpp = tengah - mid < 0 ? NB : tengah - mid;
    // cout << mid << " " << tmpp << endl;
    int start = ask(mid, tmpp, 0);
    // cout << start << endl;
    if(start == 0){
        l = mid + 1;
        while(l <= r){
            mid = (l + r) / 2;
            int bb = (tengah - mid) < 0 ? NB : (tengah - mid);
            // cout << "in binser " << mid << " " << bb << endl;
            if(mid >= K){
            	// cout << "BREAK" << endl;
            	r = mid - 1;
            	continue;
			}
            if(ask(mid, bb, 0) == 0){
            	// cout << ans << endl;
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << "ans : " << ans;
        int bb = (K - ans - 2) < 0 ? -1 : K - ans - 2;
    	cout << " " << bb << endl;
    	int y = ask(ans + 1, bb, 0);
    	// cout << y << endl;
    	if(y == 0){
    		// cout << ans + 1 << endl;
        	return ans + 1;
    	}
    	// cout << NA + bb << endl;
    	return NA + bb;
    }
    else{
        l = mid + 1;
        while(l <= r){
            mid = (l + r) / 2;
            int aa = (tengah - mid) < 0 ? NA : (tengah - mid);
            // cout << "in binser " << aa << " " << mid << endl;
            if(mid >= K){
            	// cout << "BREAK" << endl;
            	r = mid - 1;
            	continue;
			}
            if(ask(aa, mid, 0) == 1){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << "ans : " << ans;
        int bb = (K - ans - 2) < 0 ? 0 : K - ans - 1;
    	cout << " " << bb << endl;
    	int y = ask(bb + 1, ans + 1, 0);
    	// cout << y << endl;
    	if(y == 0){
    		// cout << bb << endl;
        	return bb;
    	}
    	// cout << NA + ans + 1 << endl;
    	return NA + ans + 1;
    }
}