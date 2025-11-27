#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
int n,m,ans,a[MAXN],b[MAXN];
inline void Add(int u,int v){
	if(u > v)swap(u,v);
	for(int i = u;i < v;i++)a[i]++;
	return ;
}
inline void ReverseAdd(int u,int v){
	if(u > v)swap(u,v);
	for(int i = u-1;i >= 1;i--){
		b[i]++;
	}
	for(int i = n;i >= v;i--){
		b[i]++;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans += c / 2;
		c %= 2;
		if(c == 0)continue;
		Add(a,b);
		ReverseAdd(a,b);
	}
	return not(Akano loves pure__Elysia);
}

