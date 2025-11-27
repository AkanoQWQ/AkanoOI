#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii pii = pair<int,int>;
const int MAXN = 1018;
const int UP = 1108;
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
int T,n;
int vis[MAXN][MAXN];//int
int dep[MAXN],light[MAXN],heavy[MAXN];
void dfs(int u,int fa){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dep[v] = dep[u] + 1;
		light[u] = min(light[u],v);
		heavy[u] = max(heavy[u],v);
		dfs(v,u);
	}
	return ;
}
inline void Update(int u,int& limL,int& limR){
	limL = 
}
inline pii Cut(pii from,bool IsLeft){
	int l = from.first,r = from.second;
	int limL = l,limR = r;
	if(IsLeft){
		Update(l,limL,limR),++l;
	}else{
		Update(r,limL,limR),--r;
	}
	while(l <= r && (l < limL || limR < r)){
		if(l < limL){
			Update(l,limL,limR),++l;
		}else{
			Update(r,limL,limR),--r;
		}
		if(limR < limL)l = r + 1;//correct?
	}
	if(l > r)return make_pair(0,0);
	return make_pair(l,r);
}
inline int Solve(int no){//long long ? 
	queue<pair<int,int> > q;
	int ret = 0;
	vis[0][0] = vis[1][n] = no;
	q.push(make_pair(1,n));
	while(!q.empty()){
		const Node u = q.front();
		q.pop();
		ret++;
		pii nodeL = CutLeft(u,true),nodeR = CutRight(u,false);
		if(vis[nodeL.first][NodeL.second] != no)q.push(nodeL);
		if(vis[nodeR.first][NodeR.second] != no)q.push(nodeR);
	}
	return ret;
}
inline void Clear(int n){
	for(int i = 0;i <= n;i++){
		head[i] = dep[i] = 0;
		light[i] = heavy[i] = i;
	}
	cnt = 0;
	return ;
}
int main(){
	freopen("./datas/tree/tree1.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int turn = 1;turn <= T;turn++){
		cin>>n;
		Clear(n);
		for(int i = 1;i < n;i++){
			int u,v;
			cin>>u>>v;
			AddEdge(u,v),AddEdge(v,u);
		}
		cout<<Solve(turn)<<endl;
	}
	return 0;
}
