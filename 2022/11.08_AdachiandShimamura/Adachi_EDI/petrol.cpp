#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
const int MAXM = MAXN * 2;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,s,q;
bool add_fuel[MAXN];
struct Edge{
	int nxt,to,v,from;
}e[MAXM],tree_edge[MAXM];
bool cmp4e(Edge a,Edge b){
	return a.v < b.v;
}
int head[MAXN],tot = 1,t2 = 0;
void AddEdge(int from,int to,int v){
	e[++tot].to = to;
	e[tot].from = from;
	e[tot].v = v;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
bool inq[MAXN];
int dis[MAXN],near[MAXN];
queue<int> sq;
void SPFA(){
	while(!sq.empty())sq.pop();
	for(int i = 1;i <= n;i++){
		inq[i] = 0;
		dis[i] = 0x7fffffff;
		if(add_fuel[i]){
			inq[i] = 1;
			dis[i] = 0;
			near[i] = i;
			sq.push(i);
		}
	}
	while(!sq.empty()){
		const int u = sq.front();
		sq.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[u] + e[i].v < dis[v]){
				near[v] = near[u];
				dis[v] = dis[u] + e[i].v;
				if(inq[v])continue;
				inq[v] = 1;
				sq.push(v);
			}
		}
	}
	return ;
}
struct ask{
	int u,v,b,no;
}asq[MAXN];
bool cmp4a(ask a,ask b){
	return a.b < b.b;
}
struct save_edges{
	int u,v,w;
}edges2[MAXM/2];
int eeetot,fa[MAXN];
int getfa(int x){
	if(fa[x] == x)return x;
	fa[x] = getfa(fa[x]);
	return fa[x];
}
bool ans[MAXN];
int main(){
	freopen("petrol.in","r",stdin);
	freopen("petrol.out","w",stdout);
	n = read(),s = read(),m = read();
	for(int i = 1;i <= s;i++){
		int c = read();
		add_fuel[c] = 1;
	}
	while(m--){
		int u = read(),v = read(),d = read();
		edges2[++eeetot].u = u;
		edges2[eeetot].v = v;
		edges2[eeetot].w = d;
		AddEdge(u,v,d);
		AddEdge(v,u,d);
	}
	SPFA();
	for(int i = 1;i <= eeetot;i++){
		const int u = edges2[i].u;
		const int v = edges2[i].v;
		const int w = edges2[i].w;
		if(near[u] == near[v]){
			cout<<"skip"<<i<<endl;
			continue;
		}
		cout<<"add "<<t2+1<<" in ";
        cout<<near[u]<<" "<<near[v]<<endl;
		tree_edge[++t2].from = near[u];
		tree_edge[t2].to = near[v];
		tree_edge[t2].v = w + dis[u] + dis[v];
	}
	q = read();
	for(int i = 1;i <= q;i++){
		asq[i].u = read(),asq[i].v = read(),asq[i].b = read();
		asq[i].no = i;
	}
	sort(asq+1,asq+q+1,cmp4a);
	sort(tree_edge+1,tree_edge+t2+1,cmp4e);
	int tail = 1;
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= q;i++){
		while(tail <= t2 && tree_edge[tail].v <= asq[i].b){
			int a = tree_edge[tail].from,b = tree_edge[tail].to;
			if(getfa(a) != getfa(b)){
				fa[getfa(a)] = b;
			}
			if(i<=10000)cout<<tree_edge[tail].v<<"compare"<<asq[i].b<<" ";
			tail++;
			if(i<=10000)cout<<i<<":"<<tail<<endl;
		}
		if(getfa(asq[i].u) != getfa(asq[i].v)){
			ans[asq[i].no] = 0;
		}else{
			ans[asq[i].no] = 1;
		}
		//cout<<(getfa(asq[i].u) == getfa(asq[i].v))<<endl;
	}
	for(int i = 1;i <= q;i++){
		if(ans[i]){
	//		puts("TAK");
		}else{
	//		puts("NIE");
		}
	}
	return 0;
}
