#include<bits/stdc++.h>
using namespace std;
#define open(x) freopen(x ".in", "r", stdin);freopen(x ".out", "w", stdout);

inline int read(){int f=1;int x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-'){f=-f;}c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
inline void wr(int x){if(x<0){putchar('-');x=-x;}if(x>9){wr(x/10);}putchar(x%10+'0');}

int n,q;
struct node{
	int nex,to;
}a[200050];

int used[200050];
int cnt;
int f[200050];
int head[500050];

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
unordered_map<int,int> disc[200005];

set<int> s;

inline void dfs_fa(int x,int fa){
	cout<<"fad "<<x<<endl;
	for(int i=head[x];i;i=a[i].nex){
		int v = a[i].to;
		if(v == fa) continue;					//
		dis[v] = min(dis[x]+1,dis[v]);
		dfs_fa(v,x);
	}
	return;
}

int ct[200050];

signed main(){
	freopen("b.in","r",stdin);
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
	kkk = 0;
	for(int i=id;i;i=pre[i]){
		f[++kkk] = i;
		s.insert(i);
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i){
		if(s.find(i) != s.end()){				//
			cout<<i<<" in set"<<endl;
			dfs_fa(i,0);
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
		}
		else if(s.find(y) != s.end()){
			int base = dis[x];
			int idx = idxx[x];
			//
			int mina = min(idx,y);
			int maxa = max(idx,y);
			//
			int base_up = disc[mina][maxa];
			if(base_up < base){
				puts("Survive");
			}
			else{
				puts("Deception");
			}
			continue;
		}
		else{
			int A = dis[x];
			int B = dis[y];
			if(A >= B) puts("Deception");
			else puts("Survive");
			continue;
		}
	}
	return 0;
}
