#include <bits/stdc++.h>
using namespace std;
#define int int
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

bool cek;

int nn;

string anss = "999999999999999999999999999";

void bf(int cur, int nx1, int nx2, string v){
    if(nx1 >= nn){
        anss = min(anss, v);
        return;
    }
    if(nx2 >= nn){
        if(v[cur] > v[nx1]) swap(v[cur], v[nx1]);
        anss = min(anss, v);
        return;
    }
    string tmp = v;
    tmp[cur] = v[nx1];
    tmp[nx1] = v[nx2];
    tmp[nx2] = v[cur];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
    tmp = v;
    tmp[cur] = v[nx2];
    tmp[nx1] = v[cur];
    tmp[nx2] = v[nx1];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
    tmp = v;
    tmp[cur] = v[nx1];
    tmp[nx1] = v[cur];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
    tmp = v;
    tmp[cur] = v[nx2];
    tmp[nx2] = v[cur];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
    tmp = v;
    tmp[cur] = v[nx2];
    tmp[nx1] = v[cur];
    tmp[nx2] = v[nx1];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
    tmp = v;
    tmp[cur] = v[nx2];
    tmp[nx2] = v[cur];
    bf(cur + 1, nx1 + 2, nx2 + 2, tmp);
}

vector<int> persiapan(int n, vi a){
	nn = n;
    string s = "";
    for(auto x : a){
        s += to_string(x);
    }
    bf(0, 1, 2, s);
    vi v;
    for(int i = 0; i < n; i++){
//    	cout << anss[0][i] << " ";
    	int x = anss[i] - '0';
        v.pb(x);
    }
    return v;
}


int main() {
  int N;
  std::cin >> N;

  std::vector<int> X(N);
  for (int i = 0; i < N; i++) {
    std::cin >> X[i];
  }

  std::vector<int> Y = persiapan(N, X);
  for (auto y : Y) {
    std::cout << y << " ";
  }
  std::cout << std::endl;

  return 0;
}
