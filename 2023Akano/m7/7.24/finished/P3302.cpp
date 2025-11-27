#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8e4 + 1018 + 1108;
const int MAXM = MAXN * 4;
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
struct Node{
	int ls,rs,val;
};
int maxval;
class PersistableSegmentTree{
	private:
		int roots[MAXN],tot;
		Node node[MAXN * 128];
		inline int L(int p){
			return node[p].ls;
		}
		inline int R(int p){
			return node[p].rs;
		}
		inline void PushUp(int p){
			node[p].val = node[L(p)].val + node[R(p)].val;
			return ;
		}
		int Change(int p,int l,int r,int OBJ,int _val){
			const int no = ++tot;
			node[no] = node[p];
			if(l == r){
				node[no].val += _val;
				return no;
			}
			const int mid = (l + r) >> 1;
			if(mid >= OBJ){
				node[no].ls = Change(node[no].ls,l,mid,OBJ,_val);
			}else{
				node[no].rs = Change(node[no].rs,mid+1,r,OBJ,_val);
			}
			PushUp(no);
			return no;
		}
		int QueryKth(int p1,int p2,int d1,int d2,int l,int r,int k){
			if(l == r)return l;
			const int lval = node[L(p1)].val + node[L(p2)].val - node[L(d1)].val - node[L(d2)].val;
			const int mid = (l + r) >> 1;
			if(lval >= k){
				return QueryKth(L(p1),L(p2),L(d1),L(d2),l,mid,k);
			}else{
				return QueryKth(R(p1),R(p2),R(d1),R(d2),mid+1,r,k-lval);
			}
		}
	public:
		inline void Change(int version,int history,int pos,int val){
			roots[version] = Change(roots[history],1,maxval,pos,val);
			return ;
		}
		inline int QueryKth(int v1,int v2,int dv1,int dv2,int k){
			return QueryKth(roots[v1],roots[v2],roots[dv1],roots[dv2],1,maxval,k);
		}
}pst;
int lastans = 0,testcase,n,m,q,val[MAXN];
vector<int> vec;
inline void ReadIn(){
	cin>>testcase;
	cin>>n>>m>>q;
	for(int i = 1;i <= n;i++){
		cin>>val[i];
		vec.push_back(val[i]);
	}
	for(int i = 1;i <= m;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v),AddEdge(v,u);
	} 
	return ;
}
inline void Discretize(){
	sort(vec.begin(),vec.end());
	auto it = unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for(int i = 1;i <= n;i++){
		val[i] = lower_bound(vec.begin(),vec.end(),val[i]) - vec.begin() + 1;
	}
	maxval = vec.size();
	return ;
}
int fa[MAXN][20],dep[MAXN],sz[MAXN],nowcnt,father[MAXN];//SPACE TO CALC FASTER
int GetFa(int x){
	if(father[x] == x)return father[x];
	return GetFa(father[x]);
}
void PreLCA(int u){
	sz[nowcnt]++;
	father[u] = nowcnt;
	pst.Change(u,fa[u][0],val[u],1);
	for(int i = 1;i <= 18;i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa[u][0])continue;
		dep[v] = dep[u] + 1;
		fa[v][0] = u;
		PreLCA(v);
	}
	return ;
}
inline void PreCalc(){
	for(int i = 1;i <= n;i++){
		if(fa[i][0] == 0){
			nowcnt = i;
			dep[i] = 1;
			PreLCA(i);
		}
	}
	return ;
}
inline int LCA(int x,int y){
	if(dep[x] < dep[y])swap(x,y);//dep_x > dep_y
	for(int i = 18;i >= 0;i--){
		if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	}
	if(x == y)return x;
	for(int i = 18;i >= 0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
inline int Calc(int x,int y,int k){
	int lca = LCA(x,y);
	int falca = fa[lca][0];
	return pst.QueryKth(x,y,lca,falca,k);
}
inline void Merge(int x,int y){
	int orgx = x,orgy = y;
	x = GetFa(x),y = GetFa(y);
	if(sz[x] < sz[y]){//size_x >= size_y
		swap(x,y),swap(orgx,orgy);
	}
	fa[orgy][0] = orgx,dep[orgy] = dep[orgx] + 1;
	AddEdge(orgx,orgy),AddEdge(orgy,orgx);
	nowcnt = x;
	PreLCA(orgy);
	return ;
}
inline void Solve(){
	char opt;
	int x,y,k;
	cin>>opt;
	if(opt == 'Q'){
		cin>>x>>y>>k;
		int nowans = Calc(x^lastans,y^lastans,k^lastans);
		lastans = vec[nowans-1];
		cout<<lastans<<endl;
	}else if(opt == 'L'){
		cin>>x>>y;
		Merge(x^lastans,y^lastans);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	Discretize();
	PreCalc();
	while(q--)Solve();
	return 0;
}
