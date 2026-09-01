#include <bits/stdc++.h>
using namespace std;
#define int long long

int get_cycle_length(int node, vector<int> &adam, vector<int> &a){
        int ans = 0;
        int p = node;
        while (true)
        {
            adam[p] = true;
            ++ans;
            if (a[p] == node)
            {
                break;
            }
            p = a[p];
        }
        return ans;
    };

signed main(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    queue<int> q;
    vector<int> sol(n + 1, -1);
    for (int i = 1; i <= n; ++i){
        if (cnt[i] == 0){
            q.push(i);
            sol[i] = 0;
        }
    }
    while (!q.empty()){
        int qui = q.front();
        q.pop();
        assert(sol[qui] != -1);
        if (sol[qui] == 0){
            if (sol[a[qui]] == -1){
                sol[a[qui]] = 1;
                q.push(a[qui]);
                continue;
            }
            if (sol[a[qui]] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
        cnt[a[qui]]--;
        if (cnt[a[qui]] == 0){
            sol[a[qui]] = 0;
            q.push(a[qui]);
        }
    }
    vector<int> adam(n + 1);
    for (int i = 1; i <= n; ++i){
        if (sol[i] == -1 && !adam[i]){
            int sz = get_cycle_length(i, adam, a);
            if (sz % 2 == 1){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        if (sol[i] == -1){
            for (int color = 0; color <= 1; ++color){
                int p = i;
                bool x = color;
                bool ok = true;
                while (true){
                    color = !color;
                    if (sol[a[p]] != -1 && sol[a[p]] != color){
                        ok = false;
                        break;
                    }
                    p = a[p];
                    if (p == i){
                        break;
                    }
                }
                if (ok){
                    p = i;
                    sol[p] = color;
                    while (true){
                        sol[a[p]] = !sol[p];
                        p = a[p];
                        if (p == i){
                            break;
                        }
                    }
                    break;
                }
            }
            if (sol[i] == -1){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    int sz = 0;
    for (int i = 1; i <= n; ++i){
        if (sol[i] == 0){
            sz++;
        }
    }
    cout << sz << '\n';
    for (int i = 1; i <= n; ++i){
        if (sol[i] == 0){
            cout << a[i] << ' ';
        }
    }
}