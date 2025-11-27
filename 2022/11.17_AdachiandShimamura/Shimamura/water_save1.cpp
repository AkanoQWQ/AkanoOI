#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
#define ll long long
const int MAXN = 100006;
const int MAXM = 6 * MAXN;//di <= 5
int n,m,maxd;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],sz[MAXN],ent;
void AddEdge(int from,int to){
	e[++ent].to = to;
	e[ent].nxt = head[from];
	head[from] = ent;
	return ;
}
int gcd(int a,int b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return 1ll*a*b/gcd(a,b);
}
struct fs{
	int up,down;
}p[MAXN],cf;
void yue(fs& a){
	const int gc = gcd(a.up,a.down);
	if(gc == 1)return ;
	a.up /= gc;
	a.down /= gc;
	return ;
}
void AddFS(fs& a,const fs& b,int div){
	cf.up = b.up;
	cf.down = b.down * div;
	cout<<cf.down<<" "<<a.down<<" ";
	const int lc = lcm(cf.down,a.down);
	cout<<lc<<endl;
	cf.up *= lc/cf.down;
	cf.down = lc;
	a.up *= lc/a.down;
	a.down = lc;
	a.up += cf.up;
	yue(a);
	return ;
}
vector<int> dep[16];// change   if 16 is too small!! expected 10 - 12
vector<int> otp;
queue<pair<int,int> > q;
void bfs(){
	for(int i = 1;i <= m;i++){
		q.push(make_pair(i,0));
	}
	while(!q.empty()){
		const int u = q.front().first;
		const int nowd = q.front().second;
		q.pop();
		if(sz[u] == 0)continue;//otp
		maxd = max(maxd,nowd);
		dep[nowd].push_back(u);
		for(int i = head[u];i;i = e[i].nxt){
			q.push(make_pair(e[i].to,nowd+1));
		}
	}
	return ;
}
EXCUTE_ST
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&sz[i]);
		p[i].down = 1;
		if(sz[i] == 0){
			otp.push_back(i);
		}
		for(int j = 1;j <= sz[i];j++){
			int x;
			scanf("%d",&x);
			AddEdge(i,x);
		}
	}
	bfs();
	for(int i = 1;i <= m;i++){
		p[i].up = 1;
	}
	for(int i = 0;i <= maxd;i++){
		for(int j = 0;j < dep[i].size();j++){
			const int u = dep[i][j];
			for(int k = head[u];k;k = e[k].nxt){
				AddFS(p[e[k].to],p[u],sz[u]);
			}
		}
	}
	for(int i = 0;i < otp.size();i++){
		const int u = otp[i];
		yue(p[u]);
		cout<<p[u].up<<" "<<p[u].down<<endl;
	}
FILE_ED_And_excute
