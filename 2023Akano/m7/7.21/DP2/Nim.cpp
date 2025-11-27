#include<bits/stdc++.h>
using namespace std;
int t,n,c,s;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		s = 0;
		cin>>n;
		while(n--){
			cin>>c;
			s ^= c;
		}
		if(s){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

