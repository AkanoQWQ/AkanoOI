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
bool vis[MAXN];
stack<int> s;
bool fd[MAXN];
int fa[MAXN],TOSTC[MAXN],STC[MAXN],STCNT;
int find(int x){
	if(fa[x] == x)return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
bool ins[MAXN];
void dfs(int u,int father){
	s.push(u);
	ins[u] = 1;
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v != father){
			if(vis[v] && ins[v] && ins[u]){
				while(!s.empty()){
					const int tp = s.top();
					ins[tp] = 0;
					s.pop();
					fa[find(tp)] = find(v);
					if(tp == v){
						break;
					}
				}
			}else if(vis[v] == 0){
				dfs(v,u);
			}
		}
	}
	return ;
}
int ans[MAXM],sz[MAXN],visnum;
bool OK = 0;
void dfs2(int u,int tc,int start){
	if(OK)return ;
	vis[u] = 1;
	visnum++;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if((vis[v] == 0)&& STC[v] == tc){
			if(i % 2 == 0){
				if(OK == 0)ans[i/2] = 1;
			}else{
				if(OK == 0)ans[i/2] = 2;
			}
			dfs2(v,tc,start);
		}
		if(v == start){
			if(visnum >= sz[tc]){
				if(i % 2 == 0){
					if(OK == 0)ans[i/2] = 1;
				}else{
					if(OK == 0)ans[i/2] = 2;
				}
				OK = 1;
			}
		}
	}
	vis[u] = 0;
	visnum--;
	return ;
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		AddEdge(a,b);
		AddEdge(b,a);
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	dfs(1,1);
	for(int i = 1;i <= n;i++){
		if(TOSTC[find(i)] == 0){
			TOSTC[find(i)] = ++STCNT;
		}
		sz[TOSTC[find(i)]]++;
		STC[i] = TOSTC[find(i)];
	}
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;i++){
		OK = 0;
		if(fd[STC[i]] == 0)dfs2(i,STC[i],i);
		fd[STC[i]] = 1;
	}
	for(int i = 1;i <= m;i++){
		if(ans[i] != 0){
			putchar(ans[i]+'0');
		}else{
			if(STC[e[i*2].to] == STC[e[i*2+1].to]){
				putchar('1');
			}else{
				putchar('0');
			}
		}
	}
	return 0;
}

