#include<bits/stdc++.h>
using namespace std;
#define open(x) freopen(x ".in", "r", stdin);freopen(x ".out", "w", stdout);

inline int read(){int f=1;int x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-'){f=-f;}c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
inline void wr(int x){if(x<0){putchar('-');x=-x;}if(x>9){wr(x/10);}putchar(x%10+'0');}

int n,q;
struct node{
	int nex,to;
}a[500050];

int used[200050];
int cnt;
int head[200050];

inline void addedge(int st,int to){
	a[++cnt].to=to;
	a[cnt].nex=head[st];
	head[st]=cnt;
	return;
}

int pre[200050];
int id;

inline void dfs(int x,int fa){
	used[x] = 1;
	for(int i=head[x];i;i=a[i].nex){
		int v = a[i].to;
		if(v == fa) continue;
		if(used[v] == 1) {
			id = v;
			return;
		}
		pre[v] = x;
		dfs(v,x);
	}
	return;
}

int dis[200050];
int idxx[200050];

set<int> s;

inline void dfs_fa(int x,int fa,int root){
	idxx[x] = root;
	for(int i=head[x];i;i=a[i].nex){
		int v = a[i].to;
		if(v == fa ||  s.find(v) != s.end()) continue;
		if(dis[v] > dis[x] + 1){
			dis[v] = dis[x] + 1;
		}
		dfs_fa(v,x,root);
	}
	return;
}

int ct[200050];

signed main(){
	n = read();
	q = read();
	for(int i=1;i<=n;++i){
		int x,y;
		x = read();
		y = read();
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	int kkk = 0;
	for(int i=id;i;i=pre[i]){
		ct[i] = ++kkk;
	} 
	for(int i=id;i;i=pre[i]){
		s.insert(i);
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i){
		if(s.find(i) != s.end()){
			dis[i] = 0;
			idxx[i] = i;
			dfs_fa(i,0,i);
		}
	}
	while(q--){
		int x , y;
		x = read();
		y = read();
		if(x == y){
			puts("Deception");
			continue;
		}
		else if(s.find(x) != s.end()){
			puts("Survive");
			continue;
		}else{
			int base = dis[x];
			int idx = idxx[x];
			int maxa = max(ct[idxx[x]],ct[idx]);
			int mina = min(ct[idxx[x]],ct[idx]);
			int base_up = min(maxa - mina , kkk - maxa + mina);
			if(base_up > base){
				puts("Survive");
			}
			else{
				puts("Deception");
			}
			continue;
		}
	}
	return 0;
}
