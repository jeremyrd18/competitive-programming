#include <bits/stdc++.h>
using namespace std;

bool hasPositiveVolumeIntersection(int a, int b, int c, int d, int e, int f, 
                                   int g, int h, int i, int j, int k, int l) {
    bool x_overlap = max(a, g) < min(d, j);
    bool y_overlap = max(b, h) < min(e, k);
    bool z_overlap = max(c, i) < min(f, l);
    return x_overlap && y_overlap && z_overlap;
}

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;
    if (hasPositiveVolumeIntersection(a, b, c, d, e, f, g, h, i, j, k, l)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
