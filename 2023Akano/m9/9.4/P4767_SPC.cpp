#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using uint = unsigned int;
const uint MAXN = 3002;
const uint MAXM = 302;
const uint INF = 1e9;
uint f[MAXN][MAXM],n,m,pos[MAXN],sump[MAXN];
inline uint GetP(uint l,uint r){
	if(l > r)return 0;
	return sump[r] - sump[l-1];
}
inline uint Value(int l,int r){
	uint ret = 0;
	const uint mid = (l + r) >> 1;
	ret = (mid - 1 - l + 1) * pos[mid] - GetP(l,mid-1);
	ret += GetP(mid+1,r) - (r - (mid+1) + 1) * pos[mid];
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(uint i = 1;i <= n;i++){
		cin>>pos[i];
		sump[i] = sump[i-1] + pos[i];
	}
	memset(f,0x7f,sizeof(f));
	f[0][0] = 0;
	for(uint i = 1;i <= n;i++){
		for(uint j = 1;j <= min(i,m);j++){
			for(uint k = 0;k < i;k++){
				f[i][j] = min(f[i][j],f[k][j-1] + Value(k+1,i));
			}
//			f[i][j] = min(f[i][j],f[i][j-1]);
		}
	}
	cout<<f[n][m];
	return not(Akano loves pure__Elysia);
}
