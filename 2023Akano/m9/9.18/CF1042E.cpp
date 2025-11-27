#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
const int MOD = 998244353;
inline ll P(ll x){
	return x * x;
}
inline void GetMod(ll& x){
	x = ((x % MOD) + MOD) % MOD;
	return ; 
}
struct Point{
	ll x,y,val;
}p[MAXN];
int w,c,n,OBJX,OBJY,lst;
bool Cmp(Point p1,Point p2){
	if(p1.val != p2.val)return p1.val < p2.val;
	if(p1.x != p2.x)return p1.x < p2.x;
	return p1.y < p2.y;
}
ll sumx1[MAXN],sumx2[MAXN],sumy1[MAXN],sumy2[MAXN],sumf[MAXN];
ll f[MAXN],ans,inv[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>w>>c;
	for(int i = 1;i <= w;i++){
		for(int j = 1;j <= c;j++){
			p[++n] = {i,j,10181108};
			cin>>p[n].val;
		}
	}
	cin>>OBJX>>OBJY;
	inv[1] = 1;
	for(int i = 2;i <= n;i++){
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
	sort(p+1,p+n+1,Cmp);
	for(int i = 1;i <= n;i++){
		if(p[i].val != p[i-1].val)lst = i-1;
		f[i] += sumf[lst];
		f[i] += P(p[i].x) * (lst);
		f[i] += sumx2[lst];
		f[i] -= 2 * sumx1[lst] * p[i].x;
		f[i] += P(p[i].y) * (lst);
		f[i] += sumy2[lst];
		f[i] -= 2 * sumy1[lst] * p[i].y;
		GetMod(f[i]);
		if(lst != 0){
			f[i] = (f[i] * inv[lst]) % MOD;
		} 
		sumf[i] = sumf[i-1] + f[i];
		if(sumf[i] >= MOD)sumf[i] -= MOD;
		sumx1[i] = sumx1[i-1] + p[i].x;
		if(sumx1[i] >= MOD)sumx1[i] -= MOD;
		sumx2[i] = sumx2[i-1] + P(p[i].x);
		if(sumx2[i] >= MOD)sumx2[i] -= MOD;
		sumy1[i] = sumy1[i-1] + p[i].y;
		if(sumy1[i] >= MOD)sumy1[i] -= MOD;
		sumy2[i] = sumy2[i-1] + P(p[i].y);
		if(sumy2[i] >= MOD)sumy2[i] -= MOD;
		if(p[i].x == OBJX && p[i].y == OBJY){
			ans = f[i];
			break;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
