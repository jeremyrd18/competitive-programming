#include <bits/stdc++.h>
using namespace std;

void ans(int x, int y){
    cout << "! " << x << " " << y << endl;
}

int ask(int x, int y){
    cout << "? " << x << " " << y << endl;
    int jaw;
    cin >> jaw;
    return jaw;
}

int main(){
    int x = ask(2, 2);
    if(x == 0){
        x = ask(4, 4);
        if(x == 0){
            x = ask(4, 2);
            if(x == 1){
                x = ask(3, 2);
                if(x == 1){
                    x = ask(3, 1);
                    if(x == 1){
                        ans(3, 1);
                    }
                    else{
                        ans(3, 2);
                    }
                }
                else{
                    x = ask(5, 1);
                    if(x == 1){
                        ans(4, 1);
                    }
                    else{
                        ans(4, 2);
                    }
                }
            }
            else{
                x = ask(1, 4);
                if(x == 1){
                    x = ask(1, 3);
                    if(x == 1){
                        ans(1, 3);
                    }
                    else{
                        ans(1, 4);
                    }
                }
                else{
                    x = ask(3, 3);
                    if(x == 1){
                        ans(2, 3);
                    }
                    else{
                        ans(2, 4);
                    }
                }
            }
        }
        else{
            x = ask(3, 4);
            if(x == 1){
                x = ask(3, 3);
                if(x == 1){
                    ans(3,3);
                }
                else{
                    ans(3, 5);
                }
            }
            else{
                x = ask(5, 3);
                if(x == 1){
                    ans(4, 3);
                }
                else{
                    ans(4, 4);
                }
            }
        }
    }
    else{
        x = ask(2, 1);
        int y = ask(1, 2);
        if(x == 1 && y == 1){
            ans(1, 1);
        }
        else if(x == 1 && y == 0){
            ans(2, 1);
        }
        else if(x == 0 && y == 1){
            ans(1, 2);
        }
        else{
            ans(2, 2);
        }
    }
}