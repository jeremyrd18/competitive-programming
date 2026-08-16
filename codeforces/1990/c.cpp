#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find MAD in a given array
int findMAD(const vector<int>& arr) {
    unordered_map<int, int> freq;
    int mad = 0;
    for (int num : arr) {
        freq[num]++;
        if (freq[num] >= 2) {
            mad = max(mad, num);
        }
    }
    return mad;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sum = 0;
        while (true) {
            // Add the sum of the current array to sum
            for (int num : a) {
                sum += num;
            }

            // Calculate the new array based on MAD values
            vector<int> new_a(n, 0);
            for (int i = 0; i < n; i++) {
                vector<int> subarray(a.begin(), a.begin() + i + 1);
                new_a[i] = findMAD(subarray);
            }

            // Check if all elements are zero
            bool all_zero = true;
            for (int num : new_a) {
                if (num != 0) {
                    all_zero = false;
                    break;
                }
            }
            a = new_a;
            if (all_zero) break;
        }

        cout << sum << "\n";
    }

    return 0;
}
