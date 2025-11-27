#include<bits/stdc++.h>
using namespace std;
int t,n,a[106];
int main(){
	cin>>t;
	while(t--){
		bool FD = 1;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i = 1;i < n;i++){
			if(a[i] == a[i+1]){
				FD = 0;
				break;
			}
		}
		if(FD){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

