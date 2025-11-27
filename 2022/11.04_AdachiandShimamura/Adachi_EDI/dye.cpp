#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500006;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline char readc(){
	char ch = getchar();
	while(ch != 'C' && ch != 'Q'){
		ch = getchar();
	}
	return ch;
}
struct Edge{
	int nxt,to;
}e[MAXN*4];
int head[MAXN],tot = 1;
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int n,q,koloro[MAXN],dep[MAXN],fa[MAXN],sz[MAXN],hv[MAXN];
void dfs(int u,int father){
	dep[u] = dep[father] + 1;
	fa[u] = father;
	sz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != father){
			const int v = e[i].to;
			dfs(v,u);
			if(hv[u] == 0 || sz[v] > sz[hv[u]]){
				hv[u] = v;
			}
			sz[u] += sz[v];
		}
	}
	return ;
}
int dfn[MAXN],dnt,tp[MAXN]; 
void dfs2(int u,int nowtp){
	dfn[u] = ++dnt;
	tp[u] = nowtp;
	if(hv[u] != 0){
		dfs2(hv[u],tp[u]);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(dep[v] > dep[u] && v != hv[u]){
			dfs2(v,v);
		}
	}
	return ;
}
void write(int x){
    if(x > 9)write(x / 10);
    putchar(x % 10 + '0');
    return ;
}
struct Segment_tree{
	int kol,lk,rk;
	bool lazy;
}t[MAXN*5];
int findL,findR,lastKx,lastKy,lastL,lastR;
void pushup(int p){
	t[p].lk = t[p*2].lk,t[p].rk = t[p*2+1].rk;
	t[p].kol = t[p*2].kol + t[p*2+1].kol;
	if(t[p*2].rk == t[p*2+1].lk)t[p].kol--;
	return ;
}
void pushdown(int p){
	if(t[p].lazy == 0 || p*2+1 >= MAXN*5)return ;
	t[p*2].kol = 1,t[p*2+1].kol = 1;
	t[p*2].lazy = 1,t[p*2+1].lazy = 1;
	t[p*2].lk = t[p].lk,t[p*2].rk = t[p].rk;
	t[p*2+1].lk = t[p].lk,t[p*2+1].rk = t[p].rk;
	t[p].lazy = 0;
	return ;
}
void build(int l,int r,int p){
	if(l == r){
		t[p].kol = 0;
		t[p].lk = koloro[l];
		t[p].rk = koloro[r];
		return ;
	}
	int mid = (l+r) >> 1;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	pushup(p);
	return ;
}
void change_seg(int l,int r,int objl,int objr,int p,int nk){
	if(objl <= l && r <= objr){
		t[p].kol = 1;
		t[p].lk = nk,t[p].rk = nk;
		t[p].lazy = 1;
		return ;
	}
	pushdown(p);
	int mid = (l + r >> 1);
	if(mid >= objl)change_seg(l,mid,objl,objr,p*2,nk);
	if(mid < objr)change_seg(mid+1,r,objl,objr,p*2+1,nk);
	pushup(p);
	return ;
}
void change(int x,int y,int c){
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]])swap(x,y);
		change_seg(1,n,dfn[tp[x]],dfn[x],1,c);
		x = fa[tp[x]];
	}
	if(dep[x] < dep[y])swap(x,y);
	change_seg(1,n,dfn[y],dfn[x],1,c);
	return ;
}
int query_seg(int l,int r,int objl,int objr,int p){
	int ret = 0;
	if(l == findL){
		lastL = t[p].lk;
	}
	if(r == findR){
		lastR = t[p].rk;
	}
	
	if(objl <= l && r <= objr){
		return t[p].kol;
	}
	pushdown(p);
	int mid = (l + r >> 1);
	bool choose_l = 0,choose_r = 0;
	int lc = -1,rc = -1;
	if(mid >= objl){
		ret = query_seg(l,mid,objl,objr,p*2);
		lc = ret;
		choose_l = 1;
	}
	if(mid < objr){
		ret += query_seg(mid+1,r,objl,objr,p*2+1);
		rc = ret - lc;
		choose_r = 1;
	}
	if(choose_l && choose_r && t[p*2].rk == t[p*2+1].lk){
		ret--;
	}
	pushup(p);
	return ret;
}
int query(int x,int y){
	lastKx = -1,lastKy = -1;
	int ret = 0;
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]]){
			swap(x,y);
			swap(lastKx,lastKy);
		}
		findL = dfn[tp[x]],findR = dfn[x];
		ret += query_seg(1,n,dfn[tp[x]],dfn[x],1);
		if(lastKx == lastR){
			ret--;
		}
		lastKx = lastL;
		x = fa[tp[x]];
	}
	if(dep[x] < dep[y]){
		swap(x,y);
		swap(lastKx,lastKy);
	}
	findL = dfn[y],findR = dfn[x];
	ret += query_seg(1,n,dfn[y],dfn[x],1);
	if(lastKx == lastR){
		ret--;
	}
	if(lastKy == lastL){
		ret--;
	}
	return ret;
}
int main(){
	freopen("dye.in","r",stdin);
	//freopen("dye.out","w",stdout);
	n = read(),q = read();
	for(int i = 1;i <= n;i++){
		koloro[i] = read();
	}
	for(int i = 1;i < n;i++){
		int a = read(),b = read();
		AddEdge(a,b);
		AddEdge(b,a);
	}
	dfs(1,1);
	dfs2(1,1);
	build(1,n,1);
	for(int i=1;i<=n;i++)  
        change_seg(1,n,dfn[i],dfn[i],1,koloro[i]);
    int ccc = 0;
    
	while(q--){		
		char opt = readc();
		int x = read(),y = read(),c;
		if(opt == 'C'){
			c = read();
			change(x,y,c);
		}else{
			write(query(x,y)),putchar('\n');
		}
	}
	return 0;
}
