#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	bool isPesan=true;
	for(int i=0; i<n; i++){
		if (s[i]=='*'){
			isPesan=(!isPesan);
		}
		else if (isPesan) cout<<s[i];
	}
}