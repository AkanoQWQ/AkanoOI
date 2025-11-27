//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int IINF = 0x7fffffff;
const int MAXN = 2006;
const int MAXM = 20006;//small???
const int st = 0;
const int ed = 2000;
const int INF = 0x7F7F7F7F7F7F7F7F;
const int movex[4] = {0,1,0,-1};
const int movey[4] = {1,0,-1,0};
int mp[44][44],white_sum,white_num,black_sum,black_num,maxmp;
int n,m,t,maxflow;
inline int id(int x,int y){
	return m*(x-1) + y;
}

int head[MAXN],tot = 1;
struct Edge{
	int to,cap,nxt;	
}e[MAXM];
inline void AddEdge(int u,int v,int cap){
	e[++tot].cap = cap;
	e[tot].to = v;
	e[tot].nxt = head[u];
	head[u] = tot;
	return ;
}
inline void Add(int u,int v,int cap){
	AddEdge(u,v,cap);
	AddEdge(v,u,0);
	return ;
}
int dep[MAXN],cur[MAXN];
queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	memset(dep,0,sizeof(dep));
	q.push(st);
	dep[st] = 1;
	while(!q.empty()){
		const int u = q.front();
		cur[u] = -1;
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(!dep[v] && e[i].cap > 0){
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[ed];
}
int dfs(int u,int val){
	if(u == ed || val == 0)return val;
	int ret = 0;
	int sta = cur[u];
	if(sta == -1)sta = head[u];
	for(int i = sta;i;i = e[i].nxt){
		cur[u] = i;
		const int v = e[i].to;
		if(e[i].cap <= 0 || dep[v] != dep[u]+1)continue;
		int goto_awa = min(e[i].cap,val);
		if(goto_awa <= 0)continue;
		int real_uwu = dfs(v,goto_awa);
		ret += real_uwu;
		e[i].cap -= real_uwu;
		e[i^1].cap += real_uwu;
		val -= real_uwu;
		if(val <= 0)break;
	}
	if(ret == 0)dep[u] = -1;
	return ret;
}
inline void Dinic(){
	while(bfs()){
		maxflow += dfs(st,INF);
	}
	return ;
}
inline void _INIT___(){
	tot = 1;
	memset(head,0,sizeof(head));
	return ;
}
inline bool check(int x){
	int real_max_flow = 0;
	maxflow = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			const int addval = x - mp[i][j];
			if((i+j)%2 == 0){
				Add(st,id(i,j),addval);
				real_max_flow += addval;
				for(int k = 0;k < 4;k++){
					const int OX = i + movex[k];
					const int OY = j + movey[k];
					if(OX < 1 || OX > n || OY < 1 || OY > m)continue;
					Add(id(i,j),id(OX,OY),INF);
				}
			}else{
				Add(id(i,j),ed,addval);
			}
		}
	}
	Dinic();
	_INIT___();
	return (maxflow >= real_max_flow);
}
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f=-1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	t = read();
	while(t--){
		n = read(),m = read();
		maxmp = 0;
		white_sum = 0,white_num = 0;
		black_sum = 0,black_num = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				mp[i][j] = read();
				maxmp = max(maxmp,mp[i][j]);
				if((i+j)%2 == 0){//white > black
					white_sum += mp[i][j];
					white_num++;
				}else{
					black_sum += mp[i][j];
					black_num++;
				}
			}
		}
		if(white_num != black_num){
			int x = (white_sum - black_sum) / (white_num - black_num);
			if(check(x)){
				write(x * black_num - black_sum),putchar('\n');
			}else{
				puts("-1");
			}
		}else{
			int l = maxmp;
			int r = 0x7fffffff;
			while(l < r){
				const int mid = (l + r) >> 1;
				if(check(mid)){
					r = mid;
				}else{
					l = mid + 1;
				}
			}
			if(r == INF){
				puts("-1");
			}else{
				write(r * black_num - black_sum),putchar('\n');
			}
		}
	}
	return 0;	
}
