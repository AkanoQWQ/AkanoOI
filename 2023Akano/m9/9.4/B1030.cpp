#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,pre[MAXN],dis[MAXN],farpos;
void dfs(int u,int fa){
	pre[u] = fa,dis[u] = dis[fa] + 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
	}
	if(dis[u] > dis[farpos])farpos = u;
	return ;
}
vector<int> d;
inline void GetD(){
	int pos = farpos;
	while(pos){
		d.push_back(pos);
		pos = pre[pos];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 2;i <= n;i++){
		int fa;
		cin>>fa;
		AddEdge(fa,i),AddEdge(i,fa);
	}
	dfs(1,0);//不用清空,直接继承 
	dfs(farpos,0);
	GetD();
	int sz = d.size();
	if(sz & 1){
		cout<<d[sz / 2]<<endl;
	}else{
		if(d[(sz / 2) - 1] > d[sz / 2])swap(d[(sz / 2) - 1],d[sz / 2]);
		cout<<d[(sz / 2) - 1]<<" "<<d[sz / 2]<<endl;
	}
	return not(Akano loves pure__Elysia);
}
