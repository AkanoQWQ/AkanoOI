#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2e5 + 1018 + 1108;
const int MAXM = 2e5 + 1018 + 1108;
struct Edge {
	int nxt,to;
	bool bridge;
} e[MAXM * 2];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to) {
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,q;
/*联通性相关*/
int belong[MAXN],belongCnt;
void GetConnect(int u){
	belong[u] = belongCnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(belong[v])continue;
		GetConnect(v);
	}
	return ;
}
/*边双嗦点相关*/
int dfn[MAXN],low[MAXN],dnt,BCC_NO[MAXN],BCC_CNT;
void Tarjan(int u,int fa){
	dfn[u] = low[u] = ++dnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u]){
				e[i].bridge = e[i^1].bridge = true;
			}
		}else if(v != fa){
			low[u] = min(low[u],dfn[v]);
		}
	}
	return ;
}
void FindBCC(int u){
	BCC_NO[u] = BCC_CNT;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].bridge || BCC_NO[v] != 0)continue;
		FindBCC(v);
	}
	return ;
}
/*重建后相关*/
int lcafa[MAXN][22],dep[MAXN],upper[MAXN],lower[MAXN];
bool ans = true;
void GetLCA(int u){
	dep[u] = dep[lcafa[u][0]] + 1;
	for(int i = 1;i <= 20;i++){
		lcafa[u][i] = lcafa[lcafa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == lcafa[u][0])continue;
		lcafa[v][0] = u;
		GetLCA(v);
	}
	return ;
}
inline int LCA(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(int i = 20;i >= 0;i--){
		if(dep[lcafa[u][i]] >= dep[v])u = lcafa[u][i];
	}
	if(u == v)return u;
	for(int i = 20;i >= 0;i--){
		if(lcafa[u][i] != lcafa[v][i]){
			u = lcafa[u][i];
			v = lcafa[v][i];
		}
	}
	return lcafa[u][0];
}
void GetAns(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		GetAns(v,u);
		lower[u] += lower[v],upper[u] += upper[v];
	}
	if(u != fa && lower[u] != 0 && upper[u] != 0)ans = false;
//	cerr<<u<<" lower "<<lower[u]<<" upper "<<upper[u]<<endl;
	return ;
}
inline void ReadIn(){
	cin>>n>>m>>q;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	return ; 
} 
inline void GetInfo(){
	for(int i = 1;i <= n;i++){
		if(!belong[i]){
			belongCnt++;
			GetConnect(i);
		}
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])Tarjan(i,i);
	}
	for(int i = 1;i <= n;i++){
		if(BCC_NO[i] == 0){
			BCC_CNT++;
			FindBCC(i);
		}
	}
	return ;
}
class Hasher{
	public: 
		unsigned long long operator()(const pair<int,int>& pr)const {
			return (((1ull * pr.first) << 32) + pr.second);
		}
};
inline void Remake(){
	unordered_set<pair<int,int>,Hasher> st;
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(BCC_NO[u] != BCC_NO[v])st.insert(make_pair(BCC_NO[u],BCC_NO[v]));
		}
		head[u] = 0;
	}
	n = BCC_CNT;
	cnt = 0;//!!!!!!!!!清空!!!!!!! 
	for(auto i : st){
		AddEdge(i.first,i.second);
	}
	for(int i = 1;i <= n;i++){
		if(dep[i] == 0)GetLCA(i);
	}
	return ;
}
inline void Reply(){
	while(q--){
		int u,v;
		cin>>u>>v;
		if(belong[u] != belong[v])ans = false;
		u = BCC_NO[u],v = BCC_NO[v];
		if(u == v)continue;
		int lca = LCA(u,v);
		upper[u]++,upper[lca]--;
		lower[v]++,lower[lca]--;
	}
	for(int i = 1;i <= n;i++){
		if(lcafa[i][0] == 0)GetAns(i,i);
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	GetInfo();
	Remake();
	Reply(); 
	return not(Akano loves pure__Elysia);
}
