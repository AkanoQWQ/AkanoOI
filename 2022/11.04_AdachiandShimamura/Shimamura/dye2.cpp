#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100006;
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
		dfs2(hv[u],hv[u]);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(dep[v] > dep[u] && v != hv[u]){
			dfs2(v,nowtp);
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
void pushup(int p){
	t[p].lk = t[p*2].lk,t[p].rk = t[p*2+1].rk;
	t[p].kol = t[p*2].kol + t[p*2+1].kol;
	if(t[p*2].rk == t[p*2+1].lk)t[p].kol--;
	return ;
}
void build(int l,int r,int p){
	if(l == r){
		t[p].kol = 1;
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
void pushdown(int p){
	if(t[p].lazy == 0 || p*2+1 >= n*5)return ;
	t[p*2].kol = 1,t[p*2+1].kol = 1;
	t[p*2].lk = t[p].lk,t[p*2].rk = t[p].rk;
	t[p*2+1].lk = t[p].lk,t[p*2+1].rk = t[p].rk;
	t[p].lazy = 0;
	t[p*2].lazy = 1,t[p*2+1].lazy = 1;
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
	if(dep[x] < dep[y])swap(x,y);
	while(tp[x] != tp[y]){
		change_seg(1,n,dfn[tp[x]],dfn[x],1,c);
		x = fa[tp[x]];
		if(dep[x] < dep[y])swap(x,y);
	}
	if(dep[x] < dep[y])swap(x,y);
	change_seg(1,n,dfn[y],dfn[x],1,c);
	return ;
}
int query_seg(int l,int r,int objl,int objr,int p){
	int ret = 0;
	pushdown(p);
	if(objl <= l && r <= objr){
		return t[p].kol;
	}
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
	if(choose_l && choose_r && t[p*2].rk == t[p*2].lk){
		ret--;
//		cout<<"seg--"<<ret<<"in "<<l<<","<<r<<","<<mid<<endl;
//		cout<<lc<<" and "<<rc<<endl;
	}
	if(ret < 0)cout<<"WTF???  in "<<l<<","<<r<<endl;
	return ret;
}
int findp(int l,int r,int objl,int objr,int p){
	int ret = p;
	if(objl <= l && r <= objr){
		return p;
	}
	int mid = (l + r >> 1);
	if(mid >= objl)ret = findp(l,mid,objl,objr,p*2);
	if(mid < objr)ret = findp(mid+1,r,objl,objr,p*2+1);
	return ret;
}
int query(int x,int y){
	cout<<"query "<<x<<","<<y<<endl;
	int ret = 0;
	if(dep[x] < dep[y])swap(x,y);
	while(tp[x] != tp[y]){
//		cout<<"not tp"<<" "<<tp[x]<<" "<<tp[y]<<endl;
		ret += query_seg(1,n,dfn[tp[x]],dfn[x],1);
		cout<<"nowret "<<ret<<" bec "<<dfn[tp[x]]<<"->"<<dfn[x]<<"("<<tp[x]<<","<<x<<endl;
		if(t[findp(1,n,dfn[tp[x]],dfn[tp[x]],1)].lk == t[findp(1,n,dfn[fa[tp[x]]],dfn[fa[tp[x]]],1)].rk){
			cout<<"equal "<<t[findp(1,n,dfn[tp[x]],dfn[tp[x]],1)].lk<<" and "<<t[findp(1,n,dfn[fa[tp[x]]],dfn[fa[tp[x]]],1)].rk<<endl;
			ret--;
			cout<<"ret--"<<endl;
		}
		x = fa[tp[x]];
		if(dep[x] < dep[y])swap(x,y);
		cout<<"newxy"<<x<<","<<y<<endl;
	}
	if(x == y)return ret;
	if(dep[x] < dep[y])swap(x,y);
	cout<<"nr"<<ret<<endl;
	cout<<"last "<<y<<","<<x<<" in "<<dfn[y]<<","<<dfn[x]<<endl;
//	if(x == 2 && y == 2)cout<<"both 2"<<endl;
	ret += query_seg(1,n,dfn[y],dfn[x],1);
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
	for(int i = 1;i <= n;i++){
//		cout<<dfn[i]<<" ";
	}
//	cout<<endl;
//	cout<<query(1,2)<<endl;
//	cout<<query(1,5)<<endl;
//	cout<<"2,2:"<<query(2,2)<<endl;
//	cout<<"2,2 in seg:"<<query_seg(1,n,dfn[2],dfn[2],1)<<endl;
//	cout<<"po"<<findp(1,n,2,2,1)<<endl;;
//	for(int i = 1;i <= 10;i++){
//		cout<<t[i].kol<<",";
//	}
//	cout<<endl;
//	return 0;
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
//很裸的树剖,**但是咱不会染色线段树!!!** 
//没错咱开始尝试写树剖了 
