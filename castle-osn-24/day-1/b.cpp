#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int x){
    cout << "? " << x << endl;
    int w;
    cin >> w;
    return w;
}

signed main(){
    int n;
    cin >> n;
    vector<int> v;
    int i = 0;
    while(i < 32900){
        int x = ask(i);
        if(x == 0){
            v.push_back(i);
            i++;
        }
        else if(x == 1){
            v.push_back(i + 1);
            i += 2;
        }
        else{
            i += 2;
        }
    }
    cout << "! ";
    for(auto x : v){
        cout << x << " ";
    }
}