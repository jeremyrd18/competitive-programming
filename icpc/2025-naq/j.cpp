#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[100];
    for(int i = 0; i < 100; i++){
        cin >> a[i];
    }
    if(a[99] % 10 == 0) cout << 10;
    else cout << a[99] % 10;
}