#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 10006;
long long INF = 1,I2 = 1;
long long n,m,s,u,v,w,dis[MAXN];
bool inq[MAXN];
vector<pair<long long,long long> > edg[MAXN];
queue<long long> q;
void SPFA(long long BE){
	for(long long i = 1;i <= n;++i)dis[i] = INF;
	inq[BE] = 1,dis[BE] = 0;
	q.push(BE);
	while(!q.empty()){
		long long now = q.front();
		q.pop();
		inq[now] = 0;
		for(long long i = 0;i < edg[now].size();++i){
			long long to = edg[now][i].first;
			long long dist = edg[now][i].second;
			if(dis[to] > dis[now] + dist){
				dis[to] = dis[now] + dist;
				if(inq[to] == 0){
					q.push(to);
					inq[to] = 1;
				}
			}
		}
	}
	return ;
}
int main(){
	//freopen("SPFA.in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i = 0;i < 33;i++){
		INF *= 2;
	}
	for(int i = 0;i < 31;i++){
		I2 *= 2;
	}
	I2 -= 1;
	cin>>n>>m>>s;
	for(long long i = 1;i <= m;i++){
		//cin>>u>>v>>w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edg[u].push_back(pair<long long,long long>(v,w));
		//edg[v].push_back(pair<long long,long long>(u,w));
	}
	SPFA(s);
	for(long long i = 1;i <= n;i++){
		if(dis[i] == INF){
			cout<<I2<<" ";
		}else{
			cout<<dis[i]<<" ";
		}
		
	}
	return 0;
}

