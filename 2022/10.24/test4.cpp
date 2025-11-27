#include<bits/stdc++.h>
using namespace std;
const int MAXN = 106;
const int N = 106;
const int MAXM = 20060;
struct edge{
	int nex,to;
}e[MAXM];
int tot,head[MAXN];
void AddEdge(int f,int t){
	e[++tot].to = t;
	e[tot].nex = head[f];
	head[f] = tot;
	return ;
}
int n;

int low[N] , dfn[N] , dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;  // 结点 i 所在 SCC 的编号
int sz[N];       // 强连通 i 的大小

void tarjan(int u) {
  low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
  for (int i = head[u]; i; i = e[i].nex) {
    const int &v = e[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (s[tp] != u) {
      scc[s[tp]] = sc;
      sz[sc]++;
      in_stack[s[tp]] = 0;
      --tp;
    }
    scc[s[tp]] = sc;
    sz[sc]++;
    in_stack[s[tp]] = 0;
    --tp;
  }
}





int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int a;
		cin>>a;
		AddEdge(i,a);
	}
	for(int i = 1;i <= n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i = 1;i <= sc;i++){
		cout<<sz[i]<<" ";
	}
	return 0;
}

