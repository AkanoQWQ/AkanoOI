#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 2006 + 1018 + 1108;
const int MAXP = MAXN * 4;
int n,tot,e[MAXN],l[MAXN],d[MAXN];
int in[MAXN][2],out[MAXN][2],noIn[MAXN][2],noOut[MAXN][2],nnt,cost1[MAXN],cost2[MAXN];
int fa[MAXP];
vector<pair<int,int> > edge;
int Find(int x){
	if(fa[x] == x)return fa[x];
	return fa[x] = Find(fa[x]);
}
inline void Union(int x,int y){
	x = Find(x),y = Find(y);
	fa[x] = y;
	return ;
}
inline int GetCost(int x,int y){
	if(x <= y)return y - x;
	return y + 24 - x;
}
inline int Solve(int stat){
	int ret = 0;
	for(int i = 1;i <= nnt;i++)fa[i] = i;
	if(stat == 0){//进0出0
		ret = out[1][0] + GetCost(in[1][1],out[1][1]);
		Union(noIn[1][0],noOut[1][0]);
	}else if(stat == 1){//进0出1
		ret = out[1][1] + GetCost(in[1][1],out[1][0]);
		Union(noIn[1][0],noOut[1][1]);
	}else if(stat == 2){//进1出0
		ret = out[1][0] + GetCost(in[1][0],out[1][1]);
		Union(noIn[1][1],noOut[1][0]);
	}else{//进1出1
		ret = out[1][1] + GetCost(in[1][0],out[1][0]);
		Union(noIn[1][1],noOut[1][1]);
	}
	for(auto i : edge){
		Union(i.first,i.second);
	}
	for(int u = 2;u <= n;u++){
		cost1[u] = GetCost(in[u][0],out[u][0]) + GetCost(in[u][1],out[u][1]);//不交叉
		cost2[u] = GetCost(in[u][0],out[u][1]) + GetCost(in[u][1],out[u][0]);//交叉
		if(cost1[u] < cost2[u]){
			ret += cost1[u];
			Union(noIn[u][0],noOut[u][0]),Union(noIn[u][1],noOut[u][1]);
		}else{
			ret += cost2[u];
			Union(noIn[u][0],noOut[u][1]),Union(noIn[u][1],noOut[u][0]);
		}
	}
	while(true){
		int swp = 0,cost = 1e9;
		for(int u = 2;u <= n;u++){
			int x = Find(noIn[u][0]),y = Find(noIn[u][1]);
			if(x != y){
				int delta = abs(cost1[u] - cost2[u]);
				if(delta < cost){
					swp = u,cost = delta;
				}
			}
		}
		if(swp == 0)break;
		int x = Find(noIn[swp][0]),y = Find(noIn[swp][1]);
		Union(x,y);
		ret += cost;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	memset(in,-1,sizeof(in));
	for(int i = 1;i <= n;i++){
		noIn[i][0] = ++nnt,noIn[i][1] = ++nnt;
		noOut[i][0] = ++nnt,noOut[i][1] = ++nnt;
	}
	for(int i = 1;i <= 2*n;i++){
		cin>>e[i]>>l[i]>>d[i];
		const int u = ((i-1) / 2) + 1,v = e[i];
		out[u][not(i & 1)] = l[i];
		if(in[v][0] == -1){
			edge.emplace_back(noOut[u][not(i & 1)],noIn[v][0]);
			in[v][0] = (l[i] + d[i]) % 24;
		}else{
			edge.emplace_back(noOut[u][not(i & 1)],noIn[v][1]);
			in[v][1] = (l[i] + d[i]) % 24;
		}
		tot += d[i];
	}
	int ans = 1e9;
	for(int i = 0;i < 4;i++){
		ans = min(ans,Solve(i));
	}
	cout<<ans+tot<<endl;
	return not(Akano loves pure__Elysia);
}
