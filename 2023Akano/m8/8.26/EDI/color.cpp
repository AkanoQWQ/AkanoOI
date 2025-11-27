#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves <
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int TOT_MAXN = 1e5 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[TOT_MAXN * 2];
int head[TOT_MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
vector<int> st;
ll n,c,m;
namespace Subtask1{
	const int MAXN = 22;
	int kol[MAXN];
	bool have[MAXN];
	inline int Calc(){
		for(int u = 1;u <= n;u++){
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(kol[u] == kol[v])return 0;
			}
		}
		for(int i = 1;i <= c;i++)have[i] = false;
		for(auto u : st)have[kol[u]] = true;
		int ret = 0;
		for(int i = 1;i <= c;i++)ret += have[i];
		return ret;
	}
	int dfs(int dep){
		if(dep >= n+1){
			return Calc();
		}
		int ret = 0;
		for(int i = 1;i <= c;i++){
			kol[dep] = i;
			ret += dfs(dep+1);
		}
		return ret;
	}
	inline int Solve(){
		return dfs(1);
	}
}
namespace Subtask2{
	inline ll Solve(){
		ll ret = c;
		for(int i = 2;i <= n;i++){
			ret = (ret * (c-1)) % MOD;
		}
		return ret;
	}
}
namespace Subtask3{
	inline ll Solve(){
		ll ret = c,delta = (1ll * (c-1) * c) % MOD;
		for(int i = 2;i <= n;i++){
			ret = (ret * (c-1)) % MOD;
			ret = (ret + delta) % MOD;
			delta = (delta * (c-2)) % MOD;
		}
		return ret;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n>>c>>m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= m;i++){
		int c;
		cin>>c;
		st.push_back(c);
	}
	if(n <= 16 && c <= 16){
		cout<<Subtask1::Solve()<<endl;
	}else if(m == 1){
		cout<<Subtask2::Solve()<<endl;
	}else if(m == n){
		cout<<Subtask3::Solve()<<endl;
	}
	return (Akano loves pure__Elysia);
}
