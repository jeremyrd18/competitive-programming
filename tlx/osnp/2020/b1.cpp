#include<bits/stdc++.h>
using namespace std;
void fillPrefixSum(int patok[], int n, int prefixSum[])
{
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + patok[i];
}

int main(){
    int N, K;
    cin>>N>>K;
    int patok[N];
    int prefixSum[N];
    for (int i=1; i<=N; i++){
        cin>>patok[i];
    }
    fillPrefixSum(patok,N,prefixSum);
    for(int i=0; i<K; i++){
        int x;
        cin>>x;
        int l=1;
        int r= N;
        int mid;
        int ans=0;
        while (l<=r){
            mid = (l+r)/2;
            if (prefixSum[mid]<=x){
                ans = mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
            
        }
        cout<<ans<<endl;;
    }
}