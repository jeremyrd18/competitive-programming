#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int x, int y){
    cout << "? " << x << " " << y << endl;
    int temp;
    cin >> temp;
    return temp;
}

void sub1_2(){
    int n, q;
    cin >> n >> q;
    vector<int> a;
    for(int i = 1; i <= n; i++){
        a.push_back(query(1, i));
    }
    cout << "! ";
    for(int v : a){
        cout << v << " ";
    }
    cout << endl;
}

void sub3(){
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 3);
    int last2 = 0; bool b2 = 0;
    int last1 = 0; bool b1 = 0;
    int last = 0;
    bool skibidi = 0;
    ans[0] = 3;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            ans[1] = 1;
            last = i;
            continue;
        }
        int x = query(last,i);
        if(x == 1){
        	ans[i] = ans[i - 1];
        	last = i;
        	continue;
		}
        if(x == 2){
        	if(b1 == 0){
        		b1 = 1;
        		ans[i] = 2;
        		last1 = last;
        		last = i;
			}
			else{
				if(query(last1, i) == 2){
					ans[i] = ans[last1];
					last1 = last;
					last = i;
				}
				else{
					if(b2 == 0){
						b2 = 1;
						ans[i] = 3;
						last2 = last1;
						last1 = last;
						last = i;
					}
					else{
						ans[i] = ans[last2];
						last2 = last1;
						last1 = last;
						last = i;
					}
				}
			}
		}
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
	}
    cout << endl;
}

void sub4(){
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 3);
    int last3 = 0, b3 = 0;
    int last2 = 0, b2 = 0;
    int last1 = 0, b1 = 0;
    int last = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            ans[1] = 1;
            last = i;
            continue;
        }
        if(b3 == 1){
            int x = query(last1, i);
            if(x == 2){
                int y = query(last, i);
                if(y == 2){
                    ans[i] = ans[last1];
                    last3 = last2;
                    last2 = last1;
                    last1 = last;
                    last = i;
                }
                else{
                    ans[i] = ans[i - 1];
                }
            }
            else{
                int y = query(last2, i);
                if(y == 3){
                    ans[i] = ans[last2];
                    last2 = last1;
                    last1 = last;
                    last = i;
                }
                else{
                    ans[i] = ans[last3];
                    last3 = last2;
                    last2 = last1;
                    last1 = last;
                    last = i;
                }
            }
            continue;
        }
        int x = query(last,i);
        if(x == 1){
        	ans[i] = ans[i - 1];
        	last = i;
        	continue;
		}
        if(x == 2){
        	if(b1 == 0){
        		b1 = 1;
        		ans[i] = 2;
        		last1 = last;
        		last = i;
			}
			else{
				if(query(last1, i) == 2){
					ans[i] = ans[last1];
					last1 = last;
					last = i;
				}
				else{
					if(b2 == 0){
						b2 = 1;
						ans[i] = 3;
						last2 = last1;
						last1 = last;
						last = i;
					}
					else{
                        if(query(last2, i) == 3){
                            ans[i] = ans[last2];
                            last2 = last1;
                            last1 = last;
                            last = i;
                        }
						else{
                            if(b3 == 0){
                                b3 = 1;
                                ans[i] = 4;
                                last3 = last2;
                                last2 = last1;
                                last1 = last;
                                last = i;
                            }
                        }
					}
				}
			}
		}
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
	}
    cout << endl;
}

void sub5(){
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 3);
    int last = 1;
    ans[1] = 1;
    bool beda = 0;
    int idx;
    for(int i = 2; i <= n; i++){
    	int x = query(1, i);
    	if(x == last + 1){
    		ans[i] = i;
    		last = i;
		}
		else{
			beda = 1;
			idx = i;
			break;
		}
	}
//	
	if(!beda){
		cout << "! ";
		for(int i = 1; i <= n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}	
	else{
		int wow = idx - 1;
		for(int i = 2; i <= idx; i++){
			int x = query(i, idx);
			if(x == wow - 1){
				wow--;
			}
			else{
				ans[idx] = ans[i - 1];
				break;
			}
		}
		for(int i = idx + 1; i <= n; i++){
//			int x = query(1, i);
    		ans[i] = i - 1;
		}
	}
	cout << "! ";
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
	}
    cout << endl;
}

void subf(){
    int n, q;
    cin >> n >> q;
    vector<int> ans(n + 3);
    int cnt = 1;
    ans[1] = 1;
    for(int i = 2; i <= n; i++){
        int dist[n + 3];
        int l = 1, r = cnt + 1, idx = 1;
        while(l < r){
            memset(dist, 0, sizeof dist);
            int mid = (l + r)/2;
            int tmp = 0;
            for(int j = i - 1; j >= 1; j--){
                if(dist[ans[j]] == 0){
                    dist[ans[j]] = 1;
                    tmp++;
                }
                if(tmp == mid){
                    idx = j;
                    break;
                }
            }
            if(query(idx, i) == mid){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(l == cnt + 1){
            cnt++;
            ans[i] = cnt;
        }
        else{
            int tmp = 0;
            memset(dist, 0, sizeof dist);
            for(int j = i - 1; j >= 0; j--){
            	if(!dist[ans[j]]){
            		tmp++;
            		dist[ans[j]] = 1;
				}
				if(tmp == l){
					ans[i] = ans[j];
					break;
				}
			}
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
	}
    cout << endl;
}

signed main(){
    int t;
    cin >> t;
    if(t == 1 || t == 2){
        sub1_2();
    }
    else if(t == 3){
        sub3();
    }
    else if(t == 4){
        sub4();
    }
    else if(t == 5){
        sub5();
    }
    else{
    	subf();
	}
}