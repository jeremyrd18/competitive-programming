// Source: https://usaco.guide/general/io
// gunakan secret number
#include <bits/stdc++.h>
using namespace std;

bool debug = false;
int secret;

string ask(vector<int> numbers){
    cout << numbers.size() << " ";
    for(int i: numbers) cout << i << " ";
    cout << endl;

    string jaw;
    if (!debug){
        cin >> jaw;
    }
    else {
        for(int i: numbers){
            if(secret == i) {
                jaw = "YA";
                cout << jaw << endl;
                return jaw;
            }
        }
        for(int i: numbers){
            if(abs(secret-i) == 1) {
                jaw = "BISAJADI";
                cout << jaw << endl;
                return jaw;
            }
        }
        cout << "TIDAK" << endl;
        return "TIDAK";
    }
    return jaw;
}

int main() {
    if(debug){
        cin >> secret;
    }
	int n; 
    cin >> n;
    int lo = 1, hi = n;
    int ans = 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        vector<int> numbers;
        for(int i=lo; i<=mid; i++){
            numbers.push_back(i);
        }

        string jaw = ask(numbers);
        if(jaw == "YA"){
            ans = mid;
            hi = mid-1;
        }
        else if(jaw == "BISAJADI"){
            cout << "0 " << mid+1 << endl;
            return 0;
        }
        else {
            lo = mid+1;
        }
    }
    
    cout << 0 << " " << ans << endl;
}

// https://replit.com/@ArnoldArdianto/SecretGiantSweepsoftware?v=1