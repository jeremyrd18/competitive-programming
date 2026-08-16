#include <iostream>
#include <string>
using namespace std;

int countDirectionChanges(const string& combination) {
    if (combination.length() <= 1) return 0;
    int changes = 0;
    bool kiri = true;
    for (int i = 1; i < combination.length(); ++i) {
        int prev = combination[i-1] - '0';
        int cur = combination[i] - '0';
        // cout << prev << " " << cur << endl;
        if(cur > prev){
            if(abs(cur - prev) <= 5){
                if(abs(cur - prev) == 5) continue;
                if(kiri){
                    continue;
                }
                kiri = 1;
                changes++;
            }
        }
        else{
            int awal = 10 - prev;
            if(awal + cur <= 5){
                if(awal + cur == 5) continue;
                if(!kiri){
                    kiri = 1;
                    changes++;
                }
            }
            else{
                if(!kiri) continue;
                kiri = 0;
                changes++;
            }
        }
    }
    return changes;
}

int main() {
    string input;
    cin >> input;
    int result = countDirectionChanges(input);
    cout << result << endl;
}
