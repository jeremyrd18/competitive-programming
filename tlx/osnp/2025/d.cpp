#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int ans = 0;
    bool leftmost = true;
    int cur_block = 0;
    vector<int> blocks;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B' && leftmost){
            ans++;
            continue;
        }
        else if(s[i] == 'B'){
            cur_block++;
        }
        else{
            blocks.push_back(cur_block);
            cur_block = 0;
        }
        leftmost = false;
    }

    if(cur_block > 0){
        ans += cur_block;
    }

    // We only can choose K - 1 blocks at maximum
    k--;
    sort(blocks.rbegin(), blocks.rend());
    for(int x : blocks){
        if(k == 0) break;
        ans += x;
        k--;
    }

    cout << ans << endl;

}

/*
If there are blocks in the left or right endpoints of the string, we will always take it
*/