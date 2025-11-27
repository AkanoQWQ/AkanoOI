#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
int n,m;
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
struct SegmentTree{
	bool lazy;
	int v,len;
}t[MAXN*4 + 6];
void build(int l,int r,int p){
	t[p].v = t[p].lazy = 0;
	t[p].len = r - l + 1;
	if(l == r)return ;
	const int mid = (l + r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	return ;
}
void pushdown(int p){
	if(t[p].lazy == 1 && t[p].len != 1){
		t[p*2].v = t[p*2].len - t[p*2].v;
		t[p*2+1].v = t[p*2+1].len - t[p*2+1].v;
		t[p*2].lazy = !t[p*2].lazy,t[p*2+1].lazy = !t[p*2+1].lazy;
		t[p].lazy = 0;
	}
	return ;
}
void pushup(int p){
	if(t[p].len != 1){
		t[p].v = t[p*2].v + t[p*2+1].v;
	}
	return ;
}
void update(int l,int r,int objl,int objr,int p){
	if(objl <= l && r <= objr){
		t[p].lazy = !t[p].lazy;
		t[p].v = (t[p].len - t[p].v);
		return ;
	}
	pushdown(p);
	const int mid = (l + r) >> 1;
	if(mid >= objl)update(l,mid,objl,objr,p*2);
	if(mid < objr)update(mid+1,r,objl,objr,p*2+1);
	pushup(p);
	return ;
}
int query(int l,int r,int objl,int objr,int p){
	if(objl <= l && r <= objr){
		return t[p].v;
	}
	pushdown(p);
	const int mid = (l + r) >> 1;
	int ret = 0;
	if(mid >= objl)ret = query(l,mid,objl,objr,p*2);
	if(mid < objr)ret += query(mid+1,r,objl,objr,p*2+1);
	return ret;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(),m = read();
	build(1,n,1);
	while(m--){
		int opt = read(),l = read(),r = read();
		if(opt == 0){
			update(1,n,l,r,1);
		}else{
			write(query(1,n,l,r,1)),putchar('\n');
		}
	}
	return 0;
}
