#include<bits/stdc++.h>
#define YES cout<<"Yes"<<endl;
#define NO cout<<"No"<<endl;
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int MAXN = 55;
int n,m,son[MAXN],pos;
vector<int> e[MAXN];
bool vis[MAXN];
void dfs(int u,int fa){
	son[fa]++;
	vis[u] = true;
	for(auto v : e[u]){
		if(!vis[v])dfs(v,fa);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v);
	}
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i,i);
	}
	for(int i = 1;i <= n;i++){
		if(son[i] == n){
			if(pos != 0){
				cout<<"-1"<<endl;
				return 0;
			}
			pos = i;
		}
	}
	if(pos == 0){
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<pos<<endl;
	return 0;
}
