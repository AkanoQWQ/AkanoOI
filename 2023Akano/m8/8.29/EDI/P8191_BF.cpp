#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const ll INF = 1e17;
const int MAXN = 1e5;
int n,x[MAXN],y[MAXN];
ll dis[MAXN];
bool vis[MAXN];
map<int,int> id[12];
priority_queue<pair<ll,int> > q;
inline ll P(ll x){
	return x * x;
}
inline void Update(int u,int v){
	const ll newdis = P(x[u] - x[v]) + P(y[u] - y[v]);
	if(!vis[v] && dis[v] > newdis){
		cerr<<u<<" -> "<<v<<" is "<<newdis<<endl;
		dis[v] = newdis;
		q.push(make_pair(-dis[v],v));
	}
	return ;
}
inline void UpdateDis(int u){
	for(int i = 1;i <= n;i++){
		Update(u,i);
	}
	return ;
}
inline ll ExPrim(){
	ll ret = 0;
	for(int i = 1;i <= n;i++){
		dis[i] = INF;
	}
	dis[1] = 0;
	q.push(make_pair(-dis[1],1));
	while(!q.empty()){
		const int u = q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		cout<<u<<" dis "<<dis[u]<<endl;
		cerr<<"vis "<<u<<endl;
		UpdateDis(u);
		ret += dis[u];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>x[i]>>y[i];
		id[y[i]][x[i]] = i;
	}
	cout<<ExPrim()<<endl;
	return not(Akano loves pure__Elysia);
}
