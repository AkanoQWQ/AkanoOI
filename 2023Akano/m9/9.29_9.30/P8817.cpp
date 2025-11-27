#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1018 + 1108 + 500;
const int MAXM = 22006 + 1018 + 1108;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
bool reachable[MAXN][MAXN];
int dis[MAXN],mx[MAXN][5];
int n,m,k;
ll score[MAXN],ans;
inline void BFS(int ST){
	memset(dis,0,sizeof(dis));
	queue<int> q;
	q.push(ST);
	reachable[ST][ST] = true;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		if(dis[u] >= k)continue;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(reachable[ST][v] == true)continue;
			reachable[ST][v] = true;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	return ;
}
inline void Calc(int u){
	for(int v = 2;v <= n;v++){
		if(v == u || reachable[u][v] == false || reachable[1][v] == false)continue;
		if(score[v] > score[mx[u][1]]){
			mx[u][3] = mx[u][2];
			mx[u][2] = mx[u][1];
			mx[u][1] = v;
		}else if(score[v] > score[mx[u][2]]){
			mx[u][3] = mx[u][2];
			mx[u][2] = v;
		}else if(score[v] > score[mx[u][3]]){
			mx[u][3] = v;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	k++;
	for(int i = 2;i <= n;i++){
		cin>>score[i];
	}
	score[0] = -1e18;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= n;i++){
		BFS(i);
	}
	for(int i = 1;i <= n;i++){
		Calc(i);
	}
	for(int b = 2;b <= n;b++){
		for(int c = b+1;c <= n;c++){
			if(reachable[b][c] == false || b == c)continue;
			for(int bi = 1;bi <= 3;bi++){
				for(int ci = 1;ci <= 3;ci++){
					if(mx[b][bi] == mx[c][ci] || mx[b][bi] == c || mx[c][ci] == b || mx[b][bi] == 0 || mx[c][ci] == 0)continue;
					ans = max(ans,score[mx[b][bi]] + score[b] + score[c] + score[mx[c][ci]]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
