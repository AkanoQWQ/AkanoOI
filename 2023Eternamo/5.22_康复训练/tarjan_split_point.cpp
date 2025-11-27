#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 1108;
const int MAXM = 2e5 + 1018; 
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
vector<int> otp;
void tarjan(int u,int fa){
	bool INS = 0;
	dfn[u] = ++dnt;
	low[u] = dfn[u];
	int son = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!dfn[v]){
			++son;
			tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(INS == 0 && fa != 0 && low[v] >= dfn[u]){
				otp.push_back(u);
				INS = 1;
			}
		}else if(v != fa)low[u] = min(low[u],dfn[v]);
	}
	if(INS == 0 && fa == 0 && son >= 2){
		otp.push_back(u);
	}
	return ;
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
		tarjan(i,0);
	}
	sort(otp.begin(),otp.end());
	cout<<otp.size()<<endl;
	for(auto i : otp){
		cout<<i<<" ";
	}
	return 0;
}
