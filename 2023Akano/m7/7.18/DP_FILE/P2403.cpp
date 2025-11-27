#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXR = 1e6 + 1018 + 1108;
const int MAXM = 2e7 + 1018 + 1108;//?
using vi = vector<int>;
using pii = pair<int,int>;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
//	cout<<"ADD "<<from<<" to "<<to<<endl;
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,useless,ret,ans,door[MAXN],bel[MAXN],sz[MAXN];
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
pii p[MAXN];
map<pii,int> pos;
vi to[MAXN];
int nameX[MAXR],nameY[MAXR];
int fa[MAXN],no[MAXN],nnt;
int GetFa(int x){
	if(fa[x] == x)return x;
	return fa[x] = GetFa(fa[x]);
}
int dfn[MAXN],low[MAXN],dnt,in[MAXN],dp[MAXN];
stack<int,vector<int> > stk;
bool ins[MAXN];
void Tarjan(int u){
	dfn[u] = low[u] = ++dnt;
	ins[u] = true;
	stk.push(u);
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
		while(!stk.empty()){
			const int tp = stk.top();
			stk.pop();
			ins[u] = false;
			sz[u]++;
			bel[tp] = u;
			if(tp == u)break;
		}
	}
	return ;
}
inline void ExecuteEdge(){
	vector<pii> edges;
	for(int u = 1;u <= nnt;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(bel[u] == bel[v])continue;
			edges.push_back(make_pair(bel[u],bel[v]));
		}
		head[u] = 0;
	}
	cnt = 0;
	for(auto i : edges){
		AddEdge(i.first,i.second);
		in[i.second]++;
	}
	return ;
}
inline void ReadIn(){
	cin>>n>>useless>>useless;
	for(int i = 1;i <= n;i++){
		cin>>p[i].first>>p[i].second>>door[i];
	}
	return ;
}
inline void FindSame(){
	for(int i = 1;i <= n;i++){
		for(int k = 0;k < 8;k++){
			const int OX = p[i].first + dx[k],OY = p[i].second + dy[k];
			if(pos.find(make_pair(OX,OY)) != pos.end()){
				const int v = pos[make_pair(OX,OY)];
				if(door[i] == 3){
					to[i].push_back(v);
				}
				if(door[v] == 3){
					to[v].push_back(i);
				}
			}
		}
		pos[p[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		if(door[i] == 1){
			if(nameX[p[i].first] == 0){
				fa[i] = i;
				nameX[p[i].first] = i;
			}else{
				fa[i] = nameX[p[i].first];
			}
		}else if(door[i] == 2){
			if(nameY[p[i].second] == 0){
				fa[i] = i;
				nameY[p[i].second] = i;
			}else{
				fa[i] = nameY[p[i].second];
			}
		}
	}
	return ;
}
inline void GetNo(){
	for(int i = 1;i <= n;i++){
		if(GetFa(i) == i)no[i] = ++nnt;
	}
	for(int i = 1;i <= n;i++){
		if(fa[i] != 0){
			no[i] = no[GetFa(i)];
		}else{
			no[i] = ++nnt;
		}
	}
	return ;
}
inline void CreateEdge(){
	for(int i = 1;i <= n;i++){
		if(door[i] != 2){
			if(nameY[p[i].second] != 0){
				const int yno = no[nameY[p[i].second]];
				AddEdge(yno,no[i]);
			}
		}
		if(door[i] != 1){
			if(nameX[p[i].first] != 0){
				const int xno = no[nameX[p[i].first]];
				AddEdge(xno,no[i]);
			}
		}
		if(door[i] == 3){
			const int u = no[i];
			for(auto vpre : to[i]){
				const int v = no[vpre];
				AddEdge(u,v);
			}
		}
	}
	return ;
}
inline void ExecuteTarjan(){
	for(int i = 1;i <= nnt;i++){
		if(!dfn[i])Tarjan(i);
	}
	return ;
}
inline void BF(){
	for(int i = 1;i <= n;i++){
		no[i] = ++nnt;
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			if(door[i] == 1 && p[i].first == p[j].first){
				AddEdge(i,j);//no_i = i
			}
			if(door[i] == 2 && p[i].second == p[j].second){
				AddEdge(i,j);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(door[i] != 3)continue;
		for(int j = 1;j <= n;j++){
			if(i == j)continue;
			if(abs(p[i].first-p[j].first) <= 1 && abs(p[i].second-p[j].second) <= 1){
				AddEdge(i,j);
			}
		}
	}
	return ;
}
inline int Topo(){
	queue<int> q;
	int ret = 0;
	for(int i = 1;i <= nnt;i++){
		if(bel[i] != i)continue;
		if(in[i] == 0){
			q.push(i);
			dp[i] = sz[i];
		}
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		ret = max(ret,dp[u]);
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			in[v]--;
			if(!in[v])q.push(v);
			dp[v] = max(dp[v],dp[u] + sz[v]);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("P2043.in","r",stdin);
//	freopen("P2043.out","w",stdout);
	ReadIn();
	//FindSame();
	//GetNo();
	//CreateEdge();
	BF();
	ExecuteTarjan();
	ExecuteEdge();
	cout<<Topo()<<endl;
	return 0;
}
