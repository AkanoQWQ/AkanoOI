#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int MAXM = MAXN * 2 + 2006 + 1108;
int tot = 1,head[MAXN];
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
bool ins[MAXN],br[MAXN];
int dfn[MAXN],low[MAXN],cnt,SCC,sc[MAXN],fa[MAXN],sss;
void tarjan(int u,int father){
	dfn[u] = ++cnt;
	low[u] = cnt;
	fa[u] = father;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u]){
				cout<<v<<" to "<<u<<" is"<<endl;
				br[v] = 1;
				sss++;
			}
		}else if(dfn[v] < dfn[u] && v != father){
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u] == dfn[u]){
		SCC++;
		while(!s.empty()){
			ins[s.top()] = 0;
			//bel[s.top()] = SCC;
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
	freopen("easy2.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		AddEdge(a,b);
		AddEdge(b,a);
	}
	tarjan(1,1);
	cout<<sss;
	return 0;
}

