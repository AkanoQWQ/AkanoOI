#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 6;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n,m,ans[MAXN],anss[MAXN],dir[MAXN],tr[MAXN*8];
struct node{
	int no,v;
}c[MAXN];
bool cmp(node a,node b){
	if(a.v != b.v){
		return a.v < b.v;
	}
	return a.no < b.no;
}
void build(int l,int r,int p){
	int mid = (l + r) >> 1;
	if(l == r){
		dir[l] = p;
		return ;
	}
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
int objl,objr;
bool unable;
int query(int l,int r,int p){
	if(objl <= l && r <= objr){
		return tr[p];
	}
	int mid = (l + r) >> 1,ret = 0;
	if(mid >= objl)ret = query(l,mid,p*2);
	if(mid < objr)ret += query(mid+1,r,p*2+1);
	return ret;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		c[i].v = read();
		c[i].no = i;
	}
	sort(c+1,c+n+1,cmp);
	build(1,n,1);
	for(int i = 1;i <= n;i++){
		const int nn = c[i].no;
		if(unable){
			anss[nn] = -1;
			continue;
		}
		ans[i] = ans[i-1];
		ans[i] += (i-1) * (c[i].v - c[i-1].v);
		anss[nn] = ans[i];
		objl = 1,objr = c[i].no;
		anss[nn] += query(1,n,1);
		if(anss[nn] > m-2){
			anss[nn] = -1;
			unable = 1;
		}
		int pos = dir[c[i].no];
		while(pos >= 1){
			tr[pos]++;
			pos /= 2;
		}
	}
	for(int i = 1;i <= n;i++){
		write(anss[i]),putchar('\n');
	}
	return 0;
}
