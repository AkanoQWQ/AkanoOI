#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXT = 66;
const int MAXN = 1018;
const int MAXM = 2006 + 1018 + 1108;
struct Edge{
	int nxt,to,val;
}e[MAXM];
int head[MAXT],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,r[MAXT],pop[MAXT],dis[MAXT],way[MAXT];
bool inq[MAXT];
inline bool SPFA(){
	queue<int> q;
	for(int i = 0;i <= 24;i++){
		q.push(i),inq[i] = true;
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(v == u-1)cerr<<u<<" -> "<<v<<" is "<<dis[u] + e[i].val<<" compare "<<dis[v]<<endl;
			if(dis[v] > dis[u] + e[i].val){
				dis[v] = dis[u] + e[i].val;
				way[v] = way[u] + 1;
				if(way[v] > 25)return false;
				if(!inq[v]){
					inq[v] = true,q.push(v);
				}
			}
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 24;i++){
		cin>>r[i];
		AddEdge(i,max(i-8,0),-r);
		AddEdge(i,i-1,0); 
	}
	for(int i = 25;i <= 48;i++){
		r[i] = r[i-24];
		AddEdge(i,max(i-8,0),-r);
		AddEdge(i,i-1,0); 
	}
	cin>>n;
	for(int i = 1;i <= n;i++){
		int t;
		cin>>t;
		pop[t]++;
	}
	for(int i = 1;i <= 24;i++){//Ëã³ÉÇ°×ººÍ 
		pop[i] += pop[i-1];
	}
	if(!SPFA()){
		cout<<"No Solution!"<<endl;
		return not(Akano loves pure__Elysia);
	}
	cout<<dis[24] - dis[0]<<endl;
	return not(Akano loves pure__Elysia);
}
