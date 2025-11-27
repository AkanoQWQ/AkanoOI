#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 2006 + 1018 + 1108 + 1000;
bitset<MAXN> e[MAXN];
int n,cnt[MAXN];
inline void AddEdge(int u,int v){
	if(e[u][v])return ;
	e[u][v] = e[v][u] = true;
	cnt[u]++,cnt[v]++;
	return ;
}
inline void DelEdge(int u,int v){
	if(!e[u][v])return ;
	e[u][v] = e[v][u] = false;
	cnt[u]--,cnt[v]--;
	return ;
}
inline ll Solve(){
	ll ret = 0;
	for(int u = 1;u <= n;u++){
		ret += 1ll * (cnt[u]-1) * cnt[u];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("triples.in","r",stdin);
	freopen("triples.out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v);
	}
	for(int u = 1;u <= n;u++){
		cout<<Solve()<<endl;
		vector<int> con;
		for(int v = 1;v <= n;v++){
			if(e[u][v]){
				con.push_back(v);
				DelEdge(u,v);
			}
		}
		for(auto i1 : con){
			for(auto i2 : con){
				if(i1 != i2)AddEdge(i1,i2);
			}
		}
	}
	return not(Akano loves pure__Elysia);
}
