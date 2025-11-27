#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 200006;
int t[4*MAXN],a[MAXN],b[4*MAXN],c[4*MAXN];
int n,m,MOD;
void push_up(int p){
	t[p] = t[p*2] + t[p*2+1];
	t[p] %= MOD;
	return ;
}
void push_down(int p,int l,int mid,int r){//儿子的值=此刻儿子的值*爸爸的乘法lazytag+儿子的区间长度*爸爸的加法lazytag
	t[p*2] = (t[p*2] * c[p] + (mid-l+1) * b[p])%MOD;
	t[p*2+1] = (t[p*2+1] * c[p] + (r-mid) * b[p])%MOD;
	c[p*2] *= c[p],c[p*2+1] *= c[p];
	c[p*2] %= MOD,c[p*2+1] %= MOD;
	b[p*2] = (b[p*2] * c[p] + b[p]) % MOD;
	b[p*2+1] = (b[p*2+1] * c[p] + b[p]) % MOD;
	b[p*2] %= MOD,b[p*2+1] %= MOD;
	b[p] = 0;
	c[p] = 1;
	return ;
}
void Build(int l,int r,int p){
	if(l == r){
		t[p] = a[l] % MOD;
		return ;
	}
	c[p] = 1;
	int mid = (l + r) >> 1;
	Build(l,mid,p*2);
	Build(mid+1,r,p*2+1);
	push_up(p);
	return ;
}
void Update_Times(int l,int r,int objl,int objr,int p,int v){
	int mid = (l+r)>>1;
	if(objl <= l && r <= objr){
		push_down(p,l,mid,r);
		t[p] *= v;
		t[p] %= MOD;
		c[p] = (c[p] * v) % MOD;
		return ;
	}
	if(l != r)push_down(p,l,mid,r);
	if(mid >= objl)Update_Times(l,mid,objl,objr,p*2,v);
	if(mid < objr)Update_Times(mid+1,r,objl,objr,p*2+1,v);
	push_up(p);
	return ;
}
void Update_Plus(int l,int r,int objl,int objr,int p,int v){
	int mid = (l+r)>>1;
	if(objl <= l && r <= objr){
		push_down(p,l,mid,r);
		t[p] += v * (r - l + 1);
		t[p] %= MOD;
		b[p] += v;
		b[p] %= MOD;
		return ;
	}
	if(l != r)push_down(p,l,mid,r);
	if(mid >= objl)Update_Plus(l,mid,objl,objr,p*2,v);
	if(mid < objr)Update_Plus(mid+1,r,objl,objr,p*2+1,v);
	push_up(p);
	return ;
}
int Query(int l,int r,int objl,int objr,int p){
	int mid = (l + r) >> 1;
	if(l != r)push_down(p,l,mid,r);
	int ret = 0;
	if(objl <= l && r <= objr){
		return t[p] % MOD;
	}
	if(mid >= objl)ret = Query(l,mid,objl,objr,p*2) % MOD;
	if(mid < objr)ret = (ret + Query(mid+1,r,objl,objr,p*2+1)) % MOD;
	return ret % MOD;
}
signed main(){
	//freopen("lt.in","r",stdin);
	//freopen("lt.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&MOD);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	Build(1,n,1);
	while(m--){
		int opt,x,y,k;
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt == 1){
			scanf("%lld",&k);
			Update_Times(1,n,x,y,1,k);
		}else if(opt == 2){
			scanf("%lld",&k);
			Update_Plus(1,n,x,y,1,k);
		}else{
			printf("%lld\n",Query(1,n,x,y,1));
		}
	}
	return 0;
}
