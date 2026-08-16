#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue <vector<int> > pq;
    pq.push({1, 2, 3, 4});
    pq.push({190});
    pq.push({999, 45});
    while(!pq.empty()){
        for(auto x : pq.top()){
            cout << x << " ";
        }
        cout << endl;
        pq.pop();
    }
}