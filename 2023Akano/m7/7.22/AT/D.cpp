#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAXN = 206;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int n,m;
bool vis[MAXN][MAXN][4],cnted[MAXN][MAXN];
char mp[MAXN][MAXN];
int BFS(int STX,int STY){
	int ret = 0;
	queue<pair<pii,int> > q;
	for(int i = 0;i < 4;i++){
		vis[STX][STY][i] = true;
		q.push(make_pair(make_pair(STX,STY),i));
	}
	while(!q.empty()){
		const auto now = q.front();
		q.pop();
		auto u = now.first;
		if(!cnted[u.first][u.second]){
			cnted[u.first][u.second] = true;
			++ret;
		}
		int dir = now.second;
		const int OX = u.first + dx[dir],OY = u.second + dy[dir];
		if(mp[OX][OY] == '#'){
			for(int k = 0;k < 4;k++){
				if(!vis[u.first][u.second][k]){
					vis[u.first][u.second][k] = true;
					q.push(make_pair(u,k));
				}
			}
		}else{
			if(!vis[OX][OY][dir]){
				vis[OX][OY][dir] = true;
				q.push(make_pair(make_pair(OX,OY),dir));
			}
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
		}
	}
	cout<<BFS(2,2);
	return 0;
}

