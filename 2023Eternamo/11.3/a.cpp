#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
int T,x,y,k;
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>x>>y>>k;
		if(y <= x){
			cout<<x<<endl;
		}else{
			int newx = min(y,x + k);
			int cost = newx - x;
			cout<<x + cost + 2 * (y-newx)<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
