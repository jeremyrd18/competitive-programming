#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    string mantap;
    cin >> mantap;
    int n, me, en, ans = 0;
    cin >> n >> me >> en;
    priority_queue<pair<int, int> > pq;
    for(int i = 0; i<n - 1; i++){
        int a, k, l;
        cin >> a >> k >> l;
        if(me >= a){
            if(l <= k){
                ans += l;
                me++;
            }
            else{
                pq.push({-(l - k), a});
                ans += k;
            }
        }
        else{
            while(!pq.empty() && me < a){
                int time = pq.top().first;
                int fight = pq.top().second;
                pq.pop();
                ans -= time;
                me++;
            }
            if(me >= a){
                if(l <= k){
                    ans += l;
                    me++;
                }
                else{
                    pq.push({-(l - k), a});
                    ans += k;
                }
            }
            else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    if(me >= en){
        cout << ans << endl;
    }
    else{
        while(!pq.empty() && me < en){
            int time = pq.top().first;
            int fight = pq.top().second;
            pq.pop();
            ans -= time;
            me++;
        }
        if(me >= en){
            cout << ans << endl;
        }
        else cout << -1 << endl;
    }
}