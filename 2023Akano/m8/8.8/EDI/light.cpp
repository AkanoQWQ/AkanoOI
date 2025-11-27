#include<bits/stdc++.h>
using namespace std;

namespace Container{
	template<typename T>
	struct SegmentTreeNode{
		T val,lazy;
		int len;
		SegmentTreeNode(){val = lazy = len = 0;}
	};
	template<typename T,int SIZE>
	class SegmentTree{//支持区间加减,查询区间和的线段树 
		private:
			SegmentTreeNode<T> node[(SIZE + 4) * 4];
			int OBJL,OBJR,_val;
			T* arr;
			inline void PushUp(int p){
				node[p].val = node[p*2].val + node[p*2+1].val;
				return ;
			}
			inline void PushDown(int p){
				if(node[p].lazy == 0)return ;
				node[p*2].val += node[p*2].len * node[p].lazy;
				node[p*2+1].val += node[p*2+1].len * node[p].lazy;
				node[p*2].lazy += node[p].lazy,node[p*2+1].lazy += node[p].lazy;
				node[p].lazy = 0;
				return ;
			}
			void Build(int p,int l,int r){
				node[p].len = r - l + 1;
				if(l == r){
					if(arr != nullptr){
						node[p].val = arr[l];
					}
					return ;
				}
				const int mid = (l + r) >> 1;
				Build(p*2,l,mid),Build(p*2+1,mid+1,r); 
				PushUp(p);
				return ;
			}
			void ChangeInner(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					node[p].val += _val * node[p].len;
					node[p].lazy += _val;
					return ;
				}
				const int mid = (l + r) >> 1;
				PushDown(p);
				if(mid >= OBJL)ChangeInner(p*2,l,mid);
				if(mid < OBJR)ChangeInner(p*2+1,mid+1,r);
				PushUp(p);
				return ;
			}
			T Query(int p,int l,int r){
				if(OBJL <= l && r <= OBJR){
					return node[p].val;
				}
				const int mid = (l + r) >> 1;
				T ret = 0;
				PushDown(p);
				if(mid >= OBJL)ret = Query(p*2,l,mid);
				if(mid < OBJR)ret += Query(p*2+1,mid+1,r);
				return ret;
			}
		public:
			inline void Build(){
				Build(1,1,SIZE);
				return ;
			}
			inline void Build(T* _arr){
				arr = _arr;
				Build(1,1,SIZE);
				arr = nullptr;
				return ;
			}
			inline void Change(int l,int r,int inval){
				OBJL = l,OBJR = r,_val = inval;
				ChangeInner(1,1,SIZE);
				return ;
			}
			inline T Query(int l,int r){
				OBJL = l,OBJR = r;
				return Query(1,1,SIZE);
			}
			SegmentTree(){
				Build();
				return ;
			}
			SegmentTree(T* _arr){
				Build(_arr);
				return ;
			}
	};
}
using pii = pair<int,int>;

const int MAXN = 4e5 + 1018 + 1108;
const int MAXM = MAXN * 2;
const int MAX_SIZE = 4e5 + 1018 + 1108;
const int LGN = log2(2e5);
struct Edge{
	int nxt,to;
}e[MAXM * 2];
int headmp[MAXN],headtr[MAXN],cnt = 1;
inline void AddEdge(int from,int to,int head[]){
	e[++cnt].to = to;
	e[cnt].nxt = head[from];
	head[from] = cnt;
	return ;
}
int trans[255],arr[MAXN];
string strs[MAXN];

//LCA部分
namespace LCA{
	int fa[MAXN][22],dep[MAXN];
	const int UP = 20; 
	inline void Calc(int u){
		for(int i = 1;i <= UP;i++){
			fa[u][i] = fa[fa[u][i-1]][i-1];
		}
		return ;
	}
	inline pii GetLCASon(int x,int y){
		if(dep[x] < dep[y])swap(x,y);
		for(int i = UP; i >= 0; i--){
			if(dep[fa[x][i]] >= dep[y]){
				x = fa[x][i];
			}
		}
		if(x == y)return make_pair(x,x);
		for(int i = UP;i >= 0;i--){
			if(fa[x][i] != fa[y][i]){
				x = fa[x][i];
				y = fa[y][i];
			}
		}
		return make_pair(x,y);
	}
	inline int GetLCA(int x,int y){
		pii lcaSon = GetLCASon(x,y);
		if(lcaSon.first == lcaSon.second)return lcaSon.first;//ERROR1   
		return fa[lcaSon.first][0];
	}
}

const int AC_SIZE = MAX_SIZE * LGN; 
//AC自动机部分 
int tr[AC_SIZE][7],fail[AC_SIZE],acVal[AC_SIZE],tot;
//AC自动机内部的线段树和树结构
int treeSize[AC_SIZE],treeVal[AC_SIZE],treeDfn[AC_SIZE],treeDnt;
Container::SegmentTree<int,AC_SIZE> ACtree;
class ACAutomaton{
	private:
		int root;
		unordered_map<int,int> StrnoToAcno;
	public:
		inline void Insert(const string& str,int _val,int no){
			int u = root;//ERROR5
			for(auto ch : str){
				int i = trans[int(ch)];
				if(tr[u][i] == 0){
					tr[u][i] = ++tot;
				}
				u = tr[u][i];
			}
			StrnoToAcno[no] = u;
			acVal[u] += _val;
			return ;
		}
		void treeDFS(int u,int father){
			treeSize[u] = 1;
			treeDfn[u] = ++treeDnt;
			for(int i = headtr[u];i;i = e[i].nxt){
				const int v = e[i].to;
				if(v == father)continue;
				acVal[v] += acVal[u];
				treeDFS(v,u);
				treeSize[u] += treeSize[v];
			}
			treeVal[treeDfn[u]] = acVal[u];
			return ;
		}
		inline void Build(){
			fail[root] = root;
//			cout<<"BUILD "<<root<<endl;
			queue<int> q;
			for(int i = 0;i < 6;i++){
				if(tr[root][i] != 0){
//					cout<<"ADD "<<endl;
					AddEdge(root,tr[root][i],headtr);
					AddEdge(tr[root][i],root,headtr);
					if(root == 1)cout<<root<<" "<<tr[root][i]<<endl;
					fail[tr[root][i]] = root;//ERROR6
					q.push(tr[root][i]);
				}else{
					tr[root][i] = root;//ERROR7
				}
			}
			while(!q.empty()){
				const int u = q.front();
				q.pop();
				for(int i = 0;i < 6;i++){
					if(tr[u][i]){
						fail[tr[u][i]] = (tr[fail[u]][i] == 0) ? root : tr[fail[u]][i];//ERROR8
						AddEdge(u,tr[u][i],headtr);
						AddEdge(tr[u][i],u,headtr);
						if(root == 1)cout<<u<<" "<<tr[u][i]<<endl;
						q.push(tr[u][i]);
					}else{
						tr[u][i] = (tr[fail[u]][i] == 0) ? root : tr[fail[u]][i];
					}
				}
			}
			treeDFS(root,root);
			return ;
		}
		inline void Change(int no,int _val){
			const int acno = StrnoToAcno[no];
			const int dfnno = treeDfn[acno];
			ACtree.Change(dfnno,dfnno + treeSize[acno] - 1,_val);
			return ;
		}
		inline int Query(const string& str){
			int ret = 0,u = root;
			cout<<"QUERY "<<str<<endl;
			for(auto ch : str){
				cout<<"now "<<ch<<" : "<<endl;
				const int i = trans[int(ch)];
				u = tr[u][i];
				const int pos = treeDfn[u];
				cout<<"vis "<<u<<" get "<<pos<<" : ";
				cout<<ACtree.Query(pos,pos)<<endl;
				ret += ACtree.Query(pos,pos);
			}
			cout<<"FIN ret "<<ret<<endl;
			return ret;
		}
		inline void Init(){
			root = ++tot;
			return ;
		}
}aca;
int dir[MAXN];//dir:对字符串编号的映射
class SegmentTree{
	private:
		int SIZE;
		ACAutomaton aca[MAXN * 4];
		void Build(int p,int l,int r){
			aca[p].Init();//ERROR3
			for(int i = l;i <= r;i++){
				const int u = dir[i];
				if(u > 0){
					aca[p].Insert(strs[u],arr[u],u);
				}else{
					aca[p].Insert(strs[-u],-arr[-u],-u);//ERROR2
				}
			}
			aca[p].Build();
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			Build(p*2,l,mid),Build(p*2+1,mid+1,r);//ERROR4
			return ;
		}
		void Change(int p,int l,int r,int OBJ,int no,int _val){
			if(l <= OBJ && OBJ <= r){
				aca[p].Change(no,_val);
			}
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			if(mid >= OBJ)Change(p*2,l,mid,OBJ,no,_val);
			if(mid < OBJ)Change(p*2+1,mid+1,r,OBJ,no,_val);
			return ;
		}
		int Query(int p,int l,int r,int OBJL,int OBJR,const string& str){
			if(OBJL <= l && r <= OBJR){
				int res = aca[p].Query(str);
				cout<<l<<" to "<<r<<" res "<<res<<endl;
				return res;
			}
			const int mid = (l + r) >> 1;
			int ret = 0;
			if(mid >= OBJL)ret += Query(p*2,l,mid,OBJL,OBJR,str);
			if(mid < OBJR)ret += Query(p*2+1,mid+1,r,OBJL,OBJR,str);
			cout<<l<<" to "<<r<<" ret "<<ret<<endl;
			return ret;
		}
	public:
		inline void Build(int _SIZE){
			SIZE = _SIZE;
			Build(1,1,SIZE);
			return ;
		}
		inline void Change(int OBJ,int no,int _val){
			Change(1,1,SIZE,OBJ,no,_val);
			return ;
		}
		inline int Query(const string& str,int l,int r){
			int res = Query(1,1,SIZE,l,r,str);
			cout<<"SegmentTree QUERY "<<str<<" in "<<l<<" to "<<r<<" is "<<res<<endl;
			return res;
		}
}tree;
int n,tp,st[MAXN],ed[MAXN],bracCnt;
inline void ReadIn(){
	cin>>n>>tp;
	for(int i = 1;i <= n;i++)cin>>strs[i];
	for(int i = 1;i <= n;i++)cin>>arr[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin>>u>>v;
		AddEdge(u,v,headmp),AddEdge(v,u,headmp);
	}
	return ;
}
void dfs(int u,int father){
	st[u] = ++bracCnt;
	dir[bracCnt] = u;
	LCA::dep[u] = LCA::dep[father] + 1;
	LCA::fa[u][0] = father;
	LCA::Calc(u);
	for(int i = headmp[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == father)continue;
		dfs(v,u);
	}
	ed[u] = ++bracCnt;
	dir[bracCnt] = -u;
//	cout<<u<<" st "<<st[u]<<" and ed "<<ed[u]<<endl;
	return ;
}
inline void Pre(){
	trans['A'] = 0;
	trans['G'] = 1;
	trans['C'] = 2;
	trans['T'] = 3;
	trans['U'] = 4;
	dfs(1,0);
	tree.Build(bracCnt);
	ACtree.Build(treeVal);
	return ;
}
inline int Query(const string& str,int u,int v){
	cout<<"Query "<<str<<" from "<<u<<" to "<<v<<endl;
	pii lcaSon = LCA::GetLCASon(u,v);
	int lca = LCA::fa[lcaSon.first][0];
	if(lcaSon.first == lcaSon.second){
		if(LCA::dep[u] > LCA::dep[v])swap(u,v);//dep_u < dep_v
		const int upper = lcaSon.first;
		const int lower = u + v - lcaSon.first;
		return tree.Query(str,st[upper],st[lower]);
	}else{
		int ret = 0;
		cout<<"from "<<lca<<" to "<<u<<endl;
		ret += tree.Query(str,st[lca],st[u]);
		int vfa = lcaSon.first;
		if(LCA::GetLCA(v,vfa) != vfa){
			vfa = lcaSon.second;
		}
		cout<<"from "<<vfa<<" to "<<v<<endl;
		ret += tree.Query(str,st[vfa],st[v]);
		cout<<"ACT "<<lca<<" and "<<u<<"    and    "<<vfa<<" and "<<v<<" is "<<ret<<endl; 
		return ret;
	}
	return 10181108;
}
inline void Change(int pos,int _val){
	tree.Change(st[pos],pos,_val);
	tree.Change(ed[pos],pos,_val);
	return ;
}
inline void Solve(){
	int q,lastans = 0;
	cin>>q;
	while(q--){
		int opt,u,v;
		string str;
		cin>>opt>>u>>v;
		u ^= (lastans * tp),v ^= (lastans * tp); 
		if(opt == 1){
			cin>>str;
			str = "AGC";
			lastans = Query(str,u,v);
			cout<<"ans : "<<lastans<<endl;//卡常记得换endl 
			cout<<endl<<endl<<endl;
		}else{
			Change(u,v - arr[u]);
			arr[u] = v;
		}
		return ;//提前ret 
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("light.in","r",stdin);
//	freopen("light.out","w",stdout);
	ReadIn();
	Pre();
	cout<<"END PRE"<<endl;
	Solve();
	return 0;
}
