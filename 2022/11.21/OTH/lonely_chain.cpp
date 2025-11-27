#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
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
struct Edge{
	int nxt,to;
	bool verda;
}e[MAXN];
int head[MAXN],tot = 1;
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
int t,n,q,dep[MAXN],fa[MAXN],lst[MAXN],fae[MAXN];
bool est_chain;
namespace subtask_BF{
	int kol[MAXN];
	void solve(){
		while(q--){
			int opt = read();
			int u = read(),v = read();
			if(opt == 1){
				lst[u] = 0;
				lst[v] = 0;
				for(int i = head[u];i;i = e[i].nxt){
					e[i].verda = 0;
				}
				for(int i = head[v];i;i = e[i].nxt){
					e[i].verda = 0;
				}
				while(u != v){
					if(dep[u] < dep[v])swap(u,v);//u going up
					for(int i = head[u];i;i = e[i].nxt){
						if(e[i].to == lst[u])continue;
						e[i].verda = 0;
					}
					lst[fa[u]] = u;
					e[fae[u]].verda = 1;
					u = fa[u];
				}
			}else{
				int ret = 0;
				while(u != v){
					if(dep[u] < dep[v])swap(u,v);//u going up
					ret += e[fae[u]].verda;
					u = fa[u];
				}
				printf("%d\n",ret);
			}
		}
		return ;
	}
}
namespace subtask_chain{
	int dfn[MAXN],end_pos,dnt,tr[MAXN*4],len[MAXN*4];
	int lazy[MAXN*4];
	void dfs2(int u,int father){
		dfn[u] = ++dnt;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == father)continue;
			dfs2(v,u);
		}
		return ;
	}
	void build(int l,int r,int p){
		tr[p] = 0;
		lazy[p] = -1;
		len[p] = r - l + 1;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		build(l,mid,p*2);
		build(mid+1,r,p*2+1);
		return ;
	}
	void pushdown(int p){
		if(lazy[p] == -1)return ;
		tr[p*2] = len[p*2] * lazy[p];
		tr[p*2+1] = len[p*2+1] * lazy[p];
		lazy[p*2] = lazy[p],lazy[p*2+1] = lazy[p];
		lazy[p] = -1;
		return ;
	}
	void pushup(int p){
		if(len[p] == 1)return ;
		tr[p] = tr[p*2] + tr[p*2+1];
		return ;
	}
	void change(int l,int r,int objl,int objr,int p,int v){
		if(objl <= l && r <= objr){
			tr[p] = len[p] * v;
			lazy[p] = v;
			return ;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		if(mid >= objl)change(l,mid,objl,objr,p*2,v);
		if(mid < objr)change(mid+1,r,objl,objr,p*2+1,v);
		pushup(p);
		return ;
	}
	int query(int l,int r,int objl,int objr,int p){
		if(objl <= l && r <= objr){
			return tr[p];
		}
		pushdown(p);
		int mid = (l + r) >> 1,ret = 0;
		if(mid >= objl)ret = query(l,mid,objl,objr,p*2);
		if(mid < objr)ret += query(mid+1,r,objl,objr,p*2+1);
		return ret;
	}
	void solve(){
		dnt = 0;
		dfs2(end_pos,end_pos);
		build(1,n,1);

		while(q--){
			int opt = read();
			int u = read(),v = read();
			int l = min(dfn[u],dfn[v]);
			int r = max(dfn[u],dfn[v]);
			if(opt == 1){	
				if(l != 1)change(1,n,l-1,l-1,1,0);
				if(r != n)change(1,n,r,r,1,0);
				if(l == r)continue;
				change(1,n,l,r-1,1,1);
			}else{
				if(l == r){
					puts("0");
					continue;
				}
				printf("%d\n",query(1,n,l,r-1,1));
			}
		}
		return ;
	}
}
void dfs(int u,int father){
	int sz = 0;
	fa[u] = father;
	dep[u] = dep[father] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		sz++;
		fae[v] = i^1;
		dfs(v,u);
	}
	if(sz != 0 && sz != 2)est_chain = 0;
	if(sz == 0){
		subtask_chain::end_pos = u;
	}
	return ;
}
int main(){
	freopen("lonely.in","r",stdin);
	freopen("lonely2.out","w",stdout);
	t = read();
	while(t--){
		est_chain = 1;
		tot = 1;
		for(int i = 0;i <= n;i++){
			head[i] = 0;
			dep[i] = 0;
			fa[i] = 0;
		}
		n = read(),q = read();
		for(int i = 1;i < n;i++){
			int u = read(),v = read();
			AddEdge(u,v);
			AddEdge(v,u);
		}
		dfs(1,1);
		subtask_chain::solve();
	}
	return 0;
}

