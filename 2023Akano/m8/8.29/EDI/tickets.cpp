#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXP = 4e6 + 2006 + 1018;
const int MAXE = 1e7 + 2006 + 1108;
const int MAXN = 1e5 + 1018 + 1108;
const ll INF = 1e17;
struct Edge{
	int nxt,to;
	ll val;
}e[MAXE];
int head[MAXP],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void AddEdgeF(int from,int to,ll val){
	AddEdge(to,from,val);//½¨·´±ß 
	return ; 
}
int n,k,station[MAXN],ticket[MAXN],nnt;
class SegmentTree{
	private:
		int no[MAXN * 4];
		void Build(int p,int l,int r){
			no[p] = ++nnt;
			if(l == r){
				AddEdgeF(no[p],station[l],0);
				return ;
			}
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);
			AddEdgeF(no[p],no[p*2],0),AddEdgeF(no[p],no[p*2+1],0);
			return ;
		}
		void PushEdge(int p,int l,int r,int OBJL,int OBJR,int from,int val){
			if(OBJL <= l && r <= OBJR){
				AddEdgeF(from,no[p],val);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJL)PushEdge(p*2,l,mid,OBJL,OBJR,from,val);
			if(mid < OBJR)PushEdge(p*2+1,mid+1,r,OBJL,OBJR,from,val);
			return ;
		}
	public:
		inline void Build(){
			Build(1,1,n);
			return ;
		}
		inline void PushEdge(int from,int l,int r,int val){
			PushEdge(1,1,n,l,r,from,val);
			return ;
		}
}tr;
ll dis1[MAXP],dis2[MAXP];
bool vis[MAXP];
inline void Dij(int st,ll dis[],bool clear){
	priority_queue<pair<ll,int> > q;
	for(int i = 1;i <= nnt;i++){
		if(clear)dis[i] = INF;
		vis[i] = false;
	}
	if(clear){
		dis[st] = 0;
		q.push(make_pair(-dis[st],st));
	}else{
		for(int i = 1;i <= nnt;i++){
			q.push(make_pair(-dis[i],i));
		}
	}
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		station[i] = ++nnt;
	}
	tr.Build();
	for(int i = 1;i <= k;i++){
		ticket[i] = ++nnt;
		int inStation,price,l,r;
		cin>>inStation>>price>>l>>r;
		AddEdgeF(station[inStation],ticket[i],price);
		tr.PushEdge(ticket[i],l,r,0);
	}
	Dij(station[1],dis1,true);
	Dij(station[n],dis2,true);
	for(int i = 1;i <= nnt;i++)dis1[i] += dis2[i];
	Dij(10181108,dis1,false);
	for(int i = 1;i <= n;i++){
		if(dis1[station[i]] >= INF)dis1[station[i]] = -1;
		cout<<dis1[station[i]]<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
