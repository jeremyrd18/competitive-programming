#include <bits/stdc++.h>
using namespace std;
int n, a[200005], x;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        if(i >= x){
            a[i - x]++;
            a[i] = max(a[i - 1], a[i - x]);
        }
        else a[i] = a[i - 1];
    }
    printf("%d", n - a[n]);
}