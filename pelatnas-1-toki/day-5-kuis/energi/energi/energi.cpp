#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;



double energi(int n, int k, int l, int r, vi a) {
  
}

int main() {
    int N, K, L, R;
    std::cin >> N >> K >> L >> R;
    
    std::vector<int> A(N);
    for(auto &a : A) {
        std::cin >> a;
    }

    double answer = energi(N, K, L, R, A);

    std::cout << std::fixed << std::setprecision(8) << answer << std::endl;
    return 0;
}