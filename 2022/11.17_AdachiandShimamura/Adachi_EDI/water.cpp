#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
const int MAXN = 100006;
const int MAXM = 6 * MAXN;//di <= 5
int n,m;
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
__int128 gcd(__int128 a,__int128 b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
__int128 lcm(__int128 a,__int128 b){
	return a*b/gcd(a,b);
}
struct fs{
	__int128 up,down;
}p[MAXN],cf;
void yue(fs& a){
	const __int128 gc = gcd(a.up,a.down);
	if(gc == 1)return ;
	a.up /= gc;
	a.down /= gc;
	return ;
}
void AddFS(fs& a,const fs& b){
	const __int128 lc = lcm(b.down,a.down);
	a.up *= lc/a.down;
	a.down = lc;
	a.up += b.up * lc / b.down;
	yue(a);
	return ;
}
vector<__int128> water[MAXN];
vector<int> otp;
void write(__int128 x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x%10 + '0');
	return ;
}
inline __int128 read(){
	__int128 x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
queue<int> q;
bool inq[MAXN];
void bfs(){
	for(int i = 1;i <= m;i++){
		q.push(i);
		water[i].push_back(1);
		inq[i] = 1;
	}
	while(!q.empty()){
		const int u = q.front();
		q.pop();
		inq[u] = 0;
		if(sz[u] == 0)continue;//otp
		for(int i = head[u];i;i = e[i].nxt){
			for(int j = 0;j < water[u].size();j++){
				water[e[i].to].push_back(water[u][j]*sz[u]);
			}
			if(!inq[e[i].to])q.push(e[i].to);
		}
		water[u].clear();
	}
	return ;
}
EXCUTE_ST
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1;i <= n;i++){
		sz[i] = read();
		p[i].down = 1;
		if(sz[i] == 0){
			otp.push_back(i);
		}
		for(int j = 1;j <= sz[i];j++){
			int x;
			x = read();
			AddEdge(i,x);
		}
	}
	bfs();
	for(int i = 0;i < otp.size();i++){
		const int u = otp[i];
		p[u].down = 1;
		for(int j = 0;j < water[u].size();j++){
			fs cw;
			cw.up = 1,cw.down = water[u][j];
			AddFS(p[u],cw);
		}
		write(p[u].up);
		putchar(' ');
		write(p[u].down);
		putchar('\n');
	}
FILE_ED_And_excute
//9:14 finished  expected : 100pts
