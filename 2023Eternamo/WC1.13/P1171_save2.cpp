#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int INF = 0x7fffff;
int n,dis[MAXN][MAXN],f[MAXN][(1<<MAXN)+3],maxstat;
pair<int,int> e[MAXN][MAXN];
inline int read(){
	int ret = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
void write(int x){
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int dfs(int pos,int stat){
	if(f[pos][stat] != -1)return f[pos][stat];
	int ret = INF;
	for(int i = 1;i < n;i++){
		const int uu = 1<<e[pos][i].second;
		if((stat & uu))continue;
		ret = min(ret,dfs(e[pos][i].second,uu|stat) + dis[pos][e[pos][i].second]);
	}
	f[pos][stat] = ret;
	return ret;
}
int main(){
	freopen("P1171.in","r",stdin);
	n = read();
	maxstat = (1<<n) - 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			dis[i][j] = read();
			e[i][j] = make_pair(dis[i][j],j);
		}
		sort(e[i],e[i]+n);
	}
	memset(f,-1,sizeof(f));
	f[1][maxstat] = 0;
	write(dfs(1,0));
	return 0;
}
