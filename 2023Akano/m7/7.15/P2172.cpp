#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXR = 56;
const int MAXN = MAXR * MAXR * 2;//remember to EDIT
const int MAXM = MAXN * 8 * 2+ 1018 + 1108;//EDIT and *2
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to;
	ll cap;
}e[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].cap = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void CreateEdge(int from,int to,ll val){
	AddEdge(from,to,val);
	AddEdge(to,from,0);
	return ;
} 
int DFS_ED;//share 
int dep[MAXN],cur[MAXN];
bool BFS(int n,int ST,int ED){
	for(int i = 0;i <= n;i++){
		dep[i] = 0;
	}
	queue<int> q;
	dep[ST] = 1;
	q.push(ST);
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		cur[u] = head[u];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dep[v] != 0 || e[i].cap <= 0)continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	return (dep[ED] > 0);
}
int DFS(int u,ll val){
	if(u == DFS_ED || val == 0)return val;
	int ret = 0;
	for(int i = cur[u];i;i = e[i].nxt){
		const int v = e[i].to;
		cur[u] = i;
		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
		const ll realPush = DFS(v,min(e[i].cap,val));
		ret += realPush;
		val -= realPush;
		e[i].cap -= realPush;
		e[i^1].cap += realPush;
		if(realPush == 0)dep[v] = -1;
		if(val == 0)break;
	}
	return ret;
}
inline ll Dinic(int n,int ST,int ED){
	ll ret = 0;
	DFS_ED = ED;
	while(BFS(n,ST,ED)){
		ret += DFS(ST,INF);
	}
	return ret;
}
int n,m,dx[4],dy[4],no[MAXR][MAXR],nnt,p[MAXR][MAXR],pnt;
char MP[MAXR][MAXR];
inline bool Judge(int x,int y){
	return (x >= 1 && x <= n && y >= 1 && y <= m && MP[x][y] == '.');
}
void DFS(int kol,int x,int y){
	p[x][y] = kol;
	for(int k = 0;k < 4;k++){
		const int OX = x + dx[k],OY = y + dy[k];
		if(OX >= 1 && OX <= n && OY >= 1 && OY <= m && p[OX][OY] == 0){
			DFS(kol,OX,OY);
		}
	}
	for(int k = 0;k < 4;k++){
		const int OX = x - dx[k],OY = y - dy[k];
		if(OX >= 1 && OX <= n && OY >= 1 && OY <= m && p[OX][OY] == 0){
			DFS(kol,OX,OY);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2172.in","r",stdin);
	cin>>n>>m>>dx[0]>>dy[0];
	dx[1] = dx[0],dy[1] = -dy[0];
	dx[2] = dy[0],dy[2] = dx[0];
	dx[3] = dy[0],dy[3] = -dx[0];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
//			cin>>MP[i][j];
			no[i][j] = ++nnt;
			if(p[i][j] == 0){
				DFS(++pnt,i,j);
			}
			cout<<p[i][j];
		}
		cout<<endl;
	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			if(MP[i][j] == 'x')continue;
//			CreateEdge()
//		}
//	}
	return 0;
}
