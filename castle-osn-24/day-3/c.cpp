#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 20;

bool canTransform(vector<int>& A, vector<int>& B, vector<int>& L) {
    int N = A.size();
    for (int k = 0; k < L.size(); ++k) {
        int Lk = L[k];
        int max_idx = -1, max_value = -1;
        for (int i = 0; i <= N - Lk; ++i) {
            int current_max = -1;
            for (int j = i; j < i + Lk; ++j) {
                if (A[j] > current_max) {
                    current_max = A[j];
                    max_idx = j;
                    max_value = current_max;
                }
            }
        }
        
        if (max_idx == -1) return false; // Should not happen, just for safety
        A.erase(A.begin() + max_idx);
    }
    
    return A == B;
}

void solveTestCase() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> A(N), B(M), L(K);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < K; ++i) {
        cin >> L[i];
    }
    
    // Generate all permutations of A
    vector<int> original_A = A;
    sort(original_A.begin(), original_A.end());
    bool possible = false;
    
    do {
        if (canTransform(original_A, B, L)) {
            possible = true;
            break;
        }
    } while (next_permutation(original_A.begin(), original_A.end()));
    
    if (possible) {
        cout << "ya" << endl;
    } else {
        cout << "tidak" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solveTestCase();
    }
    return 0;
}
