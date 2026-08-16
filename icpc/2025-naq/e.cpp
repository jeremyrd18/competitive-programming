#include <bits/stdc++.h>
using namespace std;
#define se second
#define fi first

int n,m; 

int compute(int x, int y) {
    return (x-144)*(x-144)+(y-84)*(y-84);
}

int32_t main() {
    int scoreB = 0, scoreA = 0; 
    int lowestA = 1000000000, lowestB = 1000000000;
    for (int i = 0; i < 10; i++) {
        lowestA = 1000000000, lowestB = 1000000000;
        cin >> n;
        pair<int,int> x1[n+5], x2[m+5];
        for (int j = 0; j < n; j++) {
            cin >> x1[j].fi >> x1[j].se;
            lowestA = min(lowestA, compute(x1[j].fi, x1[j].se));
        }
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x2[j].fi >> x2[j].se;
            lowestB = min(lowestB, compute(x2[j].fi, x2[j].se));
        }

        if (lowestA > lowestB) {
            for (int j = 0; j < m; j++) {
                if (lowestA > compute(x2[j].fi, x2[j].se)) {
                    scoreB++;
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (lowestB > compute(x1[j].fi, x1[j].se)) {
                    scoreA++;
                }
            }
        }
    }
    cout << scoreA << " " << scoreB;
}