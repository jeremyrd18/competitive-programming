#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int B[N];
    for (int i=0; i<N; i++){
        cin>>B[i];
    }
    vector<int> x;
    x.push_back(B[0]);
    int ans=1;
    for(int i=1; i<N; i++){
            int l=0;
            int r=x.size()-1;
            int ans=-1;
            while (l<=r){
                int mid=(l+r)/2;
                if (x[mid]>=B[i]){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if (ans==-1){
                x.push_back(B[i]);
            }
            else {
                x[ans]=B[i];
            }
    }
    cout<<x.size()<<endl;
}