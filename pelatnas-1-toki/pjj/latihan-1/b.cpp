#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int temp = 1;
    while(n--){
        int x;
        cin >> x;
        if(x == temp){
            cout << "BENAR" << endl;
            cout << flush;
            temp++;
        }
        else{
            temp = 1;
            cout << "SALAH" << endl;
            cout << flush;
        }
    }
}