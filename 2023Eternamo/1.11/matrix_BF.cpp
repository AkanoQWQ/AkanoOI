#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 1006;
int n,m,r,c,a[MAXN][MAXN],pos,ans;
int ksm(int aa,int b){
	int ret = 1;
	while(b){
		if(b & 1)ret = (1ll * ret * aa) % MOD;
		aa = (1ll * aa * aa) % MOD;
		b >>= 1;
	}
	return ret;
}
int divv(int aa,int b){
	return (1ll * aa * ksm(b,MOD-2)) % MOD;
}
int sq(int aa){
	return (1ll * aa * aa) % MOD;
}
int gcd(int aa,int b){
	if(b == 0)return aa;
	return gcd(b,aa % b);
}
void dfs(int x,int y,int poss,int value){
	queue<pair<int,int> > q;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] < a[x][y]){
				q.push(make_pair(i,j));
				++cnt;
			}
		}
	}
	if(cnt == 0){
		ans = (ans + divv(value,poss)) % MOD;
		return ;
	}
	while(!q.empty()){
		const int OX = q.front().first,OY = q.front().second;
		dfs(OX,OY,poss*cnt,(value + sq(x-OX) + sq(y-OY))%MOD);
		q.pop();
	}
	return ;
}
signed main(){
	//freopen("matrix.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&r,&c);
	dfs(r,c,1,0);
	printf("%d",(1ll*ans+MOD)%MOD);
	return 0;
}
