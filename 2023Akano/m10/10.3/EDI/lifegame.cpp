#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int MAXN = 1018;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int movex[4] = {1,1,-1,-1};
const int movey[4] = {1,-1,1,-1};
char mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int step[MAXN][MAXN];
int n,m,ans = 0;
vector<pii> imp;
inline bool Judge(int x,int y){
	return 1 <= x && x <= n && 1 <= y && y <= m && vis[x][y] == false && mp[x][y] == '#';
}
inline bool Check(int xStep){
	queue<pii> q;
	memset(vis,0,sizeof(vis));//可持久化vis数组?
	for(auto i : imp){
		vis[i.first][i.second] = true;
		step[i.first][i.second] = 1;
		q.push(i);
	}
	while(!q.empty()){
		const int ux = q.front().first,uy = q.front().second;
		q.pop();
		if(step[ux][uy] >= xStep)continue;
		for(int k = 0;k < 4;k++){
			const int OX = ux + dx[k],OY = uy + dy[k];
			if(Judge(OX,OY)){
				step[OX][OY] = step[ux][uy] + 1;
				vis[OX][OY] = true;
				q.push(make_pair(OX,OY));
			}
		}
	}
	for(auto i : imp){
		bool OK = false;
		for(int dtx = 0;dtx <= xStep && OK == false;dtx++){
			const int dty = xStep - dtx;
			for(int k = 0;k < 4;k++){
				int x = i.first + dtx * movex[k],y = i.second + dty * movey[k];
				if(Judge(x,y)){
					OK = true;
					break;
				}
			}
		}
		if(OK == false){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("lifegame.in","r",stdin);
	freopen("lifegame.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>mp[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(mp[i][j] =='.'){
				for(int k = 0;k < 4;k++){
					const int OX = i + dx[k],OY = j + dy[k];
					if(Judge(OX,OY)){
						imp.emplace_back(OX,OY);
						vis[OX][OY] = true;
					}
				}
			}
		}
	}
	int l = 1,r = n+1;
	while(l < r){
		const int mid = (l + r) >> 1;
		if(Check(mid)){
			l = mid+1;
		}else{
			r = mid;
		}
	}
	cout<<l-1<<endl;
	return not(Akano loves pure__Elysia);
}
