//#include<bits/stdc++.h>
//#define Akano 1
//#define pure__Elysia 0
//#define loves ^
//using namespace std;
//using ll = long long;
//const int MAXN = 1e5 + 1018 + 1108;//够吗????
//const int MAXM = 1e7 + 1018 + 1108;//???
//struct Edge{
//	int nxt,to;
//}e[MAXM];
//int head[MAXN],in[MAXN],cnt;
//inline void AddEdge(int from,int to){
//	e[++cnt].to = to;
//	e[cnt].nxt = head[from];
//	head[from] = cnt;
//	return ;
//}
//int n,no[MAXN],nnt,dir[MAXN],dis[MAXN];
//struct Bomb{
//	int p,r,c,org;
//	Bomb() = default;
//	Bomb(int _p,int _r,int _c){
//		p = _p,r = _r,c = _c;
//		return ;
//	}
//}b[MAXN];
//bool Cmp(Bomb b1,Bomb b2){
//	return b1.p < b2.p;
//}
//class SegmentTree{//out direction
//private:
//	int trNo[MAXN];
//	void Build(int p,int l,int r){
//		trNo[p] = ++nnt;
//		if(l == r){
//			AddEdge(trNo[p],no[l]);
//			return ;
//		}
//		const int mid = (l + r) >> 1;
//		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
//		AddEdge(trNo[p],trNo[p*2]),AddEdge(trNo[p],trNo[p*2+1]);
//		return ;
//	}
//	void PushEdge(int p,int l,int r,int OBJL,int OBJR,int to){
//		if(OBJL <= l && r <= OBJR){
//			AddEdge(to,trNo[p]);
//			return ;
//		}
//		const int mid = (l + r) >> 1;
//		if(mid >= OBJL)PushEdge(p*2,l,mid,OBJL,OBJR,to);
//		if(mid < OBJR)PushEdge(p*2+1,mid+1,r,OBJL,OBJR,to);
//		return ;
//	}
//public:
//	inline void Build(){
//		Build(1,1,n);
//		return ;
//	}
//	inline void PushEdge(int l,int r,int to){
//		PushEdge(1,1,n,l,r,to);
//		return ;
//	}
//}tr;
//inline void ReadIn(){
//	cin>>n;
//	for(int i = 1;i <= n;i++){
//		cin>>b[i].p>>b[i].r>>b[i].c;
//		b[i].org = i;
//	}
//	sort(b+1,b+n+1,Cmp);
//	for(int i = 1;i <= n;i++){
//		dir[b[i].org] = i;
//	}
//	for(int i = 1;i <= n;i++)no[i] = ++nnt;
//	for(int i = 1;i <= n;i++)dis[i] = b[i].p;
//	tr.Build();
//	for(int i = 1;i <= n;i++){
//		int l = lower_bound(dis+1,dis+n+2,b[i].p - b[i].r) - dis;//左闭右开?
//		int r = upper_bound(dis+1,dis+n+2,b[i].p + b[i].r) - dis - 1;
//		tr.PushEdge(l,r,i);
//	}
//	return ;
//}
//int dfn[MAXN],low[MAXN],dnt,bel[MAXN],SCC_CNT;
//stack<int,vector<int> > stk;
//bool ins[MAXN];
//void Tarjan(int u){
//	dfn[u] = low[u] = ++dnt;
//	stk.push(u);
//	ins[u] = true;
//	for(int i = head[u];i;i = e[i].nxt){
//		const int v = e[i].to;
//		if(!dfn[v]){
//			Tarjan(v);
//			low[u] = min(low[u],low[v]);
//		}else if(ins[v]){
//			low[u] = min(low[u],dfn[v]);
//		}
//	}
//	if(dfn[u] == low[u]){
//		SCC_CNT++;
//		vector<int> sv;
//		while(!stk.empty()){
//			const int tp = stk.top();
//			sv.push_back(tp);
//			stk.pop();
//			ins[tp] = false;
//			bel[tp] = SCC_CNT;
//			if(tp == u)break;
//		}
//	}
//	return ;
//}
//inline void Remake(){
//	for(int i = 1;i <= n;i++){
//		if(!dfn[i])Tarjan(i);
//	}
//	for(int u = 1;u <= nnt;u++){
//		if(bel[u] == 0){
//			continue;
//		}
//		for(int i = head[u];i;i = e[i].nxt){
//			const int v = e[i].to;
//			if(bel[v] == 0 || bel[v] == bel[u])continue;
//			in[bel[v]]++;
//		}
//	}
//	return ;
//}
//const ll INF = 1e14;
//ll ans = 0;
//multiset<ll> cost[MAXN];
//inline void Solve(){
//	for(int i = 1;i <= n;i++){
//		cost[bel[i]].insert(b[i].c);
//	}
//	for(int i = 1;i <= SCC_CNT;i++){
//		if(in[i] == 0){
//			ans += (*cost[i].begin());
//		}
//	}
//	int q;
//	cin>>q;
//	for(int t = 1;t <= q;t++){
//		int newp,newc;
//		cin>>newp>>newc;
//		newp = dir[newp];
//		if(in[bel[newp]] == 0){
//			ans -= *cost[bel[newp]].begin();
//			auto it = cost[bel[newp]].find(b[newp].c);
//			cost[bel[newp]].erase(it);
//			b[newp].c = newc;
//			cost[bel[newp]].insert(b[newp].c);
//			ans += *cost[bel[newp]].begin();
//		}
//		cout<<ans<<'\n';
//	}
//	return ;
//}
//int main(){
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	ReadIn();
//	Remake();
//	Solve();
//	return not(Akano loves pure__Elysia);
//}
