#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 4e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXN * 3];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int T,n,m;
bool kol[MAXN];
inline void ReadIn(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		head[i] = 0;
	}
	cnt = 0;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	return ;
}
inline bool Judge(int u){
	int cntBefore = 0,cntAfter = 0;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		cntBefore += (kol[u] == kol[v]);
		cntAfter += (kol[u] != kol[v]);
	}
	return cntAfter < cntBefore;
}
inline void Solve(){
	for(int now = 1;now <= n;now++){
		queue<int> q;
		if(Judge(now)){
			q.push(now);
			kol[now] = !kol[now];	
		}
		while(!q.empty()){
			const int u = q.front();
			q.pop();
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(Judge(v)){
					q.push(v);
					kol[v] = !kol[v];	
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cout<<kol[i]<<" ";
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("classical.in","r",stdin);	
	freopen("classical.out","w",stdout);
	cin>>T;
	while(T--){
		ReadIn();
		Solve();
	}
	return not(Akano loves pure__Elysia);
}
