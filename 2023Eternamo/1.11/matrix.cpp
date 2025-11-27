#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
const int MAXN = 1006;
int n,m,r,c,a[MAXN][MAXN],cnt,lstn = -1,ans,pos,level_sum[MAXN*MAXN],point_poss[MAXN*MAXN];
struct node{
	int x,y,v;
}nd[MAXN*MAXN];
struct levels{
	int x,y,sum,x2,y2;
}level[MAXN*MAXN];
bool cmp(node na,node nb){
	return na.v < nb.v;
}
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
signed main(){
	freopen("matrix.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&a[i][j]);
			nd[++cnt].x = i,nd[cnt].y = j,nd[cnt].v = a[i][j];
		}
	}
	scanf("%d%d",&r,&c);
	sort(nd+1,nd+n*m+1,cmp);
	cnt = 0;
	for(int i = 1;i <= n*m;i++){
		cout<<nd[i].v<<","<<nd[i].x<<","<<nd[i].y<<endl;;
	}
	cout<<endl;
	for(int i = 1;i <= n*m;i++){
		if(nd[i].v != lstn){
			level[cnt].x = divv(level[cnt].x,level[cnt].sum);
			level[cnt].y = divv(level[cnt].y,level[cnt].sum);
			level[cnt].x2 = divv(level[cnt].x2,level[cnt].sum);
			level[cnt].y2 = divv(level[cnt].y2,level[cnt].sum);
			lstn = nd[i].v;
			++cnt;	
		}
		level[cnt].x += nd[i].x,level[cnt].y += nd[i].y;
		level[cnt].x2 += sq(nd[i].x),level[cnt].y2 += sq(nd[i].y);
		level[cnt].x2 %= MOD,level[cnt].y2 %= MOD;
		level[cnt].x %= MOD,level[cnt].y %= MOD;
		level[cnt].sum++;
		a[nd[i].x][nd[i].y] = cnt;
	}
	level[cnt].x = divv(level[cnt].x,level[cnt].sum);
	level[cnt].y = divv(level[cnt].y,level[cnt].sum);
	level[cnt].x2 = divv(level[cnt].x2,level[cnt].sum);
	level[cnt].y2 = divv(level[cnt].y2,level[cnt].sum);
	for(int i = 1;i <= cnt;i++){
		level_sum[i] = level_sum[i-1] + level[i].sum;
	}
	for(int i = 1;i <= cnt;i++){
		cout<<level[i].x<<","<<level[i].y<<" | "<<level[i].x2<<","<<level[i].y2<<endl;;
	}
	cout<<divv(1,3)<<"!!!"<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<a[i][j]<<" ";
		} 
		cout<<endl;
	}
/*	pos = a[r][c];
	while(pos > 1){
		ans = ((1ll * ans + level[pos-1].x2 + level[pos-1].y2 + level[pos].x2 + level[pos].y2 - 2ll * (1ll * level[pos].x * level[pos-1].x + level[pos].y * level[pos-1].y)) + MOD) % MOD;
		pos--;
	}*/
	point_poss[a[r][c]] = 1;
	for(pos = a[r][c];pos > 1;pos--){
		cout<<"POINT POSS OF "<<pos<<" is "<<point_poss[pos]<<endl;
		for(int p2 = pos - 1;p2 >= 1;p2--){
			const int addd = (((1ll * level[p2].x2 + level[p2].y2)%MOD) + ((level[pos].x2 + level[pos].y2)%MOD) - ((2ll * (1ll * level[pos].x * level[p2].x + level[pos].y * level[p2].y)) % MOD)) % MOD;
			const int nposs = divv(level[p2].sum,level_sum[pos-1]);
			const int real_add = (addd * nposs * point_poss[pos]) % MOD;
			ans = (1ll * ans + real_add + MOD) % MOD;
			cout<<pos<<" to "<<p2<<" "<<level[p2].sum<<"/ "<<level_sum[pos-1]<<" add "<<real_add<<" !!! "<<(1ll * level[pos].x * level[p2].x + level[pos].y * level[p2].y)<<endl;
			cout<<addd<<" * "<<nposs<<endl;
			point_poss[p2] = (point_poss[p2] + nposs * point_poss[pos]) % MOD;
		}
	}
	cout<<(ans+MOD) % MOD;
	return 0;
}
