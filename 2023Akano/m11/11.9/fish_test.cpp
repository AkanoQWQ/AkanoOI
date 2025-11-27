#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
constexpr int MAXN = 1e6 + 1018 + 1108;
constexpr int MOD = 1e9 + 7;
constexpr int inv2 = (MOD+1) / 2;
struct Edge{
	int nxt,to;
	ull val;
	bool ban;
}e[MAXN * 2];
int head[MAXN],cnt = 1;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
mt19937_64 rng(time(0));
unordered_map<ull,int> udm;
int n,m,dep[MAXN],block;
bool vis[MAXN];
ull pointvalue[MAXN],ans,case2,case3;
void dfs(int u){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(e[i].ban)continue;
		e[i^1].ban = true;
		if(!vis[v]){
			dep[v] = dep[u] + 1;
			dfs(v);
		}else{
			ull hashval = rng();
			pointvalue[u] ^= hashval,pointvalue[v] ^= hashval,e[i].val ^= hashval;
		}
	}
	return ;
}
void dfs2(int u,int frome){
	vis[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(vis[v])continue;
		if(e[i].ban)continue;
		dfs2(v,i);
		pointvalue[u] ^= e[i].val;
	}
	e[frome].val = pointvalue[u];//?
	return ;
}
vector<int> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("fish/fish3.in","r",stdin);
	cin>>n>>m;
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			if(head[i] == 0)block--;
			block++;
			dfs(i);
			st.push_back(i);
		}
	}
	for(int i = 1;i <= n;i++)vis[i] = false;
	for(auto i : st){
		dfs2(i,0);
	}
	case3 = 1;
	if(m - n + block - 2 > 0){
		for(int i = 1;i <= m - n + block - 2;i++){
			case3 = (case3 * 2) % MOD;
		}
	}else{
		const int v = -(m - n + block - 2);
		for(int i = 1;i <= v;i++){
			case3 = (case3 * inv2) % MOD;
		}
	}
	case2 = (case3 * 2) % MOD;
	for(int i = 2;i <= cnt;i++){
		if(e[i].ban)continue;
		udm[e[i].val]++;
	}
	cerr<<case2<<" and "<<case3<<endl;
	for(int u = 1;u <= n;u++){
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(e[i].ban)continue;
			cerr<<u<<" - "<<v<<" val "<<e[i].val<<endl;
		}
	}
	for(auto i : udm){
		ull res = m - i.second;
		ans = (ans + ((1ll * i.second * res) % MOD) * case3) % MOD;
		if(i.first != 0){
			ans = (ans + ((1ll * i.second * (i.second-1)) % MOD) * case2) % MOD;
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
