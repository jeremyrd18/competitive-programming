#include <bits/stdc++.h>
using namespace std;
int main(){
	long long A,B,C;
	cin>>A>>B>>C;
	long long X;
	cin>>X;
	long long rray[X-1];
	for (int i=0; i<X; i++){
		cin>>rray[i];
	}
	for (int j=0;j<X;j++){
		if(rray[j]%A==0&&rray[j]%B==0&&rray[j]%C==0){
			cout<<"YA"<<endl;
		}
		else{
			cout<<"TIDAK"<<endl;
		}
	}
}