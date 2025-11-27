#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
constexpr int MAXN = 1018;
struct Edge{
	int nxt,to;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int n,dfn[MAXN],siz[MAXN],dep[MAXN],dnt;
void dfs(int u,int fa){
	u[dfn] = ++dnt,u[siz] = 1,u[dep] = fa[dep] + 1;
	for(int i = u[head];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		u[siz] += v[siz];
	}
	return ;
}
class SegmentTree{
private:
	struct Node{
		int len,val;
		bool lazy;
	}node[MAXN * 4];
	inline void Flip(int p){
		node[p].val = node[p].len - node[p].val;
		node[p].lazy = !node[p].lazy;
		return ;
	}
	inline void PushUp(int p){
		node[p].val = node[p*2].val + node[p*2+1].val;
		return ;
	}
	inline void PushDown(int p){
		if(!node[p].lazy)return ;
		Flip(p*2),Flip(p*2+1);
		node[p].lazy = 0;
		return ;
	}
	void Build(int p,int l,int r){
		node[p].len = r - l + 1;
		if(l == r){
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		return ;
	}
	int Query(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return node[p].val;
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		int ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
		return ret;
	}
	void Change(int p,int l,int r,int OBJL,int OBJR){
		if(OBJL <= l && r <= OBJR){
			return Flip(p);
		}
		const int mid = (l + r) >> 1;
		PushDown(p);
		if(mid >= OBJL)Change(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)Change(p*2+1,mid+1,r,OBJL,OBJR);
		return PushUp(p);
	}
public:
	inline int Query(int l,int r){
		if(l > r)return 0;
		return Query(1,1,n,l,r);
	}
	inline void Change(int l,int r){
		if(l > r)return ;
		return Change(1,1,n,l,r);
	}
	inline void Build(){
		return Build(1,1,n);
	}
}lr,ud;
vector<pii> uv;
bool fliped[MAXN];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("easy/easy1.in","r",stdin);
//	freopen("easy.out","w",stdout);
	cin>>n;
	if(n > 1018){
		cout<<"aK4n0不知道呢"<<endl;
		return not(Akano loves pure__Elysia);
	}
	for(int i = 1;i <= n;i++){
		lr.Build(),ud.Build();
	}
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
		uv.emplace_back(u,v);
	}
	dfs(1,1);
	int uvcnt = 0;
	for(auto nowuv : uv){
		int u = nowuv.first,v = nowuv.second;
		if(u[dep] < v[dep])swap(u,v);//u.dep > v.dep
		int dfnl = u[dfn],dfnr = u[dfn] + u[siz] - 1;
		int cnt0 = ud.Query(dfnl,dfnr),cnt1 = (dfnr - dfnl + 1) - cnt0;
		int kol0 = 0,kol1 = 0;
		if(dfnl - 1 >= 1){
			const int delta = lr.Query(1,dfnl-1);
			kol0 += delta,kol1 += ((dfnl - 1) - 1 + 1) - delta;
		}
		if(n >= dfnr + 1){
			const int delta = lr.Query(dfnr+1,n);
			kol0 += delta,kol1 += (n - (dfnr + 1) + 1) - delta;
		}
		int delta = (kol0 * (cnt0 - cnt1)) + (kol1 * (cnt1 - cnt0));
		if(delta > 0){
			fliped[++uvcnt] = true;
			lr.Change(dfnl,dfnr),ud.Change(dfnl,dfnr);
		}else{
			fliped[++uvcnt] = false;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		bool fl = lr.Query(i,i);
		if(fl){
			ans += n - ud.Query(1,n);
		}else{
			ans += ud.Query(1,n);
		}
	}
	cout<<ans / 2<<endl;
	for(int i = 1;i < n;i++){
		cout<<fliped[i]<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
