#include<bits/stdc++.h>
using namespace std; 
#define int long long
int INF; 
const int dx[] = {0, 0, -1, 1}; const int dy[] = {-1, 1, 0, 0}; struct Graph{ 	static const int MAXM=200000+10; 	static const int MAXN=10000+10; 	struct Edge{ 		int from,to,cap; 		int next; 	}node[MAXM]; 	int head[MAXN],top; 	void init(){ 		top=1; 		memset(head, 0, sizeof(head)); 		s = MAXN - 1; 		t = MAXN - 2; 	} 	void add(int u,int v,int cap){ 		top++; 		node[top].next=head[u]; 		node[top].from=u; 		node[top].to=v; 		node[top].cap=cap; 		head[u]=top; 		top++; 		node[top].next=head[v]; 		node[top].from=v; 		node[top].to=u; 		node[top].cap=0; 		head[v]=top; 	} 	int s,t; 	int dis[MAXN]; 	queue<int> Q; 	bool bfs(){ 		memset(dis,-1,sizeof(dis)); 		Q.push(s); 		dis[s]=0; 		while(!Q.empty()){ 			int u=Q.front(); 			Q.pop(); 			for(int i=head[u];i;i=node[i].next){ 				int v=node[i].to; 				if(dis[v]==-1&&node[i].cap){ 					dis[v]=dis[u]+1; 					Q.push(v); 				} 			} 		} 		return dis[t]!=-1; 	} 	
int dfs(int u,int flow){ 	
	if(u==t) 	
		return flow; 
	else{ 	
		int ret=flow; 	
		for(int i=head[u];i&&ret;i=node[i].next){ 	
			int v=node[i].to; 		
			if(dis[v]==dis[u]+1&&node[i].cap){ 		
				int k=dfs(v,min(ret,node[i].cap)); 	
				node[i].cap-=k; 				
				node[i^1].cap+=k; 				
				ret-=k; 			
			} 	
		} 		
		if(ret == flow) 		
		dis[u] = -1; 			
		return flow-ret; 	
	} 	
} 	
int dinic(){
 		int ans=0; 	
		 	while(bfs()) 		
			 	ans+=dfs(s,INF); 	
				 	return ans; 
					 	} }G; 
#define POINT(X, Y) ((X) * 40 + (Y)) 
int T, n, m; int a[100][100]; bool check(int val) { 	G.init(); 	int sum = 0; 	for(int i = 1; i <= n; i ++) { 		for(int j = 1; j <= m; j ++) { 			if((i + j) % 2 == 0) {				G.add(G.s, POINT(i, j), val - a[i][j]); 				sum += val - a[i][j]; 				for(int k = 0; k < 4; k ++) { 					int tx = i + dx[k]; 					int ty = j + dy[k]; 					if(tx >= 1 && tx <= n && ty >= 1 && ty <= m) { 						G.add(POINT(i, j), POINT(tx, ty), INF); 					} 				} 			} 			else {				G.add(POINT(i, j), G.t, val - a[i][j]); 			} 		} 	} 	return G.dinic() == sum; } signed main() { 
freopen("game/2.in","r",stdin);
freopen("game.out","w",stdout);
INF = 0x7F7F7F7F7F7F7F7F; 	cin>>T; 	while(T --) { 		cin>>n>>m; 		int max1 = 0; 		int s0, s1, c0, c1; 		s0 = s1 = c0 = c1 = 0; 		for(int i = 1; i <= n; i ++) { 			for(int j = 1; j <= m; j ++) { 				cin>>a[i][j]; 				max1 = max(max1, a[i][j]); 				if((i + j) % 2 == 0) { 					s0 += a[i][j]; 					c0 ++; 				} 				else { 					s1 += a[i][j]; 					c1 ++; 				} 			} 		} 		if(c0 != c1) { 			int x = (s0 - s1) / (c0 - c1);  			if(x >= max1 && check(x)) { 				cout<<x * c1 - s1<<endl; 			} 			else { 				cout<<-1<<endl; 			} 		} 		else { 			if(s0 != s1) { 				cout<<-1<<endl; 			} 			else { 				int top = INF >> 1, end = max1 - 1; 				while(end + 1 != top) { 					int mid = (top + end) >> 1; 					if(check(mid)) {						top = mid; 					} 					else { 						end = mid; 					} 				} 				if(top == INF >> 1) { 					cout<<-1<<endl; 				} 				else { 					cout<<top * c1 - s1<<endl; 				} 			} 		} 	} 	return 0; }


