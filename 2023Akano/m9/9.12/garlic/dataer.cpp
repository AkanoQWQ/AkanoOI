#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e6 + 1018 + 1108;
int n,x,arr[MAXN];
inline void Solve(){
	cin>>n>>x;
	for(int i = 1;i <= n;i++)cin>>arr[i];
	int ret = 0;
	for(int l = 1;l <= n;l++){
		int mn = 1e9,mx = 0;
		for(int r = l;r <= n;r++){
			mn = min(mn,arr[r]),mx = max(mx,arr[r]);
			if(mn + mx == x)ret++;
		}
	}
	cout<<ret<<endl;
}
Rander rd;
const int MAXVAL = 108;
const int nn = 1e5;
inline void Make(){
	cout<<nn<<" "<<rd(1,MAXVAL)<<endl;
	for(int i = 1;i <= nn;i++){
		cout<<rd(1,MAXVAL)<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	MakeData("garlic",1,5,Make,Solve);
	return not(Akano loves pure__Elysia);
}
