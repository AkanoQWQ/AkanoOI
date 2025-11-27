#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
struct Edge{
	int to,nxt;
}e[MAXN];
int head[MAXN],cnt,n,q,tot;
void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool vis[MAXN],cir[MAXN],FIND_CIR,ST_DIS;
int pre[MAXN],dep[MAXN],no[MAXN],dis[MAXN]; 
void dfs(int u,int from){
	if(FIND_CIR)return ;
	if(vis[u]){
		int pos = pre[u];
		while(pos != u){
			cir[pos] = 1;
			pos = pre[pos];
		}
		cir[u] = 1;
		FIND_CIR = 1;
		return ;
	}
	vis[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == from)continue;
		pre[v] = u;
		dfs(v,u);
	}
	return ;
}
void dfs2(int u,int deep,int from,int noo){
	dep[u] = deep,no[u] = noo;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == from || cir[v])continue;
		dfs2(v,deep+1,u,noo);
	}
	return ;
}
int MAIN_U,END_DIS = 0,cir_dis[MAXN];
void dfs3(int u,int nowdis,int from){
	cir_dis[u] = nowdis;
	if(END_DIS)return ;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == MAIN_U){
			END_DIS = 1;
			return ;
		}
		if(v != from){
			dfs3(v,nowdis+1,u);
			break;
		}
	}
	return ;
}
int main(){
	n = read(),q = read();
	while(q--){
		puts("Survive");
	}
	return 0;
}
