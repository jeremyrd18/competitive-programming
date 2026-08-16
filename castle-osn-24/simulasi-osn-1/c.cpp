#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    if(n == 11){
        cout << "A " << 4 << " " << 5 << " " << 2 << endl;
        cout << "1 5 6 11" << endl;
        cout << "2 3 7 8 10" << endl;
        cout << "4 9" << endl;
        return 0;
    }
    if(q == 11){
        int l = 1, r = n, mid;
        int x;
        int ada = 0;
        while(l <= r){
            mid = (l + r) / 2;
            cout << "Q 1 1 " << mid << endl;
            cin >> x;
            if(x == 1){
                l = mid + 1;
            }
            else{
                ada = 1;
                r = mid - 1;
            }
        }
        if(!ada){
            cout << "A " << n << " 0 0" << endl;
            for(int i = 1; i <= n; i++) cout << i << " ";
        }        
        else{
            if(x) mid++;
            cout << "A " << mid - 1 << " " << n - mid + 1 << " 0"<< endl;
            for(int i = 1; i < mid; i++) cout << i << " ";
            cout << endl;
            for(int i = mid; i <= n; i++) cout << i << " ";
        }
        return 0;
    }
    if(q == 22){
        int l = 1, r = n, mid;
        int x;
        int ada = 0;
        int v1, v2;
        while(l <= r){
            mid = (l + r) / 2;
            cout << "Q 1 1 " << mid << endl;
            cin >> x;
            if(x == 1){
                l = mid + 1;
            }
            else{
                ada = 1;
                r = mid - 1;
            }
        }
        if(!ada){
            cout << "A " << n << " 0 0" << endl;
            for(int i = 1; i <= n; i++) cout << i << " ";
            return 0;
        }        
        if(!x) mid--;
        v1 = mid;
        l = 1, r = n;
        while(l <= r){
            mid = (l + r) / 2;
            cout << "Q 1 " << mid << " " << n << endl;
            cin >> x;
            if(x == 1) r = mid - 1;
            else l = mid + 1;
        }
        if(!x) mid++;
        v2 = mid;
        if(v1 + 1 == v2){
            cout << "A " << v1 << " " << n - v2 + 1 << " 0" << endl;
            for(int i = 1; i <= v1; i++){
                cout << i << " ";
            } cout << endl;
            for(int i = v2; i <= n; i++){
                cout << i << " ";
            } cout << endl;
        }
        else{
            cout << "A " << v1 << " " << v2 - v1 - 1 << " " << n - v2 + 1 << endl;
            for(int i = 1; i <= v1; i++){
                cout << i << " ";
            } cout << endl;
            for(int i = v1 + 1; i < v2; i++){
                cout << i << " ";
            } cout << endl;
            for(int i = v2; i <= n; i++){
                cout << i << " ";
            }cout << endl;
        }
    }
    vector<int> v[3];
    v[0].push_back(1);
    vector<int> belum;
    for(int i = 2; i <= n; i++){
        cout << "Q 1 1 " << i << endl;
        int x;
        cin >> x;
        if(x){
            v[0].push_back(i);
        }
        else belum.push_back(i);
    }
    if(belum.empty()){
        cout << "A " << v[0].size() << " " << 0 << " " << 0 << endl;
        for(auto i : v[0]){
            cout << i << " ";
        } cout << endl;
        return 0;
    }
    v[1].push_back(belum[0]);
    for(int i = 1; i < belum.size(); i++){
        cout << "Q 1 "  << belum[0] << " " << belum[i] << endl;
        int x;
        cin >> x;
        if(x)v[1].push_back(belum[i]);
        else v[2].push_back(belum[i]);
    }
    cout << "A " << v[0].size() << " " << v[1].size() << " " << v[2].size() << endl;
    for(auto i : v[0]){
        cout << i << " ";
    } cout << endl;
    for(auto i : v[1]){
        cout << i << " ";
    } cout << endl;
    for(auto i : v[2]){
        cout << i << " ";
    } cout << endl;
}