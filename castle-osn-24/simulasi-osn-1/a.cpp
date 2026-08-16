#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main(){
    int seleb, foto, juri, like, win;
    cin >> seleb >> foto >> juri >> like >> win;
    vector<pair<int, int> > post(foto);
    for(int i = 0; i < foto; i++){
        int s, l;
        cin >> s >> l;
        post[i] = {l, s};
    }
    sort(post.rbegin(), post.rend());
    set<int> menang;
    for(int i = 0; i < win; i++){
        menang.insert(post[i].se);
    }
    int minv = post[win - 1].fi;
    // for(int i = win; i < foto; i++){
    //     if(minv == post[i].fi){
    //         menang.insert(post[i].se);
    //     }
    // }
    int lastv = minv;
    for(int i = win; i < foto; i++){
        if(lastv == post[i].fi){
            menang.insert(post[i].se);
        }
        else if(foto - like >= i + 1 - win){
            if(minv <= juri + post[i].fi){
                menang.insert(post[i].se);
                lastv = post[i].fi;
            }
        }
    }
    cout << menang.size() << endl;
}