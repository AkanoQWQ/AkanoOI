#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 42006;//remember to EDIT
const int MAXM = 300000 + 2006 + 1018 + 1108;//EDIT and *2
const int MAXR = 106; 
const int INF = 1e8;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
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
int n,m,A[MAXR][MAXR],B[MAXR][MAXR],C[MAXR][MAXR],VST,VED,no[MAXR][MAXR][2],nnt;
ll sum;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P1935.in","r",stdin);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			no[i][j][0] = ++nnt,no[i][j][1] = ++nnt;
			CreateEdge(no[i][j][0],no[i][j][1],INF);
		}
	}
	VST = ++nnt,VED = ++nnt;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>A[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>B[i][j];
			if((i+j) & 1)swap(A[i][j],B[i][j]);
			sum += A[i][j] + B[i][j];
			CreateEdge(VST,no[i][j][0],A[i][j]);
			CreateEdge(no[i][j][1],VED,B[i][j]);
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>C[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 0;k < 4;k++){
				const int OX = i + dx[k],OY = j + dy[k];
				if(OX <= 0 || OX > n || OY <= 0 || OY > m)continue;
				const int TOTC = C[i][j] + C[OX][OY];
				if((i + j) & 1){
//					cout<<i<<","<<j<<" to "<<OX<<","<<OY<<" is "<<TOTC<<endl;
					sum += TOTC*2;
					const int no1 = ++nnt;
					CreateEdge(VST,no1,TOTC);
					CreateEdge(no1,no[i][j][0],INF),CreateEdge(no1,no[OX][OY][0],INF);
					const int no2 = ++nnt;
					CreateEdge(no2,VED,TOTC);
					CreateEdge(no[i][j][1],no2,INF),CreateEdge(no[OX][OY][1],no2,INF);
				}
			}
		}
	}
	ll DNC = Dinic(nnt,VST,VED);
//	cout<<DNC<<" ? dinic"<<endl;
	cout<<sum-DNC<<flush;
	return 0;
}
