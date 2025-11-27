//I'm debuging for my classmate
//so this is not my code
#include <bits/stdc++.h>
#define int long long
#define MAXN 200010
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n,m,q;
int clk;
multiset<int>tran[200010];
struct Edge{
	int nxt,to;
}e[MAXN<<1],edge[MAXN<<1];
int h[MAXN],head[MAXN];
int tt,tot;
vector<int>team[MAXN];
int d[MAXN],val[MAXN];
inline void add_edge(int u,int v){
	edge[++tot].to=v;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
inline void add(int u,int v){
	e[++tt].to=v;
	e[tt].nxt=h[u];
	h[u]=tt;
}
int low[MAXN],dfn[MAXN],num;
int stk[MAXN],tp,col;
void Tarjan(int x){
	low[x]=dfn[x]=++num;
	stk[++tp]=x;
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[x]=min(low[v],low[x]);
			if(low[v]==dfn[x]){
				col++;
				while(stk[tp]!=x){
					add_edge(n+col,stk[tp]);
					add_edge(stk[tp],n+col);
					tran[col].insert(d[stk[tp]]);
					team[stk[tp]].push_back(col);
					tp--;
				}
				add_edge(n+col,stk[tp]);
				add_edge(stk[tp],n+col);
				tran[col].insert(d[stk[tp]]);
				team[stk[tp]].push_back(col);
			}
		}
		else low[x]=min(low[x],dfn[v]);
	}
}
int fa[MAXN],siz[MAXN],dep[MAXN],son[MAXN];
void dfs_1(int now,int fath){
	fa[now]=fath;
	siz[now]=1;
	son[now]=0;
	dep[now]=dep[fath]+1;
	for(int i=head[now];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fath) continue;
		dfs_1(v,now);
		siz[now]+=siz[v];
		if(siz[son[now]]<siz[v]) son[now]=v;
	}
}
int top[MAXN],per[MAXN],cnt;
void dfs_2(int now,int topx){
	top[now]=topx;
	per[now]=++cnt;
	if(son[now]) dfs_2(son[now],topx);
	else return;
	for(int i=head[now];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa[now]||v==son[now]) continue;
		dfs_2(v,v);
	}
}
void prework(){
	Tarjan(1);
	dfs_1(1,0);
	dfs_2(1,1);
}
struct SG{
	int l,r;
	int minn;
}t[MAXN<<2];
void build(int p,int l,int r){
	t[p].l=l;t[p].r=r;
	if(l==r){
		t[p].minn=val[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
}
void change(int p,int pos,int w,int note){
	if(t[p].l==t[p].r){
		clk -= clock();
		if(note<=n){
			int si=team[note].size();
			for(int i=0;i<si;i++){
				multiset<int>::iterator it=tran[team[note][i]].find(t[p].minn);
				tran[team[note][i]].erase(it);
				tran[team[note][i]].insert(w);
			}
		}
		t[p].minn=w;
		clk += clock();
		return;
	}
	int mid=(t[p].l+t[p].r)>>1;
	if(mid>=pos) change(p*2,pos,w,note);
	else change(p*2+1,pos,w,note);
	t[p].minn=min(t[p*2].minn,t[p*2+1].minn);
}
int query(int p,int l,int r){
	if(l<=t[p].l&&t[p].r<=r){
		return t[p].minn;
	}
	int mid=(t[p].l+t[p].r)>>1;
	int ans=INF;
	if(mid>=l) ans=min(ans,query(p*2,l,r));
	if(mid<r) ans=min(ans,query(p*2+1,l,r));
	return ans;
}
inline int LCA(int x,int y){
	int ans=INF;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,query(1,per[top[x]],per[x]));
		x=fa[top[x]];
	}
	if(dep[y]<dep[x]) swap(x,y);
	ans=min(ans,query(1,per[x],per[y]));
	return ans;
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&d[i]);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	prework();
	for(int i=1;i<=n+col;i++){
		if(i<=n) val[per[i]]=d[i];
		else val[per[i]]=(*tran[i-n].begin());
	}
	build(1,1,n+col);
	for(int i=1;i<=q;i++){
		if(clock() / CLOCKS_PER_SEC >= 0.9){
			cout<<"now execute "<<i<<" in "<<q<<",use time "<<clk<<endl;
			return 0;
		}
		char c[5];
		scanf("%s",c);
		if(c[0]=='A'){
			int a,b;
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",LCA(a,b));
		}
		else if(c[0]=='C'){
			int a,w;
			scanf("%lld%lld",&a,&w);
			change(1,per[a],w,a);
			int si=team[a].size();
			for(int j=0;j<si;j++){
				change(1,per[team[a][j]+n],(*tran[team[a][j]].begin()),team[a][j]+n);
			}
		}
	}
	return 0;
}

