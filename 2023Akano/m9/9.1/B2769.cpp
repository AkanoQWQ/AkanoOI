#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 8e4 + 1018 + 1108;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
template<int SIZE>
class SegmentTree{
	private:
		int val[SIZE * 4];
		inline void PushUp(int p){
			val[p] = max(val[p*2],val[p*2+1]);
			return ;
		}
		void Clear(int p,int l,int r){
			if(val[p] == 0)return ;
			val[p] = 0;
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Clear(p*2,l,mid),Clear(p*2+1,mid+1,r);
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int _val){
			if(l == r){
				val[p] = max(val[p],_val);
				return ;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
			PushUp(p);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR){
			if(OBJL <= l && r <= OBJR){
				return val[p];
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret = max(ret,Query(p*2,l,mid,OBJL,OBJR));
			if(mid < OBJR)ret = max(ret,Query(p*2+1,mid+1,r,OBJL,OBJR));
			return ret;
		}
	public:
		inline void Clear(){
			Clear(1,0,SIZE);
			return ;
		}
		inline void Change(int pos,int _val){
			Change(1,0,SIZE,pos,_val);
			return ;
		}
		inline int Query(int l,int r){
			return Query(1,0,SIZE,l,r);
		}
}; 
SegmentTree<MAXN> tr;
bool solved[MAXN],blk[MAXN];
int n,k,m,siz[MAXN],mss[MAXN],root,sum,ans = 0;
vector<pair<int,int> > dis;
void GetDis(int u,int fa,int nowdis,int nowblk){
	nowblk += blk[u];
	dis.push_back(make_pair(nowblk,nowdis)); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v] || v == fa)continue;
		GetDis(v,u,nowdis + e[i].val,nowblk);
	}
	return ;
}
inline void Calc(int u){
	tr.Clear();//tr自带0,即u自己 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dis.clear();
		GetDis(v,u,e[i].val,0);
		const int leftVal = k - blk[u];
		for(auto d : dis){
			if(d.first <= leftVal)ans = max(ans,tr.Query(0,leftVal-d.first) + d.second);
		}
		for(auto d : dis){
			tr.Change(d.first,d.second);
		}
	}
	return ;
}
void GetSize(int u,int fa){
	mss[u] = 0,siz[u] = 1;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa || solved[v])continue;
		GetSize(v,u);
		siz[u] += siz[v];
		mss[u] = max(mss[u],siz[v]);
	}
	mss[u] = max(mss[u],sum - siz[u]);
	if(mss[u] < mss[root])root = u;
	return ;
}
void Solve(int u){
	Calc(u);
	solved[u] = true;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		sum = siz[v],root = 0;
		GetSize(v,u);
		GetSize(root,root);
		Solve(root);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k>>m;
	for(int i = 1;i <= m;i++){
		int x;
		cin>>x;
		blk[x] = true;
	}
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	mss[0] = 1e9;
	sum = n,root = 0;
	GetSize(1,1);
	GetSize(root,root);
	Solve(root);
	cout<<ans<<endl;
	return not(Akano loves pure__Elysia);
}
