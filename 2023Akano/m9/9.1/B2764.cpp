#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;
const int INF = 1e9 + 1018 + 1108; 
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
mt19937 rng(time(0));
struct Node{
	int l,r;
	int key,val,siz;
	Node(){}
	Node(int _val){val = _val,key = rng() % INT_MAX,siz = 1;}
};
template<int SIZE>
class Treap{
	private:
		Node node[SIZE];
		int tot,root;
		inline void PushUp(int p){
			node[p].siz = node[node[p].l].siz + node[node[p].r].siz + 1;
			return ;
		}
		void Split(int p,int k,int& x,int& y){
			if(!p){
				x = y = 0;
				return ;
			}
			if(node[p].val <= k){
				x = p;
				Split(node[p].r,k,node[p].r,y);
			}else{
				y = p;
				Split(node[p].l,k,x,node[p].l);
			}
			PushUp(p);
			return ;
		}
		int Merge(int x,int y){//val_x < val_y
			if(!x || !y)return x + y;
			if(node[x].key < node[y].key){
				node[y].l = Merge(x,node[y].l);
				PushUp(y);
				return y;
			}else{
				node[x].r = Merge(node[x].r,y);
				PushUp(x);
				return x;
			}
			return 10181108;
		}
	public:
		inline void Clear(){
			tot = 2,root = 1;
			node[1] = Node(INF),node[2] = Node(-INF);
			node[1].l = 2;
			PushUp(root);
			return ;
		}
		inline void Insert(int val){
			node[++tot] = Node(val);
			int l,r;
			Split(root,val,l,r);
			root = Merge(Merge(l,tot),r);
			return ;
		}
		inline int GetRank(int val){
			int l,r,ret = 0;
			Split(root,val,l,r);
			ret = node[l].siz;
			root = Merge(l,r);
			return ret-1;
		}
		Treap(){Clear();}
};
Treap<MAXN> tr;
bool solved[MAXN];
int n,k,siz[MAXN],mss[MAXN],root,sum;
long long ans;
vector<int> dis;
void GetDis(int u,int fa,int nowdis){
	dis.push_back(nowdis); 
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v] || v == fa)continue;
		GetDis(v,u,nowdis + e[i].val);
	}
	return ;
}
inline void Calc(int u){
	tr.Clear();
	tr.Insert(0);//u×Ô¼º 
//	cerr<<" CALC "<<u<<endl;
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(solved[v])continue;
		dis.clear();
//		cerr<<"search "<<v<<endl;
		GetDis(v,u,e[i].val);
		for(auto d : dis){
//			cerr<<"get "<<k-d<<" is "<<tr.GetRank(k-d)<<endl;
			ans += tr.GetRank(k-d);
		}
		for(auto d : dis){
//			cerr<<"ins "<<d<<endl;
			tr.Insert(d);
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
	cin>>n>>k;
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
	cout<<ans;
	return not(Akano loves pure__Elysia);
}
