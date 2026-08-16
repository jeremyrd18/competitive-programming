// #include "kucing.h"
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>

const int maxn = 200005;
int idx[maxn];

int NN;

pii st[4 * maxn];

void build(int nd, int l, int r){
    if(l == r){
        st[nd] = {idx[l], l};
        return;
    }
    int mid = (l + r) / 2;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
    st[nd] = max(st[nd * 2], st[nd * 2 + 1]);
}

pii query(int nd, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return st[nd];
    }
    if(l > qr || r < ql){
        return {-1e16, - 1e16};
    }
    int mid = (l + r) / 2;
    return max(query(nd * 2, l, mid, ql, qr), query(nd * 2 + 1, mid + 1, r, ql, qr));
}

int dnc(int idx, int l, int r){
    if(l == r){
        return 1;
    }
    int ans = 0;
    pii nx = query(1, 0, N - 1, l, r);
    ans += abs(nx.se - idx);
    if(nx.se == l){
        return ans + dnc(nx.se, l + 1, r);
    }
    else if(nx.se == r){
        return ans + dnc(nx.se, l, r - 1);
    }
    else{
        return ans + max(dnc(nx.se, l, nx.se - 1), dnc(nx.se, l, r - 1));
    }
}

long long latihanKucing(int n, std::vector<int> p, std::vector<int> a, std::vector<int> b) {
    NN = n;
    for(int i = 0; i < n; i++){
        idx[i] = p[i];
    }
    build(1, 0, n - 1);
    pii maxv = query(1, 0, n - 1, 0, n - 1);
    if(maxv.se == 0){
        return dnc(0, 1, n - 1);
    }
    else if(maxv.se == n - 1){
        return dnc(n - 1, 0, n - 2);
    }
    else{
        return max(dnc(maxv.se, 0, maxv.se - 1), dnc(maxv.se, maxv.se + 1, n - 1));
    }
}

int main() {
  int N; std::cin >> N;

  std::vector<int> P(N);
  for (auto &p : P) {
    std::cin >> p;
  }

  std::vector<int> A(N - 1);
  std::vector<int> B(N - 1);
  for (int i = 0; i < N - 1; i++) {
    std::cin >> A[i];
    std::cin >> B[i];
  }

  long long ans = latihanKucing(N, P, A, B);
  std::cout << ans << std::endl;
  return 0;
}
