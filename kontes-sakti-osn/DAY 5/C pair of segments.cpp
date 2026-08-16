#include<bits/stdc++.h>
#define int long long
 
using namespace std;
const int N = 5500;
int n , m;
int last[N] , f[N];
pair<int,int> p[N]; 
 
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++){
        int a , b; 
        cin >> a >> b; 
        p[i] = {b , a}; 
    }
    
    sort(p + 1 , p + 1 + n); 
    
    for(int i = 1; i <= n; i ++){
        auto [r , l] = p[i];
        last[i] = 0 , f[i] = 0; 
        for(int j = i - 1; j >= 1; j --){
            auto [b , a] = p[j]; 
            if(l > b){
                last[i] = j;
                break;
            }
        }
    }

    for(int i = 1 ; i <= n ; i ++){
        auto [r , l] = p[i] ;  
        f[i] = f[i - 1] ; 
        for(int j = i - 1 ; j >= 1 ; j --){
            auto [b , a] = p[j] ; 
            int c = min(last[i] , last[j]) ; 
            if(l <= b)f[i] = max(f[i] , f[c] + 1) ; 
        }
    }
    
    cout << n - (f[n] * 2) << endl ; 
}
 
signed main(){
  int t ; 
  cin >> t ; 
  while(t --)
    solve() ; 
}