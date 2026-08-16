#include "kucing.h"

#include <iostream>
#include <vector>
#include <iomanip>

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
