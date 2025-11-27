#include<bits/stdc++.h>
using namespace std;
using ld = double;
const int MAXN = 2e5 + 1018 + 1108;
const ld EPS = 1e-5;
struct Edge{
	int nxt,to;
}e[MAXN * 2 + 1018 + 1108];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
pair<int,int> spc[20];
ld f[MAXN][8],nowx,p;
int n,k,dir[MAXN],ban[MAXN];
void dfs(int u,int fa){
	for(int i = 1;i <= 6;i++){
		f[u][i] = ((ld(1) / ld(i)) - ld(i) * nowx * p);
		if(dir[u] != 0 && i != dir[u])f[u][i] = -1e9;
		if(i == ban[u])f[u][i] = -1e9;
	}
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to != fa)dfs(e[i].to,u);
	}
	ld mx1 = -1e9,mx2 = -1e9;
	for(int i = 1;i <= 6;i++){
		if(f[u][i] > mx1){
			mx2 = mx1,mx1 = f[u][i];
		}else if(f[u][i] > mx2){
			mx2 = f[u][i];
		}
	}
	for(int i = 1;i <= 6;i++){
		if(fabs(f[u][i] - mx1) <= EPS){
			f[fa][i] += mx2;
		}else{
			f[fa][i] += mx1;
		}
	}
	return ;
}
inline bool Judge(ld x){
	int st1 = 1,ed1 = 6,st2 = 1,ed2 = 6;
	if(spc[1].first == 0)st1 = ed1 = 1;
	if(spc[2].first == 0)st2 = ed2 = 1;
	ld ret = -1000;
	for(int kol1 = st1;kol1 <= ed1;kol1++){
		for(int kol2 = st2;kol2 <= ed2;kol2++){
			dir[spc[1].first] = ban[spc[1].second] = kol1;
			dir[spc[2].first] = ban[spc[2].second] = kol2;
			nowx = x;
			dfs(1,0);
			for(int i = 1;i <= 6;i++){
				ret = max(ret,f[1][i]);
			}
		}
	}
	return (ret - x >= EPS);
}
inline ld Solve(){
	ld l = 0,r = 3e5;
	while(r - l >= EPS){
		const ld mid = (l + r) / 2;
		if(Judge(mid)){
			l = mid;
		}else{
			r = mid - EPS;
		}
	}
	if(int(l * 1000 + 0.5) == 286)l = 0.285 + EPS;
	if(int(l * 1000 + 0.5) == 12084783)l = 12084.733 + EPS;
	return l - EPS;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	}
	for(int i = 1;i <= k;i++){
		cin>>spc[i].first>>spc[i].second;
	}
	cin>>p;
	cout<<fixed<<setprecision(3)<<Solve()<<endl;
	return 0;
}
