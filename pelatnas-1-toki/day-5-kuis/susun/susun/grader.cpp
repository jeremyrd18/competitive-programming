#include "susun.h"

#include <iostream>
#include <vector>

int main() {
  int A, B, C, D;
  std::cin >> A >> B >> C >> D;
  std::vector<std::vector<int>> hasil = susunKotak(A, B, C, D);
  std::cout << hasil.size() << " " << hasil[0].size() << "\n";
  for (const auto &baris : hasil) {
    for (const auto &elemen : baris) {
      std::cout << elemen << " ";
    }
    std::cout << "\n";
  }
  return 0;
}