#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXE = 55;
const int MAXN = 206;//remember to EDIT
const int MAXM = (2006 + 1018 + 1108) * 2;//EDIT and *2
const int INF = 0x7fffffff;
const double EPS = 1e-6;
struct Edge{
	int nxt,to;
	double cap;
}e[MAXM];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to,double val){
	e[++cnt].to = to;
	e[cnt].cap = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline void CreateEdge(int from,int to,double val){
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
			if(dep[v] != 0 || e[i].cap <= EPS)continue;
			dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
	return (dep[ED] > 0);
}
double DFS(int u,double val){
	if(u == DFS_ED || val == 0)return val;
	double ret = 0;
	for(int i = cur[u];i;i = e[i].nxt){
		const int v = e[i].to;
		cur[u] = i;
		if(e[i].cap <= 0 || dep[v] != dep[u] + 1)continue;
		const double realPush = DFS(v,min(e[i].cap,val));
		ret += realPush;
		val -= realPush;
		e[i].cap -= realPush;
		e[i^1].cap += realPush;
		if(realPush == 0)dep[v] = -1;
		if(val == 0)break;
	}
	return ret;
}
inline double Dinic(int n,int ST,int ED){
	double ret = 0;
	DFS_ED = ED;
	while(BFS(n,ST,ED)){
		ret += DFS(ST,INF);
	}
	return ret;
}
int nnt,VST,VED;
int n,m,enemy[MAXE],weapon[MAXE],h[MAXE],atk[MAXE],sum;
bool atkable[MAXE][MAXE];
inline bool Judge(double x){
	for(int i = 1;i <= nnt;i++)head[i] = 0;
	cnt = 1;
	for(int i = 1;i <= m;i++){
		CreateEdge(VST,weapon[i],x * atk[i]);
	}
	for(int i = 1;i <= n;i++){
		CreateEdge(enemy[i],VED,h[i]);
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			if(atkable[i][j]){
				CreateEdge(weapon[i],enemy[j],INF);
			}
		}
	}
	double maxflow = Dinic(nnt,VST,VED);
	if(maxflow > sum - EPS)return true;
	return false;
}
inline double Solve(){
	double l = 0,r = 6e5;
	while(r - l > EPS){
		const double mid = (l + r) / 2;
		if(Judge(mid)){
			r = mid;
		}else{
			l = mid + EPS;
		}
	}
	return r;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	VST = ++nnt,VED = ++nnt;
	for(int i = 1;i <= n;i++){
		cin>>h[i];
		sum += h[i];
		enemy[i] = ++nnt;
	}
	for(int i = 1;i <= m;i++){
		cin>>atk[i];
		weapon[i] = ++nnt;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			cin>>atkable[i][j];
		}
	}
	cout<<fixed<<setprecision(6)<<Solve()<<endl;
	return 0;
}
