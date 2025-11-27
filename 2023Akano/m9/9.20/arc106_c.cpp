#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int n,m,now = 2;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m == 0){
		for(int i = 1;i <= n;i++){
			cout<<now+1<<" "<<now+2<<endl;//²îµãUBÁË 
			now += 2;
		}
		return 0;
	}
	if(m < 0 || (m+1 >= n)){
		cout<<-1<<endl;
		return 0;
	}
	m++;
	cout<<1<<" "<<int(1e8)<<endl;
	n--;
	while(m){
		cout<<now<<" "<<now+1<<endl;
		now += 2;
		m--,n--;
	}
	now = 2e8;
	while(n){
		cout<<now<<" "<<now+1<<endl;
		now += 2;
		n--;
	}
	return not(Akano loves pure__Elysia);
}
