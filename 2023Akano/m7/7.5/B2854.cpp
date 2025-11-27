#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
const int MAXN = 106;
const int INF = 1e8;
const int MAXST = (1<<15) + 6;
const int MAXK = 16;
int dis[MAXN][MAXN],mp[MAXN],n,m,t;
inline void Floyd(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	return ;
}
vector<int> stats;
inline int Onenum(int x){
	int ret = 0;
	while(x){
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}
bool Cmp4One(int _i1,int _i2){
	return Onenum(_i1) < Onenum(_i2);
}
inline string Bit(const int& _i){
	string ret;
	for(int i = 0;i < m;i++){
		ret += '0' + bool(_i & (1<<i));
	}
	return ret;
}
int f[MAXST][MAXK];
int main(){
	//freopen(".in","r",stdin);
	n = Read(),m = Read(),t = Read();
	for(int i = 1;i <= m;i++){
		mp[i] = Read();
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	while(t--){
		int u = Read(),v = Read(),w = Read();
		dis[u][v] = min(dis[u][v],w);
		dis[v][u] = dis[u][v];
	}
	Floyd();
	stats.reserve(1<<m);
	for(int stat = 0;stat < (1<<m);stat++){
		for(int j = 0;j <= m;j++)f[stat][j] = INF;
		stats.push_back(stat);
	}
	for(int i = 0;i < m;i++){
		f[(1<<i)][i] = dis[1][mp[i+1]];
	}
	sort(stats.begin(),stats.end(),Cmp4One);
	for(auto stat : stats){
		for(int lst = 0;lst < m;lst++){
			const int u = mp[lst+1];
			if(!(stat & (1<<lst)))continue;
			const int lstStat = stat - (1<<lst);
			for(int dec = 0;dec < m;dec++){
				const int v = mp[dec+1];
				if(!(lstStat & (1<<dec)))continue;
				f[stat][lst] = min(f[stat][lst],f[lstStat][dec] + dis[v][u]);
			}
//			cout<<Bit(stat)<<" in "<<mp[lst+1]<<" is "<<f[stat][lst]<<endl;
		}
	}
	int ans = INF,endST = (1<<m)-1;
	for(int i = 0;i < m;i++){
		ans = min(ans,f[endST][i] + dis[mp[i+1]][1]);
	}
	if(ans == INF)ans = -1;
	Write(ans),edl;
	return 0;
}

