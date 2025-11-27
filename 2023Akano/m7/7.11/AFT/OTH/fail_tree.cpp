#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MAXN = 1018;
const int UP = 1108;
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
int T,n;
int nowl,nowr,nodecnt;
void dfs(int u,int fa){
	++nodecnt;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || v < nowl || v > nowr)continue;
		dfs(v,u);
	}
	return ;
}
inline int Solve(int no){//long long ? 
	int ret = 0;
	for(int l = 1;l <= n;l++){
		for(int r = l;r <= n;r++){
			nowl = l,nowr = r,nodecnt = 0;
			dfs(l,l);
			ret += (nodecnt == (r - l + 1));
		}
	}
	return ret;
}
inline void Clear(int n){
	for(int i = 0;i <= n;i++){
		head[i] = 0;
	}
	cnt = 0;
	return ;
}
int main(){
	freopen("./datas/tree/mytree.in","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	for(int turn = 1;turn <= T;turn++){
		cin>>n;
		Clear(n);
		for(int i = 1;i < n;i++){
			int u,v;
			cin>>u>>v;
			AddEdge(u,v),AddEdge(v,u);
		}
		cout<<Solve(turn)<<endl;
	}
	return 0;
}
