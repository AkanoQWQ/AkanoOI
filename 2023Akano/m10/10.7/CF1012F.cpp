#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 24;
int n,p,maxs,s[MAXN],len[MAXN],t[MAXN],f[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i = 1;i <= n;i++){
		cin>>s[i]>>len[i]>>t[i];
	}
	maxs = (1<<n) - 1;
	for(int stat = 0;stat <= maxs;stat++){
		for(int i = 1;i <= n;i++){
			if(stat & (1<<(i-1)))continue;
			const int nxt = stat | (1<<(i-1));
			const int timeNxt = f[MAXN] + t[i] - 1;
			f[timespec]
		}
	}
	return not(Akano loves pure__Elysia);
}
