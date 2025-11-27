#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

bool _ST_;

constexpr int MAXN = 1e4 + 104;
constexpr int MAXM = 1e5 + 1018 + 1108;
constexpr int SIZEN = 1e4 + 100;
struct Edge{
	int nxt,to;
}e[MAXM];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int T,q[MAXN],lastans;
unsigned short maindis[MAXN][MAXN];
inline void BFS(int ST,unsigned short dis[]){
	int qhead = 1,qtail = 0;
	q[++qtail] = ST;
	dis[ST] = 1;
	while(qhead <= qtail){
		const int u = q[qhead++];
		for(int i = head[u];i;i = e[i].nxt){
			const int v = e[i].to;
			if(dis[v] != 0)continue;
			dis[v] = dis[u] + 1;
			q[++qtail] = v;
		}
	}
	return ;
}
bool edgeval[12];
inline void LinkEdge(int n){
	for(int i = 0;i <= n;i++){
		int x = i;
		for(int j = 0;j <= 10;j++){
			edgeval[j] = false;
		}
		while(x){
			edgeval[x % 10] = true;
			x /= 10;
		}
		for(int j = 0;j <= 10;j++){
			if(edgeval[j]){
				AddEdge(i,i-j);
				if(i+j <= n)AddEdge(i,i+j);
			}
		}
	}
	return ;
}

bool _ED_;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cerr<<"memory usage : "<<(&_ST_ - &_ED_) / 1024. / 1024.<<endl;
	freopen("counter.in","r",stdin);
	freopen("counter.out","w",stdout);
	cin>>T;
	LinkEdge(SIZEN);
	while(T--){
		int x,y;
		cin>>x>>y;
		x ^= (lastans+1),y ^= (lastans+1);
		if(x > SIZEN || y > SIZEN){
			cout<<"aK4n0不知道哦"<<'\n';
		}else{
			if(maindis[x][x] == 0){
				BFS(x,maindis[x]);
			}
			lastans = maindis[x][y]-1;
			cout<<lastans<<'\n';
		}
	}
	return not(Akano loves pure__Elysia);
}
