#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 314;
const int INF = 1e9;
int f[MAXN][MAXN][MAXN],g[MAXN][MAXN],price[MAXN],fuel[MAXN],n,h,x[MAXN],dis[MAXN];
inline void ReadIn(){
	cin>>n>>h;
	for(int i = 1;i <= n;i++){
		cin>>x[i];
		dis[i-1] = x[i] - x[i-1];
	}
	for(int i = 1;i < n;i++){
		cin>>price[i]>>fuel[i];
	}
	for(int i = 0;i <= n+1;i++){
		for(int a = 0;a <= h;a++){
			for(int b = 0;b <= h;b++){
				f[i][a][b] = INF;
			}
		}
	}
	return ;
}
inline int Solve(){
	int ans = INF;
	if(dis[0] <= h){
		for(int a = 0;a <= h-dis[0];a++){
			for(int b = dis[0];b <= h;b++){
				f[1][a][b] = 0;
			}
		}
	}else{
		return -1;
	}
	for(int i = 1;i < n;i++){
		memcpy(g,f[i],sizeof(g));
		for(int a = h;a >= 0;a--){//逆序防止累加
			for(int b = 0;b <= h;b++){
				const int obja = min(a + fuel[i],h);
				g[obja][b] = min(g[obja][b],f[i][a][b] + price[i]);
			}
		}
		for(int a = 0;a <= h;a++){
			for(int b = h;b >= 0;b--){
				const int objb = max(b - fuel[i],0);
				g[a][objb] = min(g[a][objb],f[i][a][b] + price[i]);
			}
		}
		memcpy(f[i],g,sizeof(g));
		for(int a = dis[i];a <= h;a++){//a : 还剩多少油
			for(int b = 0;b <= h-dis[i];b++){//b : 还剩多少油
				f[i+1][a - dis[i]][b + dis[i]] = min(f[i+1][a - dis[i]][b + dis[i]],f[i][a][b]);
			}
		}
	}
	for(int a = 0;a <= h;a++){
		for(int b = 0;b <= a;b++){
			ans = min(ans,f[n][a][b]);
		}
	}
	if(ans >= INF)ans = -1;
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	cout<<Solve()<<endl;
	return not(Akano loves pure__Elysia);
}
