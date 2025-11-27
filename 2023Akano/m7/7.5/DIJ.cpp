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
vector<int> pre[MAXK],nxt[MAXK];
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
inline int onenum(const int& _i){
	int ret;
	for(int i = 0;i < k;i++){
		if(_i & (1<<i)){
			++ret;
		}
	}
	return ret;
}
unordered_map<int,int> f[MAXK],emp;
inline int SizeMB(){
	int ret = 0;
	for(int i = 2;i <= k+1;i++){
		ret += sizeof(f) / 1000 / 1000;
	}
	ret += sizeof(pre) / 1000 / 1000;
	ret += sizeof(nxt) / 1000 / 1000;
	ret += sizeof(e) / 1000 / 1000;
	ret += sizeof(head) / 1000 / 1000;
	return ret;
}
inline void Clear(){
	for(int i = 2;i <= k+1;i++){
		f[i].clear();
		f[i] = emp;
	}
	return ;
}
inline bool Judge(int stat,int lst){
	if(!(stat & (1<<(lst-2))))return false;
	for(auto j : pre[lst]){
		const int QUERY = j-2;
		if(!(stat & (1<<QUERY))){
			return false;
		}
	}
	for(auto j : nxt[lst]){
		const int QUERY = j - 2;
		if(stat & (1<<QUERY)){
			return false;
		}
	}
	return true;
}
int Search(int stat,int lst){
	if(!Judge(stat,lst))return INF;
	if(f[lst].find(stat) != f[lst].end())return f[lst][stat];
	int ret = INF;
	const int lstStat = stat - (1<<(lst-2)); 
	for(int obj = 0;obj < k;obj++){
		const int v = obj + 2;
		if(Judge(lstStat,v)){
			ret = min(ret,Search(lstStat,v) + Way::dis[v][lst]);
		}
	}
	if(ret != INF){
		f[lst][stat] = ret;
		if(SizeMB() > 50)Clear();
	}
	return ret;
}
int main(){
	freopen("P3451.in","r",stdin);
	n = Read(),m = Read(),k = Read();
	for(int i = 1;i <= m;i++){
		int u = Read(),v = Read(),w = Read();
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	g = Read();
	while(g--){
		int u = Read(),v = Read();
		pre[v].push_back(u);nxt[u].push_back(v);
	}
	for(int i = 1;i <= k+1;i++){
		Way::Dij(i);
		if(i != 1 && pre[i].size() == 0)f[i][1<<(i-2)] = Way::dis[1][i];
	}
	if(k == 0){
		Write(Way::dis[1][n]),edl;
		return 0;
	}
	int ans = INF,endStat = (1<<k)-1;
	for(int i = 2;i <= k+1;i++){
		ans = min(ans,Search(endStat,i) + Way::dis[i][n]);
	}
	Write(ans),edl;
	return 0;
}
