#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string K;
	string huruf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int jumlahHuruf[26];
	memset(jumlahHuruf, 0, sizeof jumlahHuruf);
	cin>>N>>K;
	
	for(int i=0; i<N; i++){
		for (int j=0; j<26;j++){
			if(K[i]==huruf[j]){
				jumlahHuruf[j]++;
			}
		}
	
	}
	int n = sizeof(jumlahHuruf)/sizeof(jumlahHuruf[0]);
	sort(jumlahHuruf, jumlahHuruf+n, greater<int>());
	if (jumlahHuruf[2]<=0){
		cout<<-1;
	}
	else{
	if (jumlahHuruf[0]==jumlahHuruf[1]&&jumlahHuruf[1]==jumlahHuruf[2]){
		cout<<jumlahHuruf[0]*3;
	}
	else if (jumlahHuruf[1]==jumlahHuruf[2]){
		cout<<jumlahHuruf[2]*3+1;
	}
	else cout<<jumlahHuruf[2]*3+2;
}
}


//hitung berapa kali tiap char