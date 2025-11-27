#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006 + 1018 + 1108;
const int MAXM = (1e4 + 1018 + 1108) * 2;
const double EPS = 1e-8;
struct Edge{
	int nxt,to;
	double val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,double val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool OK;
double step[MAXN];
int t,n,m;
inline void Clear(){
	for(int i = 1;i <= n;i++)head[i] = 0,step[i] = 0;
	OK = true;
	cnt = 0;
	return ;
}
void dfs(int u){
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(fabs(step[v]) > 0){
			if(fabs(step[v] - step[u] * e[i].val) > EPS){
				OK = false;
			}
		}else{
			step[v] = step[u] * e[i].val;
			dfs(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	for(int nowt = 1;nowt <= t;nowt++){
		cin>>n>>m;
		Clear();
		for(int i = 1;i <= m;i++){
			int u,v,x,y;
			cin>>u>>v>>x>>y;
			AddEdge(u,v,double(x) / double(y));
			AddEdge(v,u,double(y) / double(x));
		}
		step[1] = 10;
		dfs(1);
		if(OK){
			cout<<"Case #"<<nowt<<": Yes"<<endl;
		}else{
			cout<<"Case #"<<nowt<<": No"<<endl;
		}
	}
	return 0;
}

