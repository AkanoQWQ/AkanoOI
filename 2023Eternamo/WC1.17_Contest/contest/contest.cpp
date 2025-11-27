#include<bits/stdc++.h>
using namespace std;
const int MAXN = 18;
struct Edge{
	int nxt,to;
}e[MAXN*MAXN*MAXN*2];
int cnt,head[MAXN][MAXN];
bool added[MAXN][MAXN][MAXN];
void AddEdge(int from,int from2,int to){
	if(added[from][from2][to])return ;
	added[from][from2][to] = 1;
	e[++cnt].to = to;
	e[cnt].nxt = head[from][from2];
	head[from][from2] = cnt;
	return ;
} 
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int t,n,m,s[MAXN],pop[MAXN],orgm;
bool same[MAXN][MAXN][MAXN],used[MAXN],fd;
bool calc(){
	if(same[pop[n-1]][pop[n]][pop[1]] || same[pop[n]][pop[1]][pop[2]])return 0;
	for(int i = 1;i <= n;i++){
		write(pop[i]),putchar(' ');
	}
	putchar('\n');
	return 1;
}
int rrd = 0;
void dfs(int pre_2,int pre_1,int dep){
	if(n > 10 && ++rrd > 2000000){
		puts("-1");
		fd = 1;
		return ;
	}
	if(fd)return ;
	if(dep == n + 1){
		fd = calc();
		return ;
	}
	for(int i = head[pre_2][pre_1];i;i = e[i].nxt){
		const int v = e[i].to;
		if(used[v])continue;
		used[v] = 1;
		pop[dep] = v;
		dfs(pre_1,v,dep+1);
		if(fd)return ;
		used[v] = 0;
	}
	return ;
}
int main(){
	freopen("contest.in","r",stdin);
	freopen("contest.out","w",stdout);
	t = read();
	while(t--){
		fd = 0,rrd = 0;
		n = read(),m = read();
		memset(used,0,sizeof(used));
		memset(same,0,sizeof(same));
		memset(head,0,sizeof(head));
		memset(added,0,sizeof(added));
		cnt = 0;
		while(m--){
			int k = read();
			for(int i = 1;i <= k;i++){
				s[i] = read();
			}
			for(int i = 1;i <= k;i++){
				for(int j = 1;j <= k;j++){
					for(int kk = 1;kk <= k;kk++){
						same[s[i]][s[j]][s[kk]] = 1;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int kk = 1;kk <= n;kk++){
					if(same[i][j][kk] == 0){
						AddEdge(i,j,kk);
						AddEdge(i,kk,j);
						AddEdge(j,i,kk);
						AddEdge(j,kk,i);
						AddEdge(kk,i,j);
						AddEdge(kk,j,i);
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
			AddEdge(0,0,i); 
			for(int j = 1;j <= n;j++){
				if(i != j)AddEdge(0,i,j);
			}
		}
		dfs(0,0,1);
		if(fd == 0){
			puts("-1");
		}
	}
	return 0;
}
