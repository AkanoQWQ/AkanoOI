#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108 + 1000;
const int MAXM = 2006;
const int INF = 1e9;
int f[MAXN][MAXM],n,m,pos[MAXN],sump[MAXN],value[MAXN][MAXN],best[MAXN][MAXN];
inline int GetP(int l,int r){
	if(l > r)return 0;
	return sump[r] - sump[l-1];
}
inline int Value(int l,int r){
	const int mid = (l + r) >> 1;
	int ret = 0;
	for(int i = l;i <= r;i++){
		ret += abs(pos[mid] - pos[i]);
	}
	return ret;
}
inline int Value2(int l,int r){
	const int mid = (l + r) >> 1;
	int ret = 0;
	for(int i = l;i < mid;i++){
		ret += pos[mid] - pos[i];
	}
	for(int i = mid+1;i <= r;i++){
		ret += pos[i] - pos[mid];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>pos[i];
	}
	sort(pos+1,pos+n+1);//BSOJ √ª≈≈–Ú 
	for(int i = 1;i <= n;i++){
		sump[i] = sump[i-1] + pos[i];
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			f[i][j] = INF;
		}
	}
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			const int mid = (i + j) >> 1;
			value[i][j] = (mid - 1 - i + 1) * pos[mid] - GetP(i,mid-1);
			value[i][j] += GetP(mid+1,j) - (j - (mid+1) + 1) * pos[mid];
		}
	}
	for(int j = 1;j <= m;j++){
		best[n+1][j] = n;
		for(int i = n;i >= 1;i--){
			int ans = INF;
			for(int k = best[i][j-1];k <= best[i+1][j];k++){
				if(f[k][j-1] + value[k+1][i] < f[i][j]){
					f[i][j] = f[k][j-1] + value[k+1][i];
					best[i][j] = k;
				}
			}
			f[i][j] = min(f[i][j],f[i][j-1]);
		}
	}
	cout<<f[n][m]<<endl;
	return not(Akano loves pure__Elysia);
}
