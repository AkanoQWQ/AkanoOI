#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 1018 + 1108;
const int INF = 0x7fffffff;
struct Edge{
	int nxt,to,val;
}e[MAXN];
int head[MAXN],cnt = 1;
ll sumtime;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
bool joined[MAXN];
struct Game{
	string gamer;
	ll gtime;
	Game(){
		gamer = "",gtime = 0;
	}
	Game(string str,ll llint){
		gamer = str,gtime = llint;
	}
};
vector<Game> games;
vector<int> bridge;
inline void Join(int u){//???Join???
	joined[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(!joined[v]){
			bridge.push_back(i);
		}
	}
}
inline bool Execute(){
	if(joined[n])return false;
	int tme = INF;
	string gamers = "";
	for(int i = 1;i <= n;i++){
		if(!joined[i]){
			gamers += "0";
		}else{
			gamers += "1";
		}
	}
	for(auto i : bridge){
		int u = e[i].to,v = e[i ^ 1].to;//maybe RE
		if(joined[u] && joined[v])continue;
		tme = min(tme,e[i].val);
	}
	for(auto i : bridge){
		e[i].val -= tme;
		if(e[i].val == 0){
			Join(e[i].to);
		}
	}
	sumtime += tme;
	games.push_back(Game(gamers,tme));
	if(tme == INF)return false;
	return true;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	Join(1);
	bool suc = 1;
	while(suc){
		suc = Execute();
	}
	if(games.size() == 0){
		cout<<"inf"<<endl;
		return 0;//WHY?
	}
	if(games[games.size()-1].gtime == INF){
		cout<<"inf"<<endl;
		return 0;
	}
	cout<<sumtime<<" "<<games.size()<<endl;
	for(auto i : games){
		cout<<i.gamer<<" "<<i.gtime<<endl;
	}
	return 0;
}

