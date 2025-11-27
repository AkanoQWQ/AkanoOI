#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
using vi = vector<int>;
using pii = pair<int,int>;
int n,r,c,ret,ans,door[MAXN];
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
pii p[MAXN];
map<pii,int> pos;
vi xVec,yVec,xline[MAXN],yline[MAXN],to[MAXN];
bool vis[MAXN];
int dfs(int u){
	int ret = 0;
	vis[u] = true;
	if(door[u] == 1){
		for(auto v : xline[p[u].first]){
			if(!vis[v]){
				ret = max(ret,dfs(v));
			}
		}
	}else if(door[u] == 2){
		for(auto v : yline[p[u].second]){
			if(!vis[v]){
				ret = max(ret,dfs(v));
			}
		}
	}else{
		for(auto v : to[u]){
			if(!vis[v]){
				ret = max(ret,dfs(v));
			}
		}
	}
	vis[u] = false;
	return ret + 1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P2043.in","r",stdin);
	freopen("P2043.ans","w",stdout);
	cin>>n>>r>>c;
	for(int i = 1;i <= n;i++){
		cin>>p[i].first>>p[i].second>>door[i];
		xVec.push_back(p[i].first),yVec.push_back(p[i].second);
	}
	sort(xVec.begin(),xVec.end()),sort(yVec.begin(),yVec.end());
	auto it1 = unique(xVec.begin(),xVec.end()),it2 = unique(yVec.begin(),yVec.end());
	xVec.erase(it1,xVec.end()),yVec.erase(it2,yVec.end());
	for(int i = 1;i <= n;i++){
		for(int k = 0;k < 8;k++){
			const int OX = p[i].first + dx[k],OY = p[i].second + dy[k];
			if(pos.find(make_pair(OX,OY)) != pos.end()){
				const int v = pos[make_pair(OX,OY)];
				if(door[i] == 3){
					to[i].push_back(v);
				}
				if(door[v] == 3){
					to[v].push_back(i);
				}
			}
		}
		pos[p[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		p[i].first = lower_bound(xVec.begin(),xVec.end(),p[i].first) - xVec.begin() + 1;
		p[i].second = lower_bound(yVec.begin(),yVec.end(),p[i].second) - yVec.begin() + 1;
		xline[p[i].first].push_back(i);
		yline[p[i].second].push_back(i);
	}
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis));
		ret = 0;
		ans = max(ans,dfs(i));
	}
	cout<<ans<<endl;
	return 0;
}
