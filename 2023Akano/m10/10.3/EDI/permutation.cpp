#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 5e5 + 1018 + 1108;
int id,n,a[MAXN];
class SegmentTree{
private:
	int val[MAXN * 4];
	void Change(int p,int l,int r,int OBJ,int _val){
		if(l == r){
			val[p] = max(val[p],_val);
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= OBJ)Change(p*2,l,mid,OBJ,_val);
		if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,_val);
		val[p] = max(val[p*2],val[p*2+1]);
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
	inline void Change(int pos,int _val){
		Change(1,1,n,pos,_val);
		return ;
	}
	inline int Query(int l,int r){
		return Query(1,1,n,l,r);
	}
	inline void Clear(){
		memset(val,0,sizeof(val));
		return ;
	}
}tr;
int L2R[MAXN],R2L[MAXN],lis[MAXN],fa[MAXN][22],dep[MAXN];
inline int LCA(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	for(int i = 20;i >= 0;i--){
		if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	}
	if(u == v)return u;
	for(int i = 20;i >= 0;i--){
		if(fa[u][i] != fa[v][i]){
			u = fa[u][i],v = fa[v][i];
		}
	}
	return fa[u][0];
}
bool CmpByA(int x,int y){
	return a[x] > a[y];
}
inline void Solve(int* f){
	vector<int> T[MAXN];
	//T_i_j 表示可以出现在 i 的某一个前缀里,lis为 j 的元素
	//T_i 用于推导 T_x_i ,x 为随便填的一个数,但是T_i是包含了真正意义上的 t_x_i ,因为还要考虑到a(题目中p)的值
	//T_i 显然有 其元素(代表下标)递增，其内部元素为下标的a值递减 的特点，否则其内部就可以转移了
	T[0].push_back(0);
	for(int u = 1;u <= n;u++){
		lis[u] = tr.Query(1,a[u]) + 1;
		tr.Change(a[u],lis[u]);
		T[lis[u]].push_back(u);
		int l = *lower_bound(T[lis[u]-1].begin(),T[lis[u]-1].end(),u,CmpByA),r = T[lis[u]-1].back();
		fa[u][0] = LCA(l,r);
		dep[u] = dep[fa[u][0]] + 1;
//		cerr<<u<<" fa "<<fa[u][0]<<" l "<<l<<" r "<<r<<" dep "<<dep[u]<<endl;
		for(int i = 1;i <= 20;i++){
			fa[u][i] = fa[fa[u][i-1]][i-1];
		}
		f[u] = dep[fa[u][0]];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("permutation/permutation1.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	cin>>id>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	Solve(L2R);
	reverse(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		a[i] = n - a[i] + 1;
	}
	tr.Clear();
	Solve(R2L);
	reverse(R2L+1,R2L+n+1);
	for(int i = 1;i <= n;i++){
		cout<<L2R[i]+R2L[i]<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
