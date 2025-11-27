#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 2e6 + 1018 + 1108;
const int MOD = 998244353;
struct Edge{
	int nxt,to,val;
}e[MAXN * 2];
int head[MAXN],d[MAXN],cnt;
inline void AddEdge(int from,int to,int val){
	e[++cnt].to = to;
	e[cnt].val = val;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
inline ll KSM(ll a,ll b){
	ll ret = 1;
	while(b){
		if(b & 1)ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
inline ll Div(ll a,ll b){
	return (a * KSM(b,MOD-2)) % MOD;
}
int n,q,orgn;
ll poss[MAXN],disRoot[MAXN];
int dfn[MAXN],dep[MAXN],fa[MAXN],siz[MAXN],org[MAXN],dnt;
class SegmentTree{
private:
	struct Node{
		ll pdis,lazy;//plazy表示区间乘标记
		int isLeaf;//是否是叶子,有的话才计入pdis的影响
		//当一个节点是叶子的时候，它的值为 1,一个节点为叶子那么它的子树的叶子值就会减一,于是小于等于0
		//没必要对isLeaf进行懒标记下传，可以看做标记永久化
	}node[MAXN * 4];
	inline void PushUp(int p){
		node[p].pdis = 0;
		if(node[p*2].isLeaf == 1)node[p].pdis += node[p*2].pdis;
		if(node[p*2+1].isLeaf == 1)node[p].pdis += node[p*2+1].pdis;
		node[p].pdis %= MOD;
		return ;
	}
	inline void PushDown(int p){
		if(node[p].lazy != 1){
			node[p*2].pdis = (node[p*2].pdis * node[p].lazy) % MOD;
			node[p*2].lazy = (node[p*2].lazy * node[p].lazy) % MOD;
			node[p*2+1].pdis = (node[p*2+1].pdis * node[p].lazy) % MOD;
			node[p*2+1].lazy = (node[p*2+1].lazy * node[p].lazy) % MOD;
			node[p].lazy = 1;
		}
		return ;
	}
	void Build(int p,int l,int r){
		node[p].pdis = 0,node[p].lazy = 1;
		node[p].isLeaf = 1;
		if(l == r){
			node[p].pdis = (poss[org[l]] * disRoot[org[l]]) % MOD;
			node[p].lazy = poss[org[l]];
			node[p].isLeaf = (d[org[l]] == 0 && org[l] <= orgn) ? 1 : 0;
			return ;
		}
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		PushUp(p);
		return ;
	}
	void ChangeMul(int p,int l,int r,int OBJL,int OBJR,ll _val){
		if(OBJL <= l && r <= OBJR){
			node[p].pdis = (node[p].pdis * _val) % MOD;
			node[p].lazy = (node[p].lazy * _val) % MOD;
			return ;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)ChangeMul(p*2,l,mid,OBJL,OBJR,_val);
		if(mid < OBJR)ChangeMul(p*2+1,mid+1,r,OBJL,OBJR,_val);
		PushUp(p);
		return ;
	}
	void SetLeaf(int p,int l,int r,int OBJL,int OBJR,ll _val){
		if(OBJL <= l && r <= OBJR){
			node[p].isLeaf += _val;
			return ;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJL)SetLeaf(p*2,l,mid,OBJL,OBJR,_val);
		if(mid < OBJR)SetLeaf(p*2+1,mid+1,r,OBJL,OBJR,_val);
		PushUp(p);
		return ;
	}
	ll Query(int p,int l,int r,int OBJL,int OBJR){
		if(node[p].isLeaf != 1)return 0;
		if(OBJL <= l && r <= OBJR){
			return node[p].pdis;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		ll ret = 0;
		if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR);
		if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR);
		return ret % MOD;
	}
	pll GetPoss(int p,int l,int r,int OBJ){
		if(l == r){
			return make_pair(node[p].pdis,node[p].lazy);//此时的lazy就是它改变后的倍率
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)return GetPoss(p*2,l,mid,OBJ);
		if(mid < OBJ)return GetPoss(p*2+1,mid+1,r,OBJ);
		return make_pair(1018,1108);
	}
	bool CheckLeaf(int p,int l,int r,int OBJ){
		if(node[p].isLeaf != 1)return false;
		if(l == r){
			return node[p].isLeaf == 1;
		}
		PushDown(p);
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)return CheckLeaf(p*2,l,mid,OBJ);
		if(mid < OBJ)return CheckLeaf(p*2+1,mid+1,r,OBJ);
		return false;
	}
	friend class Reference;
	class Reference{
	private:
		friend class SegmentTree;
		SegmentTree* source;
		int l,r;
		Reference() = default;
		Reference(SegmentTree* _source,int _l,int _r){
			source = _source,l = _l,r = _r;
			return ;
		}
	public:
		Reference& operator*=(ll _val){
			source->ChangeMul(1,1,n,l,r,_val);
			return *this;
		}
		Reference& operator+=(ll _val){
			source->SetLeaf(1,1,n,l,r,_val);
			return *this;
		}
		Reference& operator-=(ll _val){
			source->SetLeaf(1,1,n,l,r,-_val);
			return *this;
		}
		operator ll(){
			return source->Query(1,1,n,l,r);
		}
	};
public:
	inline void Build(){
		Build(1,1,n);
		return ;
	}
	inline Reference operator()(int l,int r){
		return Reference(this,l,r);
	}
	inline pll operator()(int pos){
		return GetPoss(1,1,n,pos);
	}
	inline bool CheckLeaf(int pos){
		return CheckLeaf(1,1,n,pos);
	}
}tr;
ll debug_ans;
void dfs(int u){
	dfn[u] = ++dnt,dep[u] = dep[fa[u]] + 1,siz[u] = 1;
	org[dnt] = u;
	int child = 0;
	for(int i = head[u];i;i = e[i].nxt){
		if(e[i].to == fa[u])continue;
		child++;
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u])continue;
		fa[v] = u,poss[v] = Div(poss[u],child),disRoot[v] = (disRoot[u] + e[i].val) % MOD;
		dfs(v);
		siz[u] += siz[v];
	}
	cerr<<u<<" is "<<poss[u]<<" * "<<disRoot[u]<<endl;
	if(d[u] == 0 && u <= orgn)debug_ans = (debug_ans + poss[u] * disRoot[u]) % MOD;
	return ;
}
int opt[MAXN],queryU[MAXN],queryW[MAXN],nowcnt;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("lucky/lucky3.in","r",stdin);
//	freopen("lucky.out","w",stdout);
	cin>>n>>q;
	orgn = nowcnt = n;
	for(int i = 2;i <= n;i++){
		int fa,w;
		cin>>fa>>w;
		d[fa]++;
		AddEdge(fa,i,w);
	}
	for(int i = 1;i <= q;i++){
		cin>>opt[i];
		if(opt[i] == 1){
			cin>>queryU[i]>>queryW[i];
			AddEdge(queryU[i],++n,queryW[i]);
		}else if(opt[i] == 2){
			cin>>queryU[i];
		}else if(opt[i] == 3){
			cin>>queryU[i];
		}else if(opt[i] == 4){
			cin>>queryU[i];
		}
	}
	poss[1] = 1,disRoot[1] = 0;
	dfs(1);
	for(int i = 1;i <= n;i++){
		cout<<i<<" deg "<<d[i]<<" dfn "<<dfn[i]<<endl;
	}
	tr.Build();
	for(int i = 1;i <= q;i++){
//		cerr<<"in  turn "<<i<<endl;
		for(int j = 1;j <= n;j++){
			if(tr.CheckLeaf(j)){
//				cerr<<org[j]<<" is leaf!"<<endl;
			}
		}
		if(opt[i] == 1 || opt[i] == 3){//1和3操作是一样的
			if(opt[i] == 1){
				queryU[i] = ++nowcnt;//但是此时新加入的点其实是nowcnt++而不是原本的queryU
			}
//			cerr<<"turn "<<i<<" get "<<queryU[i]<<endl;
			const int u = queryU[i],father = fa[u];
			tr(dfn[u],dfn[u] + siz[u] - 1) += 1;
			d[father]++;
			if(d[father] == 1){
				tr(dfn[father],dfn[father]) -= 1;
			}else{//剩下的子树的变化,不包括自己!
				tr(dfn[father] + 1,dfn[father]) *= Div(d[father],d[father]-1);
			}
		}else if(opt[i] == 2){
			const int u = queryU[i],father = fa[u];
			tr(dfn[u],dfn[u] + siz[u] - 1) -= 1;
			d[father]--;
			if(d[father] == 0){
				tr(dfn[father],dfn[father]) += 1;
			}else{
				tr(dfn[father] + 1,dfn[father]) *= Div(d[father],d[father]+1);
			}
		}else if(opt[i] == 4){
			const int u = queryU[i];
			ll tot = tr(1,n);
			ll subTree = tr(dfn[u],dfn[u] + siz[u] - 1);
			pll point = tr(dfn[u]);
			ll finalAns = tot - subTree + point.first;
			finalAns = ((finalAns % MOD) + MOD)% MOD;
			finalAns = Div(finalAns,point.second);
			cout<<finalAns<<'\n';
//			cout<<"tot "<<tot<<" subtree "<<subTree<<" get Point value "<<point.first<<" poss "<<point.second<<endl;
//			cout<<"compare debug_ans "<<debug_ans<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}
