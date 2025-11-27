#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1018 + 1108;
const int MAXM = 5e5 + 1018 + 1108;

namespace IO {
	const int SIZE=(1<<21)+1;
	char ibuf[SIZE],*iS,*iT,obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1,c,qu[55];int f, qr;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template <class I>
	inline void Read(I &x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);
		x*=f;
	}
	template <class I>
	inline void Print(I x){
		if(!x)putc('0');
		if(x<0)putc('-'),x=-x;
		while(x)qu[++qr]=x%10+'0',x/=10;
		while(qr)putc(qu[qr --]);
	}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using IO::Read;
using IO::Print;
using IO::putc;

struct Edge{
	int nxt,to;
	ll val;
}e[MAXM * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,ll val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,m;
ll ans,tot;
int vis[MAXN],turn,q[MAXN];
inline bool BFS(){
	int qhead = 1,qtail = 0;
	turn++;
	q[++qtail] = n;//为什么颠倒过来就这么快?!!!!
	vis[n] = turn;//可持久化vis数组
	while(qhead <= qtail){
		const int u = q[qhead++];
		for(int i = head[u];i;i = e[i].nxt){
			if((e[i].val & ans) != ans){
				continue;
			}
			const int v = e[i].to;
			if(vis[v] == turn)continue;
			q[++qtail] = v,vis[v] = turn;
			if(v == 1)return true;
		}
	}
	return (vis[1] == turn);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Read(n),Read(m);
	for(int i = 1;i <= m;i++){
		int u,v;
		ll w;
		Read(u),Read(v),Read(w);
		tot |= w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	for(int i = 63;i >= 0;i--){
		if(((1ll<<i) & tot) == 0)continue;
		ans += (1ll<<i);
		if(BFS() == false)ans -= (1ll<<i);
	}
	Print(ans);
	return not(Akano loves pure__Elysia);
}
