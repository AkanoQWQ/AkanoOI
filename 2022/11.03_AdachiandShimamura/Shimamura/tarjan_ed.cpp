#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int MAXM = MAXN * 2 + 2006 + 1108;
int tot,head[MAXN];
struct Edge{
	int nxt,to;
	bool able;
}e[MAXM];
void AddEdge(int from,int to){
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
	return ;
}
pair<int,int> edges[MAXN];
int n,m;
stack<int> s;
bool ins[MAXN];
int dfn[MAXN],low[MAXN],cnt,SCC,sc[MAXN],bel[MAXN];
void tarjan(int u){
	dfn[u] = ++cnt;
	low[u] = cnt;//dep
	s.push(u);
	ins[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		//if(e[i].able == false)continue;
		const int v = e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		SCC++;
		while(!s.empty()){
			ins[s.top()] = 0;
			bel[s.top()] = SCC;
			if(s.top() == u){
				s.pop();
				break;
			}
			s.pop();
		}
	}
	return ;
}
int main(){
	freopen("tarjan.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		AddEdge(a,b);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
		cout<<bel[i]<<" ";
	}
	return 0;
}

