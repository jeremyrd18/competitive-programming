#include <bits/stdc++.h>
using namespace std;
#define ll int
#define int long long

int getSum(ll n, ll a[]){
  int ans = 0;
  for(int i = 0; i < n; i++){
    ans += a[i];
  }
  return ans;
}