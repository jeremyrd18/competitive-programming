#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

struct Point {
 
    int x, y;
 
    bool operator<(Point p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int cross(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

void solve(){
    vector<Point> points, upper, lower;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int xx, yy;
        cin >> xx >> yy;
        Point pt;
        pt.x = xx;
        pt.y = yy;
        points.pb(pt);
    }
    
    sort(points.begin(), points.end());
    for(Point p : points){
        while(upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), p) >= 0){
            upper.pop_back();
        }
        upper.pb(p);
    }
    for(Point p : points){
        while(lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), p) <= 0){
            lower.pop_back();
        }
        lower.pb(p);
    }
    for(auto v : upper){
        cout << v.x << " " << v.y << endl;
    } cout << endl;
    for(auto v : lower){
        cout << v.x << " " << v.y << endl;
    }
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}