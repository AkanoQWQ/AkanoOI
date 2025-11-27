#include<bits/stdc++.h>
using namespace std;
int n,nx,ny,x,y,t,nt;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>t>>x>>y;
		const int usedtime = abs(x - nx) + abs(y - ny);
		if(usedtime <= t-nt && (t-nt-usedtime) % 2 == 0){
			nx = x,ny = y,nt = t;
		}else{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}

