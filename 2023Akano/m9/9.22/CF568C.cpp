#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 406;
const int MAXM = 4 * MAXN * MAXN;
struct Edge{
	int nxt,to;
}e[MAXM * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
string s;
int siz,n,m,lst[MAXN][2],orgval[MAXN];
int trans[258];
inline int Fx(int x){//翻转
	if(x <= siz)return x + siz;
	return x - siz;
}
inline int Fn(int x){
	if(x <= n)return x + n;
	return x - n;
}
/*
契约:  
V 为 0，C 为 1
*/
bool vis[MAXN];
bool dfs(int u){
	if(vis[Fn(u)])return false;
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		bool suc = dfs(v);
		if(suc == false)return false;
	}
	return true;
}
inline bool Judge(int st){
	for(int i = 1;i <= 2*n;i++)vis[i] = false;
	for(int i = 1;i <= st;i++){
		bool suc = dfs(i + orgval[s[i] - 'a' + 1] * n);
		if(suc == false)return suc;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	trans['V'] = 0,trans['C'] = 1;
	cin>>s>>n>>m;
	siz = s.length();
	s = "." + s;
	for(int i = 1;i <= m;i++){
		int u,v;
		char uc,vc;
		cin>>u>>uc>>v>>vc;
		const int u1 = u + trans[int(uc)] * n;
		const int v2 = Fn(u1);
		const int v1 = v + trans[int(vc)] * n;
		const int u2 = Fn(v1);
		AddEdge(u1,v1),AddEdge(u2,v2);
	}
	{
	lst[siz+1][0] = lst[siz+1][1] = siz+1;
	int lstcnt[2] = {siz+1,siz+1};
	for(int i = siz;i >= 1;i--){
		orgval[i] = trans[int(s[i])];
		lstcnt[orgval[i]] = i;
		lst[i][0] = lstcnt[0],lst[i][1] = lstcnt[1];
	}
	}
	cin>>s;
	bool res = Judge(n);
	if(res == true){
		for(auto i : s)if(i != '.')cout<<i;
		cout<<endl;
		return not(Akano loves pure__Elysia);
	}
	
	return not(Akano loves pure__Elysia);
}
