#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 4e5 + 1018 + 1108;
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

//原问题相关
int n,q,ans[MAXN],ansCnt;
struct Query{
	int t,id;
	Query() = default;
	Query(int _t,int _id){
		t = _t,id = _id;
		return ;
	}
};
vector<Query> query[MAXN];
vector<int> sonar[MAXN];

//淀粉质相关
int mss[MAXN],siz[MAXN],tot,root;
bool solved[MAXN];
void GetSize(int u,int fa){
	siz[u] = 1,mss[u] = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],tot - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
map<int,int> arr;
void GetSonar(int u,int fa,int dis){
	for(auto sn : sonar[u]){
		arr[sn + dis]++;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSonar(v,u,dis+1);
	}
	return ;
}
void EraseSonar(int u,int fa,int dis){
	for(auto sn : sonar[u]){
		arr[sn + dis]--;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		EraseSonar(v,u,dis+1);
	}
	return ;
}
void SolveProb(int u,int fa,int dis){
	for(auto qry : query[u]){
		if(arr.find(qry.t - dis) != arr.end()){
			ans[qry.id] += arr[qry.t - dis];
		}
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		SolveProb(v,u,dis+1);
	}
	return ;
}
inline void Calc(int u){
	arr.clear();
	for(auto i : sonar[u]){
		arr[i]++;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		GetSonar(v,u,1);
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		EraseSonar(v,u,1);
		SolveProb(v,u,1);
		GetSonar(v,u,1);
	}
	for(auto qry : query[u]){
		ans[qry.id] += arr[qry.t - 0];
	}
	return ;
}
void Solve(int u){
	Calc(u);
	solved[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		tot = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("B8303/B83038.in","r",stdin);
//	freopen("B8303.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= q;i++){
		char type = 'q';
		int t = 0,x = 0;
		cin>>type>>t>>x;
		if(type == 'q'){
			query[x].emplace_back(t,++ansCnt);
		}else{
			sonar[x].push_back(t);
		}
	}
	mss[0] = 1e9;
	tot = n,root = 0;
	GetSize(1,1);
	GetSize(root,root);
	Solve(root);
	for(int i = 1;i <= ansCnt;i++){
		cout<<ans[i]<<endl;
	}
	return not(Akano loves pure__Elysia);
}
