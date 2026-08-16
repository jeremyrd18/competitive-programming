#include <bits/stdc++.h>
using namespace std;
const int N = 8005;
int n, st[N];

int judge(int l, int r){
    cout << "? " << l << " " << r << endl;
    int wow;
    cin >> wow;
    return wow;
}

void build(int node, int l, int r){
    if(l == r){
        st[l] = l;
        return;
    }
    int ln = node * 2, rn = (node * 2) + 1, mid = (l + r)/2;
    build(ln, l, mid);
    build(rn, mid + 1, r);
    if(judge(st[ln], st[rn]) == judge(st[ln], st[rn] - 1)){
        st[node] = st[rn];
    }
    else{
        st[node] = st[ln];
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        build(1, 0, n - 1);
        cout << "! " << st[0] << endl;
    }
}