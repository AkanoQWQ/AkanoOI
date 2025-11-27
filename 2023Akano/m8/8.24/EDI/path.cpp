#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;//¹»Âð?!!
const int MAXN = 2006;
const int MAXM = 60000 + 1018 + 1108;
const int MOD = 1e9 + 9;
const int div2 = (MOD+1) / 2;
struct Edge{
	int nxt,to,val;
}e[MAXM];
struct SaveE{
	int from,to,val;
	SaveE(){from = to = val = 0;}
	SaveE(int _from,int _to,int _val){from = _from,to = _to,val = _val;}
};
int head1[MAXN],head2[MAXN],cnt;
inline void AddEdge(int from,int to,int val,int head[]){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int con[MAXN][MAXN];
int dis1[MAXN],dis2[MAXN],no[MAXN],dis3[MAXN],nnt,n,m,s,t;
bool vis[MAXN],est[MAXN];
inline void Dij(int st,int dis[],int head[]){
	priority_queue<pair<int,int> > q;
	for(int i = 1;i <= n;i++){
		dis[i] = INF,vis[i] = false;
	}
	dis[st] = 0;
	q.push(make_pair(-dis[st],st));
	while(!q.empty()){
		const int u = q.top().second;;
		q.pop();
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return ;
}
inline void ReadIn(){
	cin>>n>>m>>s>>t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			con[i][j] = INF;
		}
	}
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		con[u][v] = min(con[u][v],w);
	}
	for(int u = 1;u <= n;u++){
		for(int v = 1;v <= n;v++){
			if(con[u][v] == INF || u == v)continue;
			AddEdge(u,v,con[u][v],head1),AddEdge(v,u,con[u][v],head2);
		}
	}
	return ;
}
inline void Remake(){
	Dij(s,dis1,head1),Dij(t,dis2,head2);
	for(int i = 1;i <= n;i++){
		if(dis1[i] + dis2[i] == dis1[t]){
			est[i] = true;
		}
	}
	vector<SaveE> saveEdge1,saveEdge2;
	for(int u = 1;u <= n;u++){
		if(!est[u])continue;
		no[u] = ++nnt;
		dis3[no[u]] = dis1[u];
		for(int i = head1[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(est[v]){
				if(dis1[u] + e[i].val == dis1[v]){
					saveEdge1.push_back(SaveE(u,v,e[i].val));
				}
			}
		}
		for(int i = head2[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(est[v]){
				if(dis2[u] + e[i].val == dis2[v]){
					saveEdge2.push_back(SaveE(u,v,e[i].val));
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)head1[i] = head2[i] = 0;
	cnt = 0;
	for(auto i : saveEdge1){
		AddEdge(no[i.from],no[i.to],i.val,head1);
	}
	for(auto i : saveEdge2){
		AddEdge(no[i.from],no[i.to],i.val,head2);
	}
	return ;
}
inline void Show(){
	for(int i = 1;i <= n;i++){
		if(est[i]){
			cout<<i<<" no "<<no[i]<<endl;
			for(int j = head1[i];j;j = e[j].nxt){
				const int v = e[j].to;
				cout<<i<<" to "<<v<<" edge1 "<<e[j].val<<endl;
			}
			for(int j = head2[i];j;j = e[j].nxt){
				const int v = e[j].to;
				cout<<i<<" to "<<v<<" edge2 "<<e[j].val<<endl;
			}
		}
	}
	return ;
}
ll f[MAXN][MAXN];
vector<int> vec,pre[MAXN];
bool Smaller(int i1,int i2){
	if(dis3[i1] != dis3[i2])return dis3[i1] < dis3[i2];
	return i1 < i2;
}
inline int Solve(){
	n = -100;
	int ret = 0;
	for(int i = 1;i <= nnt;i++){
		vec.push_back(i);
	}
	sort(vec.begin(),vec.end(),Smaller);
	s = no[s],t = no[t];
	f[s][s] = 1;
	for(auto u1 : vec){
		for(auto u2 : vec){
			if(Smaller(u1,u2)){
				for(int i = head1[u1];i;i = e[i].nxt){
					const int v = e[i].to;
					if(v != u2|| v == t)f[v][u2] = (f[v][u2] + f[u1][u2]) % MOD;
				}
			}else{
				for(int i = head1[u2];i;i = e[i].nxt){
					const int v = e[i].to;
					if(v != u1 || v == t)f[u1][v] = (f[u1][v] + f[u1][u2]) % MOD;
				}
			}
		}
	}
	ret = f[t][t];
	for(int i = head1[s];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == t)ret++;
	}
	ret = (1ll * ret * div2) % MOD;
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Remake();
	cout<<Solve()<<endl;
	return 0;
}

