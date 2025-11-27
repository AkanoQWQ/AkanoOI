#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int MAXN = 5e4 + 1018 + 1108;
const int MAXTAIL = 406;
int n,m,k,q,tot,tail;
string mp[MAXN];
vector<int> bel[MAXN];
bool e[MAXTAIL][MAXTAIL];
int no[MAXN];
inline void BFS(int stX,int stY,int nowkol){
	queue<pii> q;
	q.push(make_pair(stX,stY));
	bel[stX][stY] = nowkol;
	while(!q.empty()){
		const pii u = q.front();
		q.pop();
		for(int dir = 0;dir < 4;dir++){
			const int OX = u.first + dx[dir],OY = u .second + dy[dir];
			if(1 <= OX && OX <= n && 1 <= OY && OY <= m && bel[OX][OY] == 0 && mp[OX][OY] == '.'){
				bel[OX][OY] = nowkol;
				q.push(make_pair(OX,OY));
			}
		}
	}
	return ;
}
inline void Floyd(){
	for(int kth = 1;kth <= tail;kth++){
		for(int i = 1;i <= tail;i++){
			for(int j = 1;j <= tail;j++){
				e[i][j] = e[i][j] | (e[i][kth] & e[kth][j]);
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n>>m>>k>>q;
	for(int i = 1;i <= n;i++){
		cin>>mp[i];
		mp[i] = "." + mp[i];
		bel[i].resize(m+2);
	}
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= m;y++){
			if(bel[x][y] == 0 && mp[x][y] == '.')BFS(x,y,++tot);
		}
	}
	for(int i = 1;i <= k;i++){
		int u,v,x,y;
		cin>>x>>y;
		u = bel[x][y];
		cin>>x>>y;
		v = bel[x][y];
		if(no[u] == 0)no[u] = ++tail;
		if(no[v] == 0)no[v] = ++tail;
		u = no[u],v = no[v];
		e[u][v] = true;
	}
	for(int i = 1;i <= tail;i++){
		e[i][i] = true;
	}
	Floyd();
	for(int i = 1;i <= q;i++){
		int u,v,x,y;
		cin>>x>>y;
		u = bel[x][y];
		cin>>x>>y;
		v = bel[x][y];
		if(u == v){
			cout<<"1\n";
		}else if(no[u] == 0 || no[v] == 0){
			cout<<"0\n";
		}else{
			u = no[u],v = no[v];
			cout<<e[u][v]<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}

