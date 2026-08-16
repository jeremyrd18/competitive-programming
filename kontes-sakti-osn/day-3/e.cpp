#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<pair<int,int>> v;
    int start=-1;
    set<int> st;
    for(int i=0;i<n;i++) {
        cin>>a[i+1];
        if(a[i+1]==0) start=i+1;
        v.push_back({a[i+1],i+1});
        st.insert(a[i+1]);
    }
    
    sort(v.rbegin(),v.rend());
    if(start!=-1){
        cout<<"YES"<<endl;
        //cout<<start<<endl;
    vector<pair<int,int>> pos(n+1);
    pos[start]={1,1};
    vector<pair<int,int>> vnew;
    for(auto x:v){
        if(x.second==start) continue;
        vnew.push_back(x);
    }
    int y=1;
    for(int i=2;i<=n;i++){
        auto p=vnew[i-2];
        int id=p.second,dis=p.first;
        //cout<<id<<' ';
        if(dis==0){
            pos[id]={i,y};
        }
        else{
            dis--;
            if(y-dis>=1) { pos[id]={i,y-dis}; y=y-dis; }
            else{ pos[id]={i,y+dis}; y=y+dis; }
        }
    }
    map<int,int> column,wizard;
    for(int i=1;i<=n;i++){
        cout<<pos[i].first<<' '<<pos[i].second<<endl;
        column[i]=pos[i].first;
        wizard[pos[i].first]=i;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) cout<<i<<' ';
        else{
            int x=column[i];
            x--;
            cout<<wizard[x]<<' ';
        }
    }
}
else {
    if(st.size()==n){
        if(n==2) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            vector<pair<int,int>> pos(n+1);
            for(int i=1;i<n-1;i++){
                auto p=v[i];
                int id=p.second;
                pos[id]={i+1,1};
            }
            pos[v[0].second]={n,2};
            pos[v[n-1].second]={1,1};
            int id1,id2,idn;
            for(int i=1;i<=n;i++){
                cout<<pos[i].first<<' '<<pos[i].second<<endl;
                if(pos[i].first==n) idn=i;
                if(pos[i].first==1) id1=i;
                if(pos[i].first==2) id2=i;
            }
            for(int i=1;i<=n;i++){
                if(a[i]==n) cout<<id1<<' ';
                else if(a[i]==1) cout<<id2<<' ';
                else cout<<idn<<' ';
            }
        }
    }
    else{
        cout<<"YES"<<endl;
        int partition;
        for(int i=0;i<n-1;i++){
            if(v[i].first==v[i+1].first){
                partition=i+2; break;
            }
        }
        vector<pair<int,int>> pos(n+1);
        pos[v[0].second]={1,1};
        int y=1;
        for(int i=2;i<=partition;i++){
            auto p=v[i-1];
            int id=p.second,dis=v[i-2].first;
            if(dis==0){
                pos[id]={i,y};
            }
            else{
                dis--;
                if(y-dis>=1) { pos[id]={i,y-dis}; y=y-dis; }
                else{ pos[id]={i,y+dis}; y=y+dis; }
            }
        }
        for(int i=partition+1;i<=n;i++){
            auto p=v[i-1];
            int id=p.second,dis=p.first;
            if(dis==0){
                pos[id]={i,y};
            }
            else{
                dis--;
                if(y-dis>=1) { pos[id]={i,y-dis}; y=y-dis; }
                else{ pos[id]={i,y+dis}; y=y+dis; }
            }
        }
        map<ll,ll> wizard,column;
        for(int i=1;i<=n;i++){
            cout<<pos[i].first<<' '<<pos[i].second<<endl;
            wizard[pos[i].first]=i;
            column[i]=pos[i].first;
        }
        for(int i=1;i<=n;i++){
            int x=column[i];
            if(x<partition){
                x++;
                cout<<wizard[x]<<' ';
            }
            else{
                x--; cout<<wizard[x]<<' ';
            }
        }
    }
}
 
 
}