//
#include <bits/stdc++.h>
using namespace std;
#define int long long

int MOD = 1e9 + 7;

void solve(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int idx, length, rounds, min_diff;
        cin >> length >> rounds >> min_diff;
        vector<int> array;
        for(idx = 0; idx < rounds; idx++){
            int x;
            cin >> x;
            array.push_back(x);
        }
        sort(array.begin(), array.end());
        vector<pair<int,int>>type1,type2;
        int count=0,totalpts=rounds;
 
        if(length==4){
            if(rounds+min_diff>2)cout<<"2"<<endl;
            else {
                if(array[1]-array[0]==2)cout<<"2"<<endl;
                else cout<<"0"<<endl;
            }
        }
        else {
        for(idx = 0; idx < rounds-1; idx++){
            int difference = array[idx+1]-array[idx];
            if(difference==2){
                count++;
            }
            else{
                if(difference%2){
                    type2.push_back({difference/2,difference/2});
                }
                else{
                    type1.push_back({difference/2,difference/2-1});
                }
            }
        }
            int range=array[0]-array[rounds-1]+length;
            if(range==2)count++;
            else if(range%2){
                type2.push_back({range/2,range/2});
            }
            else{
                type1.push_back({range/2,range/2-1});
            }
        sort(type2.begin(),type2.end());
        sort(type1.begin(),type1.end());
 
        int sz1=type1.size(),sz2=type2.size();
 
        for(idx = 0; idx < sz1; idx++){
            if(min_diff>0){
                if(min_diff>=type1[idx].second){
                    count+=type1[idx].first;
                    min_diff-=type1[idx].second;
                    totalpts+=type1[idx].second;
                }
                else{
                    count+=min_diff;
                    totalpts+=min_diff;
                    min_diff=0;
                }
            }
            else{
                break;
            }
        }
        for(idx = 0; idx < sz2; idx++){
            if(min_diff>0){
                if(min_diff>=type2[idx].second){
                    count+=type2[idx].first;
                    min_diff-=type2[idx].second;
                    totalpts+=type2[idx].second;
                }
                else{
                    count+=min_diff;
                    totalpts+=min_diff;
                    min_diff=0;
                }
            }
            else{
                break;
            }
        }
        if(totalpts>2)
        count+=totalpts-2;
        cout<<count<<endl;
        }
    }
}

signed main(){
	int test_cases;
    test_cases = 1;
    for(int idx = 1; idx<=test_cases; idx++){
        solve();
    }
}