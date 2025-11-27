#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 6;
const int MAXM = 4e6 + 6; 
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt,n,m,dfn[MAXN],low[MAXN],dnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int bccs;
vector<int> BCC[MAXN]; 
stack<int> st;
inline void AddBCC(int u,int v){
	++bccs;
	while(!st.empty()){
		const int tp = st.top();
		st.pop();
		BCC[bccs].push_back(tp);
		if(tp == v)break;
	}
	BCC[bccs].push_back(u);
	return ;
}
void tarjan(int u,int fa){
	dfn[u] = ++dnt;
	low[u] = dfn[u];
	int son = 0;
	st.push(u);
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			++son;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]){
				AddBCC(u,v);
			}
		}else if(v != fa)low[u] = min(low[u],dfn[v]);
	}
	if(fa == 0 && son == 0)BCC[++bccs].push_back(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v);
		AddEdge(v,u); 
	}
	for(int i = 1;i <= n;i++){
		if(dfn[i])continue;
		//st.clear();
		tarjan(i,0);
	}
	cout<<bccs<<endl;
	for(int i = 1;i <= bccs;i++){
		cout<<BCC[i].size()<<" ";
		for(auto j : BCC[i])cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}
