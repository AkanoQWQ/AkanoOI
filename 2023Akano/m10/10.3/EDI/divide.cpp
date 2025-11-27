#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1e6 + 1018 + 1108;

namespace IO {
	const int SIZE=(1<<21)+1;
	char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f, qr;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template <class I>
	inline void Read(I &x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);
		x*=f;
	}
	template <class I>
	inline void Print(I x){
		if(!x)putc('0');
		if(x<0)putc('-'),x=-x;
		while(x)qu[++qr]=x%10+'0',x/=10;
		while(qr)putc(qu[qr --]);
	}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using IO::Read;
using IO::Print;
using IO::putc;

struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int T,n,kol[MAXN],tp[MAXN];
vector<int> point[MAXN],control[MAXN];
int dep[MAXN],dfn[MAXN],dnt;
bool deleted[MAXN],vis[MAXN];

int clk;

namespace LCA{
	int fa[MAXN],ans[MAXN];
	int Find(int x){
		if(fa[x] == x)return x;
		return fa[x] = Find(fa[x]);
	}
	bool visit[MAXN];
	vector<pii> querys[MAXN];
	inline void Clear(){
		for(int i = 1;i <= n;i++){
			querys[i].clear();
		}
		return ;
	}
	inline void Push(int u,int v,int id){
		querys[u].emplace_back(v,id);
		querys[v].emplace_back(u,id);
		return ;
	}
	void Tarjan(int u){
		visit[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(visit[v])continue;
			Tarjan(v);
			fa[v] = u;
		}
		for(auto qry : querys[u]){
			if(visit[qry.first]){
				ans[qry.second] = Find(qry.first);
			}
		}
		return ;
	}
	inline void Execute(){
		for(int i = 1;i <= n;i++){
			visit[i] = false;
			fa[i] = i;
		}
		Tarjan(1);
		return ;
	}
}

void dfs(int u,int fa){
	dfn[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dep[v] = dep[u] + 1;
		dfs(v,u);
	}
	return ;
}

void Erase(int u,int fa){
	if(vis[u])return ;
	deleted[kol[u]] = vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		Erase(v,u);
	}
	return ;
}
int totans;
void GetAns(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetAns(v,u);
	}
	for(auto nowKol : control[u]){
		if(deleted[nowKol])continue;
		Erase(u,fa);
		totans++;
		break;
	}
	return ;
}
inline int Solve(){
	for(int i = 1;i <= n;i++){
		point[i].clear();
		control[i].clear();
		deleted[i] = vis[i] = false;
		dnt = 0;
		head[i] = 0;
	}
	cnt = totans = 0;
	LCA::Clear();
	for(int i = 1;i <= n;i++){
		Read(kol[i]);
		point[kol[i]].push_back(i);
	}
	for(int i = 1;i < n;i++){
		int u,v;
		Read(u),Read(v);
		AddEdge(u,v),AddEdge(v,u);
	}
	dep[1] = 1;
	dfs(1,0);
	for(int i = 1;i <= n;i++){
		if(point[i].empty())continue;
		int mn = point[i][0],mx = point[i][0];
		for(auto u : point[i]){
			if(dfn[u] < dfn[mn])mn = u;
			if(dfn[u] > dfn[mx])mx = u;
		}
		LCA::Push(mn,mx,i);
	}
	LCA::Execute();
	for(int i = 1;i <= n;i++){
		if(point[i].empty())continue;
		tp[i] = LCA::ans[i];
		control[tp[i]].push_back(i);
	}
	GetAns(1,-10181108);
	return totans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("divide/org/divide2.in","r",stdin);
//	freopen("divide.out","w",stdout);
	Read(T);
	while(T--){
		Read(n);
		Print(Solve());
		putc('\n');
	}
	cerr<<"used time "<<clk<<endl;
	return not(Akano loves pure__Elysia);
}
