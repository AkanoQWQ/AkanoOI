#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXVAL = 1e6 + 1018 + 1108;
const int INF = 1e9;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool solved[MAXN];
int n,mn,mx,siz[MAXN],mss[MAXN],root,ans = INF;
vector<int> dis;
void GetDis(int u,int fa,int nowdis){
	dis.push_back(nowdis); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v] || v == fa)continue;
		GetDis(v,u,nowdis + e[i].val);
	}
	return ;
}
inline void Calc(int u){
	set<int> st;
	st.insert(0);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dis.clear();
		GetDis(v,u,e[i].val);
		for(auto d : dis){
			auto it = st.lower_bound(mn-d);
			if(it != st.end()){
				ans = min(ans,(*it)+d);
			}
		}
		for(auto d : dis){
			st.insert(d);
		}
	}
	return ;
}
void GetSize(int u,int fa){
	mss[u] = 0,siz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],cnt - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
void Solve(int u){
	Calc(u);
	solved[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		cnt = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>mn>>mx;
	ans = mx+1;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	mss[0] = 1e9;
	cnt = n,root = 0;
	GetSize(1,1);
	GetSize(root,root);
	Solve(root);
	if(ans > mx)ans = -1;
	cout<<ans<<endl; 
	return not(Akano loves pure__Elysia);
}
