#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 106;
const int MAXVAL = 1e6 + 1018 + 1108;
int T,n,a[MAXN],tot;
bitset<MAXVAL / 4> f[4][2];//第i个半圆,当前是奇/偶
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("track/track1.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>n;
		tot = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			tot += a[i];
		}
		f[0][0][0] = true;
		for(int i = 1;i <= n;i++){
			for(int j = 3;j >= 0;j--){
				f[j]
			}
		}
		bool OK = false;
		if(n % 2 == 0){
			if(f[n/2][tot/2] == true)OK = true;
		}else{
			if(f[(n/2)][tot/2] == true)OK = true;
			if(f[(n/2)+1][tot/2] == true)OK = true;
		}
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No!!!!!!!!!!!!!!!!"<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
