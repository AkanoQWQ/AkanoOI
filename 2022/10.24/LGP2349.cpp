#include<bits/stdc++.h>
using namespace std;
const int MAXN = 206;
const int MAXM = 8006;
const int INF = 0x7fffffff;
struct edg{
	int from,to,v;
}edg_[MAXM];
struct edge{
	int to,v;
};
vector<edge> e[MAXN];
void AddEdge(edg ed){
	edge a;
	a.to = ed.to,a.v = ed.v;
	e[ed.from].push_back(a);
	return ;
}
bool cmp4edg(edg a,edg b){
	return a.v < b.v;
}
int n,m,tail = 1;
int dis[MAXN],mans = INF;
bool inq[MAXN];
queue<int> q;
void SPFA(){
	for(int i = 1;i <= n;i++)dis[i] = INF - 600;
	memset(inq,0,sizeof(inq));
	inq[1] = 1;
	dis[1] = 0;
	while(!q.empty())q.pop();
	q.push(1);
	while(!q.empty()){
		const int u = q.front();
		inq[u] = 0;
		q.pop();
		for(int i = 0;i < e[u].size();i++){
			const int v = e[u][i].to;
			if(dis[u] + e[u][i].v < dis[v]){
				dis[v] = dis[u] + e[u][i].v;
				if(inq[v] == 0){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		cin>>edg_[i].from>>edg_[i].to>>edg_[i].v;
		edg_[i+m]= edg_[i];
		edg_[i+m].from = edg_[i+m].to;
		edg_[i+m].to = edg_[i].from;
	}
	m *= 2;
	sort(edg_+1,edg_+m+1,cmp4edg);
	for(int i = 1;i <= 255;i++){
		while(tail <= m && edg_[tail].v <= i){
			AddEdge(edg_[tail]);
			tail++;
		}
		SPFA();
		mans = min(mans,dis[n]+i);
	}
	cout<<mans;
	return 0;
}
