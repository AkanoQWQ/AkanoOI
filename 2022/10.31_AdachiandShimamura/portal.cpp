#include<bits/stdc++.h>
using namespace std;
const int MAXN = 566;
const int MAXM = MAXN*MAXN*7;
const int MAXP = MAXN*MAXN;
const int INF = 0x7fffffff;
const int movex[4] = {0,1,0,-1};
const int movey[4] = {1,0,-1,0};//ri,dow,le,upp
int head[MAXP],etot;
struct Edge{
	int nxt,to,v;
}e[MAXM];
void AddEdge(int frm,int to,int v){
	e[++etot].to = to;
	e[etot].nxt = head[frm];
	e[etot].v = v;
	head[frm] = etot;
	return ;
}
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n,m,tot,no[MAXN][MAXN],st,ed;
char mp[MAXN][MAXN];
int dis[MAXP];
bool inq[MAXP];
queue<int> q;
void SPFA(){
	for(int i = 0;i <= n*m+1;i++)dis[i] = INF;
	memset(inq,0,sizeof(inq));
	while(!q.empty())q.pop();
	dis[st] = 0;
	q.push(st);
	inq[st] = 1;
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[u] + e[i].v < dis[v]){
				dis[v] = dis[u] + e[i].v;
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("portal.in","r",stdin);
	freopen("portal.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			while(1){
				mp[i][j] = getchar();
				if(mp[i][j] == '#'||mp[i][j] == '.'||mp[i][j] == 'C'||mp[i][j] == 'F')break;
			}
			no[i][j] = ++tot;
			if(mp[i][j] == 'C'){
				st = no[i][j];
			}else if(mp[i][j] == 'F'){
				ed = no[i][j];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int ps[4][3];
			memset(ps,0,sizeof(ps));
			for(int k = 0;k < 4;k++){
				const int OX = i + movex[k];
				const int OY = j + movey[k];
				if(mp[OX][OY] != '#' && mp[i][j] != '#'){
					AddEdge(no[i][j],no[OX][OY],1);
				}
				if(mp[i][j] == '#')continue;
				int x = i,y = j;
				while(x > 0 && y > 0 && x <= n && y <= m){
					if(mp[x+movex[k]][y+movey[k]] == '#'){
						ps[k][0] = x;
						ps[k][1] = y;
						break;
					}
					ps[k][2]++;
					x += movex[k],y += movey[k];
				}
			}
			for(int s = 0;s < 4;s++){
				if(ps[s][1] == 0)continue;
				for(int k = 0;k < 4;k++){
					if(ps[k][1] == 0)continue;
					AddEdge(no[i][j],no[ps[s][0]][ps[s][1]],ps[k][2]+1);
				}
			}
			
		}
	}
	SPFA();
	if(dis[ed] == INF){
		printf("nemoguce");
	}else{
		printf("%d",dis[ed]);
	}
	return 0;
}
