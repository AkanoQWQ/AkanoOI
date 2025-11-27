#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n,m;
ll c,s,e;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		s = e = 0;
		for(int i = 1;i <= n;i++){
			cin>>c;
			s += c;
		}
		for(int i = 1;i <= m;i++){
			cin>>c;
			e += c;
		}
		if(e > s){
			cout<<"Tenzing"<<endl;
		}else if(s > e){
			cout<<"Tsondu"<<endl;
		}else{
			cout<<"Draw"<<endl;
		}
	}
	return 0;
}

