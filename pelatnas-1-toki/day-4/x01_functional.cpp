#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

int getSum(int n, int a[]){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += a[i];
    }
    return cnt;
}   