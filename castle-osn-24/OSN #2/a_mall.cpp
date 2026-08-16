#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> P(N);
    for(int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    
    std::set<std::vector<int>> unique_orders;
    
    for(int i = 0; i <= N - K; i++) {
        std::vector<int> current_order = P;
        std::sort(current_order.begin() + i, current_order.begin() + i + K);
        unique_orders.insert(current_order);
    }
    
    std::cout << unique_orders.size() << std::endl;
    
    return 0;
}
