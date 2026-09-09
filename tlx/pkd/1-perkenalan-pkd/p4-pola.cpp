#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int sz = ceil(sqrt(s.length()));
    while(s.length() < sz * sz){
        s += '.';
    }
    for(int i = 0; i < sz; i++){
        if(i % 2 == 0){
            cout << s.substr(i * sz, sz) << endl;
        }
        else{
            string temp = s.substr(i * sz, sz);
            reverse(temp.begin(), temp.end());
            cout << temp << endl;
        }
    }
}