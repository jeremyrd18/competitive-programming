#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int n, par[145];

int ask(int satu, vector<int> dua){
    vector<int> temp(n + 5, 0);
    temp[satu] = 1;
    for(auto x : dua){
        temp[x] = 2;
    }
    cout << "? ";
    for(int i = 1; i <= n; i++){
        cout << temp[i] << " ";
    } cout << endl;
    int x; cin >> x;
    return x;
}

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    par[find(x)] = find(y);
}

bool cek(int x, int y){
    return (find(x) == find(y));
}

// sekarang add yang belum visited jika satu sudah empty

signed main(){
    cin >> n;
    vector<int> satu = {1}, dua; // satu -> nilai yg di sudah cout << 1, dua -> nilai yang masih di cout << 2
    for(int i = 2; i <= n; i++){
        par[i] = i;
        dua.push_back(i);
    } par[1] = 1;
    int k = ask(1, {2});
    vector<int> price(2); price[0] = k; price[1] = -1;
    int found = 0; // if found a and b
    vector<pair<int, pair<int, int> > > edges;
    int idx = 0;
    vector<pair<int, int> > adj;
    while(dua.size()){
    while(!dua.empty() && idx < satu.size()){
        if(found){
            int que = ask(satu[idx], dua);
            if(que == dua.size() * price[1]){
                // cout << "no" << endl;
                if(idx == satu.size() - 1)
                    adj.push_back({satu.back(), dua.back()}), satu.push_back(dua.back()), dua.pop_back();
                
                idx++;
                continue;
            }
            // array satu akan bertambah
            else{
                int cnt = 0;
                // we find how much A's are there in this range
                for(int i = 0; i <= dua.size(); i++){
                    if(price[0] * i + price[1] * (dua.size() - i) == que){
                        cnt = i;
                        break;
                    }
                }
                // cout << cnt << endl;
                while(cnt--){
                    // we do binary search
                    vector<int> possible = dua;
                    while(possible.size() > 1){
                        vector<int> can;
                        for(int i = 0; i < possible.size() / 2; i++){
                            can.push_back(possible[i]);
                        }
                        if(ask(satu[idx], can) == price[1] * can.size()){
                            vector<int> new_can;
                            for(int i = 0; i < possible.size(); i++){
                                sort(can.begin(), can.end());
                                if(binary_search(can.begin(), can.end(), possible[i])) continue;
                                new_can.push_back(possible[i]);
                            }
                            possible = new_can;
                        }
                        else{
                            possible = can;
                        }
                    }
                    dua.erase(find(dua.begin(), dua.end(), possible[0]));
                    satu.push_back(possible[0]);
                    edges.push_back({price[1], {possible[0], satu[idx]}});
                    adj.push_back({satu[idx], possible[0]});
                }
                idx++;
            }
        }
        else{
            // if all K
            int que = ask(satu[idx], dua);
            if(que == k * dua.size()){
                if(idx == satu.size() - 1)
                    adj.push_back({satu.back(), dua.back()}), satu.push_back(dua.back()), dua.pop_back();
                
                idx++;
                continue;
            }
            else{
                // cout << "ketemu" << endl;
                found = 1;
                vector<int> possible = dua;
                while(possible.size() > 1){
                    vector<int> can;
                    for(int i = 0; i < possible.size() / 2; i++){
                        can.push_back(possible[i]);
                    }
                    // for(auto aa : satu) cout << aa << " ";
                    // cout << endl;
                    // for(auto aa : can) cout << aa << " ";
                    // cout << endl;
                    // for(auto aa : possible) cout << aa << " ";
                    //     cout << endl;
                    if(ask(satu[idx], can) == price[0] * can.size()){
                        vector<int> new_can;
                        sort(can.begin(), can.end());
                        for(int i = 0; i < possible.size(); i++){
                            if(binary_search(can.begin(), can.end(), possible[i])) continue;
                            new_can.push_back(possible[i]);
                        }
                        possible = new_can;
                    }
                    else{
                        possible = can;
                    }
                }
                for(int i = 0; i < satu.size(); i++){
                    for(int j = i + 1; j < satu.size(); j++){
                        edges.push_back({price[0], {satu[i], satu[j]}});
                    }
                }
                price[1] = ask(satu[idx], possible);
                sort(price.begin(), price.end());
                // cout << "ketemu " << price[0] << " " << price[1] << endl;
            }
        }
    }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(price[1] != -1){
                edges.push_back({price[1], {i, j}});
            }
            else edges.push_back({price[0], {i, j}});
        }
    }
    // sort(edges.begin(), edges.end());
    cout << "! " << n - 1 << endl;
    // for(auto x : adj){
    //     cout << x.fi << " " << x.se << endl;
    // }
    for(auto x : edges){
        if(cek(x.se.fi, x.se.se)) continue;
        merge(x.se.fi, x.se.se);
        cout << x.se.fi << " " << x.se.se << endl;
    }
    
}

/*
Steps :
1. Find K (the first number we query)
2. Find A and B
3. Binary Search to find the answer
- Make function to count Ax + By = Sum of range
*/