#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define R(i) for(int i=1; i<=n; ++i)
#define rep(i, x, y) for(int i=x; i<=y; ++i)
const int N=1e5+10, SI=1e7;
const int D=1e9+10;
int n,m;
int a[N];

int amt, rt[SI];
struct nod {
	int v;
	int ls, rs;
	int Pass_son(const nod &x) {
		ls = x.ls;
		rs = x.rs;
	}
}tr[SI];
#define calmid \
int mid=(L+R)>>1;
int cha(int f, int L, int R, int x, int d) {
	int p=++amt;
	tr[p].v = tr[f].v+d;	//
	tr[p].Pass_son(tr[f]);
	if(L==R){
		return p;
	}else{
		calmid;
		if(x<=mid) tr[p].ls=cha(tr[p].ls, L, mid, x, d);
		else tr[p].rs=cha(tr[p].rs, mid+1, R, x, d);
	}
	return p;
}
ll iqr(int p, int L, int R, int l, int r) {
	int c=0;
	if(!p)return 0;
	if(l<=L&&R<=r){
		return tr[p].v;
	}else{
		calmid;
		if(l<=mid) c+=1ll*iqr(tr[p].ls, L, mid, l, r);
		if(mid+1<=r) c+=1ll*iqr(tr[p].rs, mid+1, R, l, r);
	}
	return c;
}
int calc(int l, int r){
	int x=0,s=0,tmp=0;
	while(tmp=(iqr(rt[r],1,D,x+1,s+1) - iqr(rt[l-1],1,D,x+1,s+1))) {
		x=s+1; s+=tmp;
	}
	return s+1;
}
int in(){
	int nt, x=0;
	while(!isdigit(nt=getchar())); x=(nt^'0');
	while(isdigit(nt=getchar())) x=(x<<1)+(x<<3)+(nt^'0');
	return x;
}
int main() {
	//freopen("niuniunum.in", "r", stdin);
	//freopen("niuniunum.out", "w", stdout);
	int x,y;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1; i<=n; ++i){
		x=in();
		rt[i]=cha(rt[i-1],1,D,x,x);
	}
	for(int i=1; i<=m; ++i) {
		x=in();
		y=in();
		printf("%d\n", calc(x, y));
	}
	return 0;
}

