#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int MAXK = 1e3;
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
int n,q,sz;
int bel[MAXN],fk[MAXK];
bool cg[MAXK],a[MAXN];
void BF_change(int l,int r){
	r = min(r,n);
	for(int i = l;i <= r;i++){
		a[i] = !a[i];
	}
	fk[bel[l]] = 0;
	const int lp = (bel[l]-1)*sz + 1;
	const int rp = min(bel[l]*sz,n);
	for(int i = lp;i <= rp;i++){
		fk[bel[l]] += a[i] ^ cg[bel[l]];
	}
	return ;
}
void change(int l,int r){
	if(bel[l] == bel[r]){
		BF_change(l,r);
		return ;
	}
	BF_change(l,bel[l]*sz);
	BF_change((bel[r]-1)*sz+1,r);
	if(bel[l] + 1 == bel[r])return ;
	for(int i = bel[l] + 1;i < bel[r];i++){
		fk[i] = sz - fk[i];
		cg[i] = !cg[i];
	}
	return ;
}
int BF_query(int l,int r){
	r = min(r,n);
	int ret = 0;
	for(int i = l;i <= r;i++){
		ret += a[i] ^ cg[bel[l]];
	}
	return ret;
}
int query(int l,int r){
	if(bel[l] == bel[r])return BF_query(l,r);
	int ret = BF_query(l,bel[l]*sz) + BF_query((bel[r]-1)*sz+1,r);
	for(int i = bel[l] + 1;i < bel[r];i++){
		ret += fk[i];
	}
	return ret;
}
void INIT(){
	sz = sqrt(n);
	for(int i = 1;i <= n;i++){
		bel[i] = ((i-1) / sz) + 1;
	}
	return ;
}
int main(){
	n = read(),q = read();
	INIT();
	while(q--){
		int opt = read(),l = read(),r = read();
		if(opt == 0){
			change(l,r);
		}else{
			write(query(l,r));
			putchar('\n');
		}
	}
	return 0;
}
