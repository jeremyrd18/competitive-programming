#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

int binser(vector<pii> &v, int x){
    int l = 0, r = v.size() - 1;
    if(v.size() == 0){
        return -1;
    }
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(x <= v[mid].fi){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    int ans1 = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(x >= v[mid].fi){
            ans1 = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(v[ans].fi >= v[ans1].fi){
        return ans;
    }
    else return ans1;
}

int binser2(vector<pii> &v, int x, int discard){
    
}

int main(){
    int r, c, n;
    cin >> r >> c >> n;
    vector<pii> tow[c + 3];
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        tow[y].push_back({x, i});
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < c; k++){
                int idx = binser(tow[k], j);
                int 
            }
        }
    }
}