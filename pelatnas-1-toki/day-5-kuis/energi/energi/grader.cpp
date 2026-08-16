#include "energi.h"

#include <iostream>
#include <vector>
#include <iomanip>

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