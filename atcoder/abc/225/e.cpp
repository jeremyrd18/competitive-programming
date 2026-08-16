#include <bits/stdc++.h>
using namespace std;

bool cmp(const vector<long long>& a, const vector<long long>& b) {
    long long dy_a = a[1], dx_a = a[0] - 1;
    long long dy_b = b[1], dx_b = b[0] - 1;
    return dy_a * dx_b < dy_b * dx_a;
}

int main() {
    int n;
    cin >> n;


    vector<vector<long long>> points(n, vector<long long>(2));
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    sort(points.begin(), points.end(), cmp);

    int count = 0;
    long long last_dy = -1, last_dx = 1;

    for (int i = 0; i < n; ++i) {
        // Ujung Start (L_i) dari angka 7 ke-i:
        // L_i = (y - 1) / x
        long long L_dy = points[i][1] - 1;
        long long L_dx = points[i][0];

        // Cek apakah last_R <= L_i
        // (last_dy / last_dx) <= (L_dy / L_dx)  <=>  last_dy * L_dx <= L_dy * last_dx
        if (last_dy * L_dx <= L_dy * last_dx) {
            count++;
            // Update last_R dengan R_i = y / (x - 1)
            last_dy = points[i][1];
            last_dx = points[i][0] - 1;
        }
    }

    cout << count << "\n";

    return 0;
}