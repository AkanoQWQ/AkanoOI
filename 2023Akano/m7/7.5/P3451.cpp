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
const int MAXN = 2e4 + 6;
const int MAXM = 4e5 + 6;
const int MAXK = 25;
const int INF = 2e9;
struct Edge{
	int nxt,to,val;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m,k,g;
int pre[MAXK],nxt[MAXK];
namespace Way{//The shortest way
	int dis[MAXK][MAXN];
	bool vis[MAXK][MAXN];
	inline void Dij(int ST){
		priority_queue<pair<int,int> > q;
		int* nowdis = dis[ST];
		bool* nowvis = vis[ST];
		for(int i = 1;i <= n;i++)nowdis[i] = INF;
		nowdis[ST] = 0;
		q.push(make_pair(nowdis[ST],ST));
		while(!q.empty()){
			const int u = q.top().second;
			q.pop();
			if(nowvis[u])continue;
			nowvis[u] = true;
			for(int i = head[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(nowdis[u] + e[i].val < nowdis[v]){
					nowdis[v] = nowdis[u] + e[i].val;
					q.push(make_pair(-nowdis[v],v));
				}
			}
		}
		return ;
	}
}
inline string Bit(const int& _i){
	string ret;
	for(int i = 0;i < k;i++){
		if(_i & (1<<i)){
			ret += "1";
		}else{
			ret += "0";
		}
	}
	return ret;
}
inline int Onenum(const int& _i){
	int ret = 0;
	for(int i = 0;i < k;i++){
		if(_i & (1<<i)){
			++ret;
		}
	}
	return ret;
}
const int MAXSZ = 184756 + 2006;
int f[2][MAXSZ][MAXK];
int now = 0,lst = 1;
inline bool Judge(int stat,int lst){
	if(!(stat & (1<<(lst-2))))return false;
	if((stat & pre[lst]) != pre[lst])return false;
	if(stat & nxt[lst])return false;
	return true;
}
vector<int> stats;
bool Cmp4One(int _i1,int _i2){
	return Onenum(_i1) < Onenum(_i2);
}
const int MAXSTAT = 1e6 + 50000;
int Stat2Num[MAXSTAT];
int cnts[22],endst;
inline int Zip(int stat){
	if(Stat2Num[stat])return Stat2Num[stat];
	int num = Onenum(stat);
	int to = ++cnts[num];
	Stat2Num[stat] = to;
	return to;
}
int main(){
	n = Read(),m = Read(),k = Read();
	endst = (1<<k);
	for(int i = 0;i <= 184757;i++){
		for(int j = 0;j <= k+1;j++){
			f[now][i][j] = f[lst][i][j] = INF;
		}
	}
	for(int i = 1;i <= m;i++){
		int u = Read(),v = Read(),w = Read();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	g = Read();
	while(g--){
		int u = Read(),v = Read();
		pre[v] |= 1<<(u-2);
		nxt[u] |= 1<<(v-2);
	}
	for(int i = 1;i <= k+1;i++){
		Way::Dij(i);
		if(i != 1 && pre[i] == 0){
			f[now][Zip(1<<(i-2))][i] = Way::dis[1][i];//fristly swap now/lst
		}
	}
	if(k == 0){
		Write(Way::dis[1][n]),edl;
		return 0;
	}
	for(int i = 0;i < (1<<k);i++){
		stats.push_back(i);
		Zip(i);
	}
	sort(stats.begin(),stats.end(),Cmp4One);
	int lstnum = 1;
	for(auto stat : stats){
		int num = Onenum(stat);
		if(num <= 1)continue;
		if(num != lstnum){
			swap(now,lst);
			for(int i = 0;i <= cnts[lstnum];i++){
				for(int j = 0;j <= k+1;j++){
					f[now][i][j] = INF;
				}
			}
			lstnum = num;
		}
		for(int LstNum = 0;LstNum < k;LstNum++){
			const int u = LstNum + 2;
			if(!Judge(stat,u))continue;
			const int lstStat = stat - (1<<LstNum);
			for(int obj = 0;obj < k;obj++){
				const int v = obj + 2;
				if(!Judge(lstStat,v))continue;
				f[now][Zip(stat)][u] = min(f[lst][Zip(lstStat)][v] + Way::dis[v][u],f[now][Zip(stat)][u]);
			}
		}
	}
	int ans = INF;
	for(int i = 2;i <= k+1;i++){
		ans = min(ans,f[now][Zip((1<<k)-1)][i] + Way::dis[i][n]);
	}
	Write(ans),edl;
	return 0;
}
