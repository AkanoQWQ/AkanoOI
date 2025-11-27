#include<bits/stdc++.h>
using namespace std;
const int MAXR = 22;
const int MAXN = 806;//remember to EDIT
const int MAXM = 50000 + 2006 + 1018 + 1108;//EDIT and *2
const int INF = 1018;
using ll = long long;
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
int r,c,d,VST,VED;
inline int No(int x,int y){
	return (x-1) * c + y - 1;
}
int h[MAXR][MAXR],no[MAXR][MAXR][2],nnt,sum;
bool HV[MAXR][MAXR];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>r>>c>>d;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			char ch;
			cin>>ch;
			h[i][j] = ch - '0';
			if(h[i][j] == 0)continue;
			no[i][j][0] = nnt++;
			no[i][j][1] = nnt++;
			CreateEdge(no[i][j][0],no[i][j][1],h[i][j]);
		}
	}
	VST = nnt++,VED = nnt++; 
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			char ch;
			cin>>ch;
			HV[i][j] = (ch == 'L');
			sum += HV[i][j];
			if(h[i][j] == 0)continue;
			if(HV[i][j]){
				CreateEdge(VST,no[i][j][0],1);
			}
			bool TO_ED = false;
			for(int dx = -d;dx <= d;dx++){
				for(int dy = -d;dy <= d;dy++){
					if(dx*dx + dy*dy > d*d)continue;
					if(dx == 0 && dy == 0)continue;
					const int OX = i + dx,OY = j + dy;
					if(OX <= 0 || OX > r || OY <= 0 || OY > c){
						if(TO_ED)continue;
						TO_ED = true;
						CreateEdge(no[i][j][1],VED,INF);
					}else{
						if(h[OX][OY] == 0)continue;
						CreateEdge(no[i][j][1],no[OX][OY][0],INF);
					}
				}
			}
		}
	}
	cout<<(sum) - Dinic(VED,VST,VED)<<flush;
	return 0;
}
