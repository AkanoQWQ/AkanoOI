#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n == 3){
			cout<<-1<<endl;
			continue;
		}else if(n == 2){
			cout<<"2 1"<<endl;
			continue;
		}
		if(n % 2 == 0){
			for(int i = n;i >= 1;i--){
				cout<<i<<" ";
			}
			cout<<endl;
		}else{
			for(int i = n;i > (n-1)/2 + 1;i--){
				cout<<i<<" ";
			}
			for(int i = 1;i < n - (n-1)/2 + 1;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
5
10
9
2
7
3

*/
