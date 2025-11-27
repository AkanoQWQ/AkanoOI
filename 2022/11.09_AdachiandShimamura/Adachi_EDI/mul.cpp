#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5006;
const int MAXM = 150006;
const int INF = 0x7fffffff;
const int st = 0;
const int ed = 206;
int n,m,tot = 1,head[MAXN],mincost,maxflow;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct Edge{
	int to,cap,nxt;	
}e[MAXM];
void AddEdge(int u,int v,int cap){
	e[++tot].cap = cap;
	e[tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
	return ;
}
int dep[MAXN];
queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	memset(dep,0,sizeof(dep));
	q.push(st);
	dep[st] = 1;
	while(!q.empty()){
		const int u = q.front();
		//cout<<"vis "<<u<<endl;
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(!dep[v] && e[i].cap > 0){
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[ed];
}
int dfs(int u,int val){
	if(u == ed || val == 0)return val;
	int ret = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].cap <= 0 || dep[v] != dep[u]+1)continue;
		int goto_awa = min(e[i].cap,val);
		if(goto_awa <= 0)continue;
		int real_uwu = dfs(v,goto_awa);
		ret += real_uwu;
		e[i].cap -= real_uwu;
		e[i^1].cap += real_uwu;
		val -= real_uwu;
	}
	return ret;
}
void Dinic(){
	while(bfs()){
		maxflow += dfs(st,INF);
	}
	return ;
}
int zx = 0;
int main(){
	freopen("mul.in","r",stdin);
	freopen("mul.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		x = -x;
		for(int j = i*2;j <= n;j += i){
			AddEdge(i,j,INF);
			AddEdge(j,i,0);
		}
		if(x > 0){
			AddEdge(st,i,x);
			AddEdge(i,st,0);
		}else{
			zx -= x;
			AddEdge(i,ed,-x);
			AddEdge(ed,i,0);
		}
	}
	Dinic();
	cout<<zx-maxflow;
	return 0;
}
