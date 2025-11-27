#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 1018 + 1108;
const int MAXP = MAXN * 15;
const int MAXM = 2e7 + 1018 + 1108; 
const int MOD = 1e9 + 7;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXP],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
struct Boom{
	ll pos,r;
	int no;
}b[MAXN];
ll arr[MAXN],ans;
int nnt,n;
class SegmentTree{
	private:
		int no[MAXN * 4];
		void Build(int p,int l,int r){
			no[p] = ++nnt;
			if(l == r){
				AddEdge(no[p],b[l].no);
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			AddEdge(no[p],no[p*2]),AddEdge(no[p],no[p*2+1]);
			return ;
		}
		void PushEdge(int p,int l,int r,int OBJL,int OBJR,int from){
			if(OBJL <= l && r <= OBJR){
				AddEdge(from,no[p]);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)PushEdge(p*2,l,mid,OBJL,OBJR,from);
			if(mid < OBJR)PushEdge(p*2+1,mid+1,r,OBJL,OBJR,from);
			return ;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void PushEdge(int l,int r,int from){
			PushEdge(1,1,n,l,r,from);
			return ;
		}
}tr;
int dfn[MAXP],low[MAXP],dnt,sz[MAXN],bel[MAXP],SCC_cnt;
bool ins[MAXP];
stack<int,vector<int> > stk;
int l[MAXP],r[MAXP];
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	stk.push(u),ins[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		++SCC_cnt;
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			ins[tp] = false;
			if(tp <= n){
				l[SCC_cnt] = min(l[SCC_cnt],tp);
				r[SCC_cnt] = max(r[SCC_cnt],tp);
			}
			bel[tp] = SCC_cnt;
			if(tp == u)break;
		}
	}
	return ;
}
bool vis[MAXP];
void GetAns(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!vis[v])GetAns(v);
		l[u] = min(l[u],l[v]),r[u] = max(r[u],r[v]);
	}
	return ;
}
inline void Remake(){
	set<pair<int,int> > newe;
	for(int u = 1;u <= nnt;u++){
		if(!bel[u])continue;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(!bel[v])continue;
			if(bel[u] == bel[v])continue;
			newe.insert(make_pair(bel[u],bel[v]));
		}
	}
	cnt = 0;
	for(int i = 1;i <= nnt;i++)head[i] = 0;
	for(auto i : newe){
		AddEdge(i.first,i.second);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>b[i].pos>>b[i].r;
		b[i].no = ++nnt,arr[i] = b[i].pos;
	}
	tr.Build();
	for(int i = 1;i <= n;i++){
		int l = lower_bound(arr+1,arr+n+1,b[i].pos-b[i].r) - arr;
		int r = upper_bound(arr+1,arr+n+1,b[i].pos+b[i].r) - arr - 1;
		tr.PushEdge(l,r,b[i].no);
	}
	for(int i = 1;i <= nnt;i++)l[i] = 1e9,r[i] = 0;
	for(int i = 1;i <= nnt;i++){
		if(!dfn[i])Tarjan(i);
	}
	Remake();
	for(int i = 1;i <= n;i++){
		GetAns(bel[i]);
	}
	for(int i = 1;i <= n;i++){
		ans += 1ll * i * (r[bel[i]] - l[bel[i]] + 1);
		ans %= MOD;
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
