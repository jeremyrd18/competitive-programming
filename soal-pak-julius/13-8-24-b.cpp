#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b; cin >> a >> b;
    int p = b.length() - 1;
    for(int i = 0; i < a.length() - p; i++){
        int ada = 1;
        for(int j = i; j <= i + p; j++){
            if(a[j] != b[j - i]){
                ada = 0;
            }
        }
        if(ada == 1){
            cout << "ada" << endl;
            return 0;
        }
    }
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.length() - p; i++){
        int ada = 1;
        for(int j = i; j <= i + p; j++){
            if(a[j] != b[j - i]){
                ada = 0;
            }
        }
        if(ada == 1){
            cout << "ada" << endl;
            return 0;
        }
    }
    cout << "tidak ada" << endl;
}