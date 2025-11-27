#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1108 + 1018;
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
int mx[MAXN],nowL;
void dfs(int u,int fa,int nowmx){
	mx[u] = nowmx;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || v < nowL)continue;
		dfs(v,u,max(nowmx,v));
	}
	return ;
}
inline int Solve(int no){//long long ? 
	int ret = 0;
	for(int l = 1;l <= n;l++){
		for(int i = 0;i <= n;i++)mx[i] = 0;
		nowL = l;
		dfs(l,l,l);
		mx[l-1] = 0;
		for(int r = l;r <= n;r++){
			if(mx[r] == 0)break;//cant reach r
			mx[r] = max(mx[r],mx[r-1]);
			ret += (mx[r] <= r);
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
	freopen("B7023.in","r",stdin);
	freopen("B7023.ans","w",stdout);
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
